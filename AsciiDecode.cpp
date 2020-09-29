#include "AsciiDecode.h"

namespace AsciiDecode
{
static const unsigned int SEQUANCE_SIZE{4U};
static const unsigned int DECIMAL_BASE{10U};

static unsigned char getAsciiCode(unsigned int letterAsNumber)
{
    const unsigned int firstNumber{letterAsNumber / 1000 * DECIMAL_BASE +
                                   letterAsNumber % 100 / DECIMAL_BASE};
    const unsigned int secondNumber{letterAsNumber % 1000 / 100 * DECIMAL_BASE +
                                    letterAsNumber % DECIMAL_BASE};
    return firstNumber + secondNumber;
}

std::string decode(const std::string& inputSequence)
{
    std::string decoded;
    const unsigned long symbolsCount{inputSequence.size() / SEQUANCE_SIZE};
    for (unsigned long i = 0; i < symbolsCount; ++i)
    {
        const std::string letterAsString{
            std::string(inputSequence, SEQUANCE_SIZE * i, SEQUANCE_SIZE)};
        const unsigned int letterAsNumber(std::stoi(letterAsString));
        decoded.append(1, getAsciiCode(letterAsNumber));
    }
    return decoded;
}
};  // namespace AsciiDecode
