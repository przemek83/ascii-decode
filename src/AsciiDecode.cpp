#include "AsciiDecode.h"

#include <cstdint>

namespace
{
constexpr unsigned int SEQUANCE_SIZE{4U};
constexpr unsigned int DECIMAL_BASE{10U};

char getAsciiCode(unsigned int encodedAsciiAsNumber)
{
    const unsigned int firstNumber{
        ((encodedAsciiAsNumber / 1000) * DECIMAL_BASE) +
        ((encodedAsciiAsNumber % 100) / DECIMAL_BASE)};
    const unsigned int secondNumber{
        (((encodedAsciiAsNumber % 1000) / 100) * DECIMAL_BASE) +
        (encodedAsciiAsNumber % DECIMAL_BASE)};
    return static_cast<char>(firstNumber + secondNumber);
}
}  // namespace

namespace ascii
{
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
};  // namespace ascii
