#include "reader.h"
#include "alphabet.h"
#include <algorithm>
#include <fstream>
#include <sstream>

bool notInAlphabet(const wchar_t &c)
{
    return std::find(ALPHABET.begin(), ALPHABET.end(), c) == ALPHABET.end();
}

std::vector<std::wstring> getWords()
{
    std::vector<std::wstring> words;

    std::wifstream file(FILEPATH);
    file.imbue((std::locale(LOCALE)));
    if (!file)
    {
        throw std::runtime_error("Failed to open file: " + FILEPATH);
    }

    std::wstring word;

    while (std::getline(file, word))
    {
        word.erase(
            std::remove_if(word.begin(), word.end(), notInAlphabet), word.end()
        );
        std::transform(word.begin(), word.end(), word.begin(), std::towlower);
        if (!word.empty())
        {
            words.push_back(word);
        }
    }

    return words;
}