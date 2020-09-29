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
//   First line - number of inputs.
//   For each input first line contains number of 4 digit sequences.
//   Second line is encoded ascii chars as sequences of 4 digits.
//
// Output
//   Decoded ascii string.
//
// Example
// In:
//   2
//   5
//   24746211151814964359
//   1
//   2244

// Out:
//   GREAT
//   0

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iostream>

static std::string decode(std::string sequence, unsigned int symbolsCount)
{
    std::string decoded;
    for (unsigned int i = 0; i < symbolsCount; ++i)
    {
        int codedLetter(std::stoi(std::string(sequence, 4 * i, 4)));
        int firstNumber{codedLetter / 1000 * 10 + codedLetter % 100 / 10};
        int secondNumber{codedLetter % 1000 / 100 * 10 + codedLetter % 10};
        char asciiCode = firstNumber + secondNumber;
        decoded.append(1, asciiCode);
    }
    return decoded;
}

int main()
{
    unsigned int testCases;
    std::cin >> testCases;
    for (unsigned int i = 0; i < testCases; ++i)
    {
        unsigned int symbolsCount{0};
        std::cin >> symbolsCount;

        std::string sequence;
        std::cin >> sequence;

        std::cout << decode(sequence, symbolsCount) << std::endl;
    }

    return 0;
}
