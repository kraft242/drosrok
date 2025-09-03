#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    std::locale::global(std::locale("sv_SE.utf8")); // Set UTF-8 locale
    std::wcout.imbue(std::locale());
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}