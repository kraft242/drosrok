#include "alphabet.h"
#include <algorithm>
#include <cwctype>
#include <iostream>
#include <stdexcept>

size_t charToIndex(const wchar_t &c)
{
    const auto it
        = std::find(ALPHABET.begin(), ALPHABET.end(), std::towlower(c));
    if (it == ALPHABET.end())
    {
        throw std::invalid_argument("Invalid character");
    }
    return std::distance(ALPHABET.begin(), it);
}

wchar_t indexToChar(const size_t &index)
{
    if (index >= ALPHABET_SIZE)
    {
        throw std::invalid_argument("Invalid index.");
    }
    return ALPHABET[index];
}
