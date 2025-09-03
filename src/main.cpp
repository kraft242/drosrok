#include "alphabet.h"
#include "reader.h"
#include "trie.h"
#include <codecvt>
#include <iostream>
#include <locale>

std::wstring convertToWstring(const char *str)
{
    size_t length = std::mbstowcs(nullptr, str, 0);
    std::wstring wide(length, L'\0');
    std::mbstowcs(&wide[0], str, length);
    return wide;
}

int main(int argc, char *argv[])
{
    std::locale::global(std::locale("sv_SE.utf8")); // Set UTF-8 locale
    std::wcout.imbue(std::locale());

    if (argc != 2)
    {
        std::cout << "Användning: " << argv[0] << "[SÖKTERM]" << std::endl
                  << "Markera okända tecken med understreck (_)." << std::endl;
        return 0;
    }

    const std::wstring query = convertToWstring(argv[1]);

    const std::vector<std::wstring> words = getWords();
    Trie root = getTrie(words);
    const std::vector<std::wstring> matches = getMatches(root, query);
    std::wcout << "Hittade " << matches.size() << " matchningar:" << std::endl;
    for (const std::wstring &match : matches)
    {
        std::wcout << match << std::endl;
    }
    return 0;
}
