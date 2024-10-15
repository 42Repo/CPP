#pragma once

template <typename t> class Array {
  private:
    t           *_array;
    unsigned int _size;

  public:
    Array();
    Array(unsigned int n);
    Array(Array const &src);
    Array &operator=(Array const &rhs);
    ~Array();

    t           &operator[](unsigned int i);
    unsigned int size() const;
    void         print() const;
};

#include "Array.tpp"
