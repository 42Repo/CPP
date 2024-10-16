// test_ex01.cpp
#include "Fixed.h"
#include <gtest/gtest.h>
#include <sstream>

// Test int constructor
TEST(FixedTest, IntConstructor) {
    Fixed a(42);
    EXPECT_EQ(a.toInt(), 42);
    EXPECT_EQ(a.getRawBits(), 42 << 8);
}

// Test float constructor
TEST(FixedTest, FloatConstructor) {
    Fixed a(42.42f);
    EXPECT_FLOAT_EQ(a.toFloat(), 42.421875);
}

// Test toFloat and toInt
TEST(FixedTest, ToFloatToInt) {
    Fixed a(123.456f);
    EXPECT_FLOAT_EQ(a.toFloat(), 123.45703125f);
    EXPECT_EQ(a.toInt(), 123);
}

// Test operator <<
TEST(FixedTest, OutputOperator) {
    Fixed a(42.42f);
    std::ostringstream oss;
    oss << a;
    EXPECT_EQ(oss.str(), "42.4219"); // Adjust precision as needed
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
