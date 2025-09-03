#include "alphabet.h"
#include <gtest/gtest.h>
#include <string>

#define TEST_SUITE AlphabetTest

/* charToIndex */

TEST(TEST_SUITE, CharToIndexValidCharacters)
{
    const std::wstring alphabet = L"abcdefghijklmnopqrstuvwxyzåäö";
    for (size_t i = 0; i < alphabet.size(); i++)
    {
        ASSERT_EQ(charToIndex(alphabet[i]), i);
    }
}

TEST(TEST_SUITE, CharToIndexInvalidCharacters)
{
    const std::wstring invalid = L"éüñçøæœßжяюфэαβγδθλπω@#$%&*()[]{}<>|~^`'\";"
                                 L":/\\_+=¤©®™§¶†‡•‰′″∑∆∫√∞≈≠≤≥±÷×€£¥¢₩₽₹µ";
    for (size_t i = 0; i < invalid.size(); i++)
    {
        ASSERT_THROW(charToIndex(invalid[i]), std::invalid_argument);
    }
}

/* indexToChar */

TEST(TEST_SUITE, IndexToCharValidIndexes)
{
    const std::wstring alphabet = L"abcdefghijklmnopqrstuvwxyzåäö";
    for (size_t i = 0; i < alphabet.size(); i++)
    {
        ASSERT_EQ(indexToChar(i), alphabet[i]);
    }
}

TEST(TEST_SUITE, IndexToCharInvalidIndexes)
{
    const std::vector<size_t> invalid{ 29, 30, 100, 1351356136 };
    for (const size_t &index : invalid)
    {
        ASSERT_THROW(indexToChar(index), std::invalid_argument);
    }
}

int main(int argc, char **argv)
{
    std::locale::global(std::locale("sv_SE.utf8")); // Set UTF-8 locale
    std::wcout.imbue(std::locale());
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
