#include "AsciiDecode.h"

namespace AsciiDecode
{
std::string decode(std::string sequence, unsigned int symbolsCount)
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
};  // namespace AsciiDecode
