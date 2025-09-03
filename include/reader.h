#ifndef READER_H
#define READER_H

#include <string>
#include <vector>

const std::string FILEPATH = "../data/swedish.txt";

const std::string LOCALE = "sv_SE.UTF-8";

std::vector<std::wstring> getWords();

#endif // READER_H