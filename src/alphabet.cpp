#include "alphabet.h"
#include <algorithm>
#include <cwctype>
#include <iostream>
#include <ranges>
#include <stdexcept>

namespace ALPHABET
{

std::wstring normalize(const std::wstring &str)
{
    constexpr auto normalizeChar = [](const wchar_t &c)
    { return normalize(c); };
    const auto view = str | std::views::transform(normalizeChar);
    return std::wstring(view.begin(), view.end());
}


bool equal(const std::wstring &lhs, const std::wstring &rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    const auto zipped = std::ranges::views::zip(lhs, rhs);
    constexpr auto eqChar = [](const auto &pair)
    { return equal(std::get<0>(pair), std::get<1>(pair)); };

    return std::all_of(zipped.cbegin(), zipped.cend(), eqChar);
}

std::wstring toLower(const std::wstring &str)
{
    constexpr auto charLower = [](const wchar_t &c) { return towlower(c); };
    const auto view = str | std::views::transform(charLower);
    return std::wstring(view.begin(), view.end());
}

std::wstring toUpper(const std::wstring &str)
{
    constexpr auto charUpper = [](const wchar_t &c) { return towupper(c); };
    const auto view = str | std::views::transform(charUpper);
    return std::wstring(view.begin(), view.end());
}

} // namespace ALPHABET
