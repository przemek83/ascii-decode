#include <iostream>

#include "AsciiDecode.h"

int main()
{
    std::string sequence;
    while (std::cin >> sequence)
        std::cout << ascii::decode(sequence) << "\n";
    return 0;
}
