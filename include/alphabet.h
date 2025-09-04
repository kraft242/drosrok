#ifndef ALPHABET_H
#define ALPHABET_H

#include <algorithm>
#include <array>
#include <ranges>
#include <string>
#include <cwctype>

namespace ALPHABET
{

constexpr size_t SIZE = 30;
constexpr size_t REPLACEMENT_SIZE = 30;
constexpr wchar_t WILDCARD = L'_';

constexpr std::array<wchar_t, SIZE> ALPHABET{
    L'-', L'a', L'b', L'c', L'd', L'e', L'f', L'g', L'h', L'i',
    L'j', L'k', L'l', L'm', L'n', L'o', L'p', L'q', L'r', L's',
    L't', L'u', L'v', L'w', L'x', L'y', L'z', L'å', L'ä', L'ö'
};

constexpr std::array<wchar_t, REPLACEMENT_SIZE> UPPER{
    L'À', L'Á', L'Â', L'Ã', L'Æ', L'Ç', L'È', L'É', L'Ê', L'Ë',
    L'Ì', L'Í', L'Î', L'Ï', L'Ð', L'Ñ', L'Ò', L'Ó', L'Ô', L'Õ',
    L'×', L'Ø', L'Ù', L'Ú', L'Û', L'Ü', L'Ý', L'Þ', L'ß'
};

constexpr std::array<wchar_t, REPLACEMENT_SIZE> LOWER{
    L'à', L'á', L'â', L'ã', L'æ', L'ç', L'è', L'é', L'ê', L'ë',
    L'ì', L'í', L'î', L'ï', L'ð', L'ñ', L'ò', L'ó', L'ô', L'õ',
    L'÷', L'ø', L'ù', L'ú', L'û', L'ü', L'ý', L'þ', L'ÿ'
};

constexpr std::array<wchar_t, REPLACEMENT_SIZE> REPLACEMENT{
    L'a', L'a', L'a', L'a', L'ä', L'c', L'e', L'e', L'e', L'e',
    L'i', L'i', L'i', L'i', L'd', L'n', L'o', L'o', L'o', L'o',
    L'/', L'ö', L'u', L'u', L'u', L'u', L'y', L'p', L'y'
};

std::wstring normalize(const std::wstring &str);
inline constexpr wchar_t normalize(const wchar_t &c)
{
    const auto upper = std::find(UPPER.cbegin(), UPPER.cend(), c);
    if (upper != UPPER.cend())
    {
        return REPLACEMENT[std::distance(UPPER.cbegin(), upper)];
    }

    const auto lower = std::find(LOWER.cbegin(), LOWER.cend(), c);
    if (lower != LOWER.cend())
    {
        return REPLACEMENT[std::distance(LOWER.cbegin(), lower)];
    }

    return std::towlower(c);
}
inline constexpr bool equal(const wchar_t &lhs, const wchar_t &rhs)
{
    return lhs == WILDCARD || rhs == WILDCARD || lhs == rhs;
}

bool equal(const std::wstring &lhs, const std::wstring &rhs);
std::wstring toLower(const std::wstring &str);
std::wstring toUpper(const std::wstring &str);

} // namespace ALPHABET

#endif // ALPHABET_H