#include "Span.h"
#include <algorithm>
#include <limits>

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_data.size() > _maxSize)
        throw std::runtime_error("You are trying to add too many numbers");
    _data.push_back(number);
}

int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("There are not enough numbers to calculate a span");

    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        int span = sorted[i + 1] - sorted[i];
        shortest = std::min(shortest, span);
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("There are not enough numbers to calculate a span");

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}
