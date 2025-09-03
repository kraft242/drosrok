#include "alphabet.h"
#include <gtest/gtest.h>
#include <string>

#define TEST_SUITE AlphabetTest

/* charToIndex */

TEST(TEST_SUITE, CharToIndexValidCharacters)
{
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        ASSERT_EQ(charToIndex(ALPHABET[i]), i);
    }
}

TEST(TEST_SUITE, CharToIndexInvalidCharacters)
{
    const std::wstring invalid = L"øæœßжяюфэαβγδθλπω@#$%&*()[]{}<>|~^`'\"; : "
                                 L"/\\_+=¤©®™§¶†‡•‰′″∑∆∫√∞≈≠≤≥±÷×€£¥¢₩₽₹µ ";
    for (size_t i = 0; i < invalid.size(); i++)
    {
        ASSERT_THROW(charToIndex(invalid[i]), std::invalid_argument);
    }
}

/* indexToChar */

TEST(TEST_SUITE, IndexToCharValidIndexes)
{
    for (size_t i = 0; i < ALPHABET.size(); i++)
    {
        ASSERT_EQ(indexToChar(i), ALPHABET[i]);
    }
}

TEST(TEST_SUITE, IndexToCharInvalidIndexes)
{
    const std::vector<size_t> invalid{ ALPHABET.size(), ALPHABET.size() + 1,
                                       100, 1351356136 };
    for (const size_t &index : invalid)
    {
        ASSERT_THROW(indexToChar(index), std::invalid_argument);
    }
}
