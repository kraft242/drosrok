#include "trie.h"
#include "alphabet.h"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>

Trie::Trie(const wchar_t &character)
    : m_character(character), m_children{}, m_isEnd(false)
{
    m_children.fill(nullptr);
}

Trie::Trie() : Trie(INVALID)
{
}

Trie::~Trie()
{
    for (Trie *child : m_children)
    {
        delete child;
    }
}

void Trie::insert(const std::wstring &word)
{
    Trie *node = this;
    for (size_t i = 0; i < word.size(); ++i)
    {
        wchar_t c = word[i];
        const size_t idx = charToIndex(c);
        if (node->m_children[idx] == nullptr)
        {
            node->m_children[idx] = new Trie(c);
        }
        node = node->m_children[idx];
    }
    node->setEnd();
}

bool Trie::isLeaf() const
{
    return std::none_of(
        m_children.begin(), m_children.end(),
        [](Trie *child) { return child != nullptr; }
    );
}

void Trie::setEnd()
{
    m_isEnd = true;
}

bool Trie::isEnd() const
{
    return m_isEnd;
}

Trie getTrie(const std::vector<std::wstring> &words)
{
    Trie root;
    for (const std::wstring &word : words)
    {
        root.insert(word);
    }
    return root;
}

wchar_t Trie::character() const
{
    return m_character;
}

Children Trie::children() const
{
    return m_children;
}

void search(
    const Trie *node, std::vector<std::wstring> &matches,
    const std::wstring &query, std::wstring &word, const size_t index
)
{
    if (index == query.size())
    {
        if (node->isEnd())
        {
            matches.push_back(word);
        }
        return;
    }

    const wchar_t c = query[index];
    const Children children = node->children();

    if (c == WILDCARD)
    {
        for (size_t i = 0; i < ALPHABET_SIZE; i++)
        {
            if (children[i] != nullptr)
            {
                word.push_back(indexToChar(i));
                search(children[i], matches, query, word, index + 1);
                word.pop_back();
            }
        }
    }
    else
    {
        size_t i = charToIndex(c);
        if (children[i] != nullptr)
        {
            word.push_back(c);
            search(children[i], matches, query, word, index + 1);
            word.pop_back();
        }
    }
}

std::vector<std::wstring>
getMatches(const Trie &root, const std::wstring &query)
{
    std::vector<std::wstring> matches;

    std::wstring word;

    search(&root, matches, query, word, 0);

    return matches;
}
