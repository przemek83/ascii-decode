//  Ascii decode
//   Convert string of digits into ascii string with following rules:
//   - Each 4 consecutive digits is encoded 1 ascii char.
//   - Digit 1 and 3 need to be concatenated to get first number.
//   - Digit 2 and 4 need to be concatenated to get second number.
//   - Sum of first and second number is an ascii code.
//
//   Decoding example:
//   input in form of 24746211151814964359 is split into 2474 6211
//   1518 1496 4359. For each 4 digits group we create first and second number:
//   2474 : 27 and 44 (sum 71)
//   6211 : 61 and 21 (sum 82)
//   1518 : 11 and 58 (sum 69)
//   1496 : 19 and 46 (sum 65)
//   4359 : 45 and 39 (sum 84)
//   ASCII codes (sums) will give encoded string GREAT (71 = G, 82 = R, ...).

// Input:
//   Per line encoded ascii chars as sequences of 4 digits.
//
// Output
//   Decoded ascii string.
//
// Example
// In:
//   24746211151814964359
//   2244

// Out:
//   GREAT
//   0

#include <iostream>

#include "AsciiDecode.h"

int main()
{
    std::string sequence;
    while (std::cin >> sequence)
        std::cout << AsciiDecode::decode(sequence) << std::endl;
    return 0;
}
