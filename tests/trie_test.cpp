#include "reader.h"
#include "trie.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

#define TEST_SUITE TrieTest

const static std::vector<std::wstring> words = getWords();

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

    for (const auto &w : words)
    {
        trie.insert(w);
    }

    auto actual = getMatches(trie, query);

    ASSERT_EQ(actual, expected);
}

TEST(TrieTest, PrefixMatch)
{
    Trie trie;
    const std::wstring query = L"___het";
    const std::vector<std::wstring> expected
        = { L"dumhet", L"dövhet", L"feghet", L"finhet", L"frihet", L"fulhet",
            L"godhet", L"gråhet", L"helhet", L"heshet", L"höghet", L"kokhet",
            L"kåthet", L"lathet", L"lenhet", L"likhet", L"lojhet", L"låghet",
            L"löshet", L"mörhet", L"närhet", L"renhet", L"seghet", L"slöhet",
            L"surhet", L"tomhet", L"trohet", L"täthet", L"vaghet", L"vekhet",
            L"vighet", L"vishet", L"vithet", L"vänhet", L"äkthet" };
    for (const auto &w : words)
    {
        trie.insert(w);
    }
    const auto actual = getMatches(trie, query);

    ASSERT_EQ(actual, expected);
}

TEST(TrieTest, SuffixMatch)
{
    Trie trie;
    const std::wstring query = L"förs____";
    const std::vector<std::wstring> expected
        = { L"församla", L"försatta", L"försatte", L"försedde", L"försegel",
            L"försegla", L"försiggå", L"försinka", L"försitta", L"försjönk",
            L"förskapa", L"förskepp", L"förskinn", L"förskola", L"förskole",
            L"förskona", L"förskott", L"förskämd", L"förskära", L"förskärs",
            L"försköna", L"förslava", L"förslita", L"försluta", L"förslösa",
            L"försmäda", L"försoffa", L"förspann", L"försport", L"förspänd",
            L"förspörs", L"förstena", L"förstone", L"förstora", L"förstuga",
            L"förstygn", L"förstånd", L"förstöra", L"försumma", L"försupen",
            L"försvaga", L"försvann", L"försvara", L"försvära", L"försvärs",
            L"försvåra", L"försynda", L"försäger", L"försäkra", L"försälja",
            L"försäljs", L"försämra", L"försända", L"försänka", L"försätta",
            L"försålda", L"försålde", L"försörja" };
    for (const auto &w : words)
    {
        trie.insert(w);
    }
    const auto actual = getMatches(trie, query);

    ASSERT_EQ(actual, expected);
}
