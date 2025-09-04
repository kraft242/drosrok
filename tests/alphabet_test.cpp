#include "alphabet.h"
#include <gtest/gtest.h>
#include <string>

#define TEST_SUITE AlphabetTest

TEST(TEST_SUITE, NormalizeChars)
{
    for (size_t i = 0; i < ALPHABET::SIZE; i++)
    {
        const wchar_t upper = ALPHABET::UPPER[i];
        const wchar_t lower = ALPHABET::LOWER[i];

        const wchar_t uNormal = ALPHABET::normalize(upper);
        const wchar_t lNormal = ALPHABET::normalize(lower);

        const wchar_t normal = ALPHABET::REPLACEMENT[i];

        ASSERT_EQ(uNormal, lNormal);
        ASSERT_EQ(uNormal, normal);
        ASSERT_EQ(lNormal, normal);
    }
}

TEST(TEST_SUITE, NormalizeString)
{
    const std::wstring s = L"paNnKakA";

    const std::wstring expected = L"pannkaka";
    const std::wstring actual = ALPHABET::normalize(s);

    ASSERT_EQ(expected, actual);
}
