#include "reader.h"
#include "alphabet.h"
#include <algorithm>
#include <fstream>
#include <sstream>

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
        word = ALPHABET::normalize(word);
        if (!word.empty())
        {
            words.push_back(word);
        }
    }

    return words;
}