#ifndef TRIE_H
#define TRIE_H

#include <array>
#include <string>
#include <vector>

#include "alphabet.h"

#define WILDCARD L'_'

class Trie
{
  private:
    static constexpr wchar_t INVALID = L'\0';
    wchar_t m_character;
    std::array<Trie *, ALPHABET_SIZE> m_children;

  public:
    Trie();
    Trie(const wchar_t &character);
    ~Trie();

    void insert(const std::wstring &word);
    wchar_t character() const;
    std::array<Trie *, ALPHABET_SIZE> children() const;
    bool isLeaf() const;
};

Trie getTrie(const std::vector<std::wstring> &words);

std::vector<std::wstring>
getMatches(const Trie &root, const std::wstring &query);

#endif // TRIE_H