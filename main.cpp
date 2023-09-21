#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cstdlib>

int main()
{
    std::string tmp = "abcdasdfjdiukaskdjac";
    // Option 2: use const char*
    char *char_ptr = new char(tmp.length() + 1);
    strcpy(char_ptr, tmp.c_str());

    // Huffman algothrism

    // std::cout << "String after one finding: " << tmp << std::endl;
    std::cout << "Done" << std::endl;
}