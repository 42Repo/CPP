#include "Fixed.h"

static void testDefaultMain() {
    std::cout << "=== Testing Default Main ===" << std::endl;
    Fixed       a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

static void testConstructors() {
    std::cout << std::endl << "=== Testing Constructors ===" << std::endl;
    Fixed a;                    // Default constructor
    Fixed b(10);                // Int constructor
    Fixed c(42.42f);            // Float constructor
    Fixed d(b);                 // Copy constructor
    Fixed e = Fixed(123.4321f); // Assignment operator

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d (copy of b) = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << std::endl;
}

static void testAssignment() {
    std::cout << std::endl << "=== Testing Assignment Operator ===" << std::endl;
    Fixed a;
    Fixed b(10);
    a = b;
    std::cout << "After assignment, a = " << a << std::endl;
    std::cout << std::endl;
}

static void testArithmeticOperators() {
    std::cout << std::endl << "=== Testing Arithmetic Operators ===" << std::endl;
    Fixed a(5.5f);
    Fixed b(2);
    Fixed c;

    c = a + b;
    std::cout << a << " + " << b << " = " << c << std::endl;

    c = a - b;
    std::cout << a << " - " << b << " = " << c << std::endl;

    c = a * b;
    std::cout << a << " * " << b << " = " << c << std::endl;

    c = a / b;
    std::cout << a << " / " << b << " = " << c << std::endl;

    Fixed zero(0);
    c = a / zero;

    std::cout << std::endl;
}

static void testComparisonOperators() {
    std::cout << std::endl << "=== Testing Comparison Operators ===" << std::endl;
    Fixed a(10);
    Fixed b(20);
    Fixed c(10);

    std::cout << a << " > " << b << " : " << (a > b) << std::endl;
    std::cout << a << " < " << b << " : " << (a < b) << std::endl;
    std::cout << a << " >= " << c << " : " << (a >= c) << std::endl;
    std::cout << a << " <= " << c << " : " << (a <= c) << std::endl;
    std::cout << a << " == " << c << " : " << (a == c) << std::endl;
    std::cout << a << " != " << b << " : " << (a != b) << std::endl;
    std::cout << std::endl;
}

static void testIncrementDecrementOperators() {
    std::cout << std::endl << "=== Testing Increment/Decrement Operators ===" << std::endl;
    Fixed a;

    std::cout << "Initial value: " << a << std::endl;

    std::cout << "++a = " << ++a << std::endl; // Pre-increment
    std::cout << "a++ = " << a++ << std::endl; // Post-increment
    std::cout << "Current value: " << a << std::endl;

    std::cout << "--a = " << --a << std::endl; // Pre-decrement
    std::cout << "a-- = " << a-- << std::endl; // Post-decrement
    std::cout << "Current value: " << a << std::endl;

    std::cout << std::endl;
}

static void testMinMaxFunctions() {
    std::cout << std::endl << "=== Testing min/max Functions ===" << std::endl;
    Fixed       a(1.5f);
    Fixed       b(2.5f);
    const Fixed c(3.5f);
    const Fixed d(4.5f);

    std::cout << "min(" << a << ", " << b << ") = " << Fixed::min(a, b) << std::endl;
    std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << std::endl;

    std::cout << "min(" << c << ", " << d << ") = " << Fixed::min(c, d) << std::endl;
    std::cout << "max(" << c << ", " << d << ") = " << Fixed::max(c, d) << std::endl;

    std::cout << std::endl;
}

static void testMemberFunctions() {
    std::cout << std::endl << "=== Testing Member Functions ===" << std::endl;
    Fixed a(123.456f);

    std::cout << "a = " << a << std::endl;
    std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;

    Fixed b;
    b.setRawBits(a.getRawBits());
    std::cout << "After setting raw bits, b = " << b << std::endl;

    std::cout << "a.toFloat() = " << a.toFloat() << std::endl;
    std::cout << "a.toInt() = " << a.toInt() << std::endl;

    std::cout << std::endl;
}

int main(void) {
    testDefaultMain();
    testConstructors();
    testAssignment();
    testArithmeticOperators();
    testComparisonOperators();
    testIncrementDecrementOperators();
    testMinMaxFunctions();
    testMemberFunctions();

    return 0;
}
