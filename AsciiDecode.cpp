#include "AsciiDecode.h"

namespace AsciiDecode
{
static const unsigned int sequanceSize{4U};
static const unsigned int DECIMAL_BASE{10U};

std::string decode(std::string sequence)
{
    std::string decoded;
    const unsigned long symbolsCount{sequence.size() / sequanceSize};
    for (unsigned long i = 0; i < symbolsCount; ++i)
    {
        const int codedLetter(
            std::stoi(std::string(sequence, sequanceSize * i, sequanceSize)));
        const unsigned int firstNumber{codedLetter / 1000 * DECIMAL_BASE +
                                       codedLetter % 100 / DECIMAL_BASE};
        const unsigned int secondNumber{codedLetter % 1000 / 100 *
                                            DECIMAL_BASE +
                                        codedLetter % DECIMAL_BASE};
        const char asciiCode{static_cast<char>(firstNumber + secondNumber)};
        decoded.append(1, asciiCode);
    }
    return decoded;
}
};  // namespace AsciiDecode
