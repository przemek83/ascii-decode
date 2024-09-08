#include <iostream>

#include "AsciiDecode.h"

int main()
{
    std::string sequence;
    while (std::cin >> sequence)
        std::cout << AsciiDecode::decode(sequence) << std::endl;
    return 0;
}
