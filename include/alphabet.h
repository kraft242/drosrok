#ifndef ALPHABET_H
#define ALPHABET_H

#include <array>
#include <string>

#define ALPHABET_SIZE 38
constexpr std::array<wchar_t, ALPHABET_SIZE> ALPHABET{
    L'-', L'a', L'b', L'c', L'd', L'e', L'f', L'g', L'h', L'i',
    L'j', L'k', L'l', L'm', L'n', L'o', L'p', L'q', L'r', L's',
    L't', L'u', L'v', L'w', L'x', L'y', L'z', L'à', L'ä', L'å',
    L'ç', L'è', L'é', L'ê', L'ë', L'ñ', L'ö', L'ü'
};

/**
 * Returns the index of c in ALPHABET.
 * @throws std::invalid_argument if c is not in ALPHABET.
 */
size_t charToIndex(const wchar_t &c);

/**
 * Returns the wchar_t at index in ALPHABET.
 * @throws std::invalid_argument if index is larger than ALPHABET.
 */
wchar_t indexToChar(const size_t &index);

#endif // ALPHABET_H