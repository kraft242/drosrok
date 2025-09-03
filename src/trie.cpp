#include "trie.h"
#include "alphabet.h"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>

Trie::Trie(const wchar_t &character) : m_character(character), m_children{}
{
    m_children.fill(nullptr);
}

Trie::Trie() : m_character(INVALID), m_children{}
{
    m_children.fill(nullptr);
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
}

bool Trie::isLeaf() const
{
    return std::none_of(
        m_children.begin(), m_children.end(),
        [](Trie *child) { return child != nullptr; }
    );
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

std::array<Trie *, ALPHABET_SIZE> Trie::children() const
{
    return m_children;
}

std::vector<std::wstring>
getMatches(const Trie &root, const std::wstring &query)
{
    std::vector<std::wstring> matches;

    using State = std::tuple<const Trie *, const size_t, const std::wstring>;

    std::queue<State> queue;
    queue.push({ &root, size_t(), std::wstring() });

    while (queue.size())
    {
        const auto [node, index, word] = queue.front();
        queue.pop();

        if (index >= query.size() || node->isLeaf())
        {
            if (index == query.size())
            {
                matches.push_back(word);
            }
            continue;
        }

        const auto children = node->children();
        const wchar_t c = query[index];
        if (c == WILDCARD)
        {
            for (size_t i = 0; i < ALPHABET_SIZE; i++)
            {
                const Trie *child = children[i];
                if (child != nullptr)
                {
                    queue.push(
                        std::make_tuple(
                            child, index + 1, word + indexToChar(i)
                        )
                    );
                }
            }
        }
        else
        {
            const Trie *child = children[charToIndex(c)];
            if (child != nullptr)
            {
                queue.push(std::make_tuple(child, index + 1, word + c));
            }
        }
    }

    return matches;
}
