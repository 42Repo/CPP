#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
  public:
    explicit Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    template <typename Iterator> void addNumbers(Iterator begin, Iterator end) {
        if (std::distance(begin, end) > static_cast<long>(_maxSize - _data.size()))
            throw std::runtime_error("You are trying to add too many numbers");
        _data.insert(_data.end(), begin, end);
    }

    void addNumber(int number);
    int  shortestSpan() const;
    int  longestSpan() const;

  private:
    unsigned int     _maxSize;
    std::vector<int> _data;
};
