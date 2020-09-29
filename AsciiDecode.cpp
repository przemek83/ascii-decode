#include "AsciiDecode.h"

namespace AsciiDecode
{
static const unsigned int SEQUANCE_SIZE{4U};
static const unsigned int DECIMAL_BASE{10U};

static char getAsciiCode(unsigned int encodedAsciiAsNumber)
{
    const unsigned int firstNumber{encodedAsciiAsNumber / 1000 * DECIMAL_BASE +
                                   encodedAsciiAsNumber % 100 / DECIMAL_BASE};
    const unsigned int secondNumber{encodedAsciiAsNumber % 1000 / 100 *
                                        DECIMAL_BASE +
                                    encodedAsciiAsNumber % DECIMAL_BASE};
    return static_cast<char>(firstNumber + secondNumber);
}

std::string decode(const std::string& inputSequence)
{
    std::string decoded;
    const uint64_t asciiSymbolsCount{inputSequence.size() / SEQUANCE_SIZE};
    for (uint64_t i = 0; i < asciiSymbolsCount; ++i)
    {
        const std::string encodedAsciiAsString{
            std::string(inputSequence, SEQUANCE_SIZE * i, SEQUANCE_SIZE)};
        const unsigned int encodedAsciiAsNumber{
            static_cast<unsigned int>(std::stoi(encodedAsciiAsString))};
        decoded.push_back(getAsciiCode(encodedAsciiAsNumber));
    }
    return decoded;
}
};  // namespace AsciiDecode
