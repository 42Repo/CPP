// test_ex00.cpp
#include "Fixed.h"
#include <gtest/gtest.h>

// Test default constructor
TEST(FixedTest, DefaultConstructor) {
    Fixed a;
    EXPECT_EQ(a.getRawBits(), 0);
}

// Test setRawBits and getRawBits
TEST(FixedTest, SetGetRawBits) {
    Fixed a;
    a.setRawBits(42);
    EXPECT_EQ(a.getRawBits(), 42);
}

// Test copy constructor
TEST(FixedTest, CopyConstructor) {
    Fixed a;
    a.setRawBits(42);
    Fixed b(a);
    EXPECT_EQ(b.getRawBits(), 42);
}

// Test assignment operator
TEST(FixedTest, AssignmentOperator) {
    Fixed a;
    a.setRawBits(42);
    Fixed b;
    b = a;
    EXPECT_EQ(b.getRawBits(), 42);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
