#include "AsciiDecode.h"

namespace AsciiDecode
{
static const unsigned int SEQUANCE_SIZE{4U};
static const unsigned int DECIMAL_BASE{10U};

static unsigned char getAsciiCode(unsigned int codedLetter)
{
    const unsigned int firstNumber{codedLetter / 1000 * DECIMAL_BASE +
                                   codedLetter % 100 / DECIMAL_BASE};
    const unsigned int secondNumber{codedLetter % 1000 / 100 * DECIMAL_BASE +
                                    codedLetter % DECIMAL_BASE};
    return firstNumber + secondNumber;
}

std::string decode(const std::string& input)
{
    std::string decoded;
    const unsigned long symbolsCount{input.size() / SEQUANCE_SIZE};
    for (unsigned long i = 0; i < symbolsCount; ++i)
    {
        const unsigned int codedLetter(
            std::stoi(std::string(input, SEQUANCE_SIZE * i, SEQUANCE_SIZE)));
        decoded.append(1, getAsciiCode(codedLetter));
    }
    return decoded;
}
};  // namespace AsciiDecode
