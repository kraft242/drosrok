#include "trie.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

#define TEST_SUITE TrieTest

TEST(TrieTest, ExactMatch)
{
    Trie trie;
    const std::wstring word = L"cykel";
    trie.insert(word);
    auto matches = getMatches(trie, word);
    ASSERT_EQ(matches.size(), 1);
    ASSERT_EQ(matches[0], word);
}

TEST(TrieTest, WildcardMatch)
{
    Trie trie;
    const std::wstring query = L"m_ta";

    const std::vector<std::wstring> expected
        = { L"mata", L"meta", L"mota", L"muta", L"mäta", L"möta" };

    for (const auto &e : expected)
    {
        trie.insert(e);
    }

    auto actual = getMatches(trie, query);

    ASSERT_EQ(actual, expected);
}

TEST(TrieTest, PrefixMatch)
{
    Trie trie;
    const std::wstring query = L"____tänka";
    const std::vector<std::wstring> expected
        = { L"likatänka", L"misstänka", L"oliktänka" };
    for (const auto &e : expected)
    {
        trie.insert(e);
    }
    auto actual = getMatches(trie, query);

    ASSERT_EQ(actual, expected);
}
