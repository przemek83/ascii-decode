#include "gtest/gtest.h"

#include <src/AsciiDecode.h>

TEST(AsciiDecode, decodePositive)
{
    EXPECT_EQ(AsciiDecode::decode("24746211151814964359"), "GREAT");
    EXPECT_EQ(AsciiDecode::decode("2244"), "0");
}

TEST(AsciiDecode, decodeNegative)
{
    EXPECT_NE(AsciiDecode::decode("24746211151814964359"), "NOT GREAT");
    EXPECT_NE(AsciiDecode::decode("2244"), "NOT 0");
}
