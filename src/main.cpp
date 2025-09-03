#include "alphabet.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::locale::global(std::locale("sv_SE.utf8")); // Set UTF-8 locale
    std::wcout.imbue(std::locale());
    for (const auto &c : ALPHABET)
    {
        std::wcout << c << std::endl;
    }
    return 0;
}
