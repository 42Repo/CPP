#include "Span.h"

int main() {
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        Span             sp = Span(20000);
        std::vector<int> numbers;

        for (int i = 1; i <= 20000; ++i) {
            numbers.push_back(i);
        }

        sp.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    {
        Span sp = Span(20000);

        for (int i = 1; i <= 20000; ++i) {
            sp.addNumber(i);
        }

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    try {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span             sp = Span(5);
        std::vector<int> numbers;

        for (int i = 1; i <= 6; ++i) {
            numbers.push_back(i);
        }

        sp.addNumbers(numbers.begin(), numbers.end());
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span sp = Span(1);
        sp.addNumber(1);
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span sp = Span(0);
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span sp1 = Span(5);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(3);
        Span sp2 = sp1;
        std::cout << "Shortest span (copied): " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span (copied): " << sp2.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span sp1 = Span(5);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(3);
        Span sp2 = Span(sp1);
        sp2 = sp1;
        std::cout << "Shortest span (assigned): " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span (assigned): " << sp2.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span             sp = Span(10);
        std::vector<int> numbers;

        for (int i = 1; i <= 5; ++i) {
            numbers.push_back(i);
        }
        sp.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest span (range): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (range): " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
