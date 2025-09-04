#include "match.h"
#include "alphabet.h"
#include <algorithm>

std::vector<std::wstring>
getMatches(const std::vector<std::wstring> &words, const std::wstring &query)
{
    std::vector<std::wstring> matches;

    const auto equal = [&](const std::wstring &word)
    { return ALPHABET::equal(word, query); };

    std::copy_if(
        words.begin(), words.end(), std::back_inserter(matches), equal
    );

    return matches;
}