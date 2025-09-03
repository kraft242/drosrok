#ifndef ALPHABET_H
#define ALPHABET_H

#include <array>
#include <string>

#define ALPHABET_SIZE 29
constexpr std::array<wchar_t, ALPHABET_SIZE> ALPHABET{
    L'a', L'b', L'c', L'd', L'e', L'f', L'g', L'h', L'i', L'j',
    L'k', L'l', L'm', L'n', L'o', L'p', L'q', L'r', L's', L't',
    L'u', L'v', L'w', L'x', L'y', L'z', L'å', L'ä', L'ö'
};

size_t charToIndex(const wchar_t &c);

wchar_t indexToChar(const size_t &index);

#endif // ALPHABET_H