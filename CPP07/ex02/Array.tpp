#include <iostream>

template <typename t> Array<t>::Array() : _array(NULL), _size(0) {}

template <typename t> Array<t>::Array(unsigned int n) : _size(n) { _array = new t[n]; }

template <typename t> Array<t>::Array(Array const &src) : _array(NULL), _size(0) { *this = src; }

template <typename t> Array<t> &Array<t>::operator=(Array const &rhs) {
    if (this != &rhs) {
        if (_array != NULL)
            delete[] _array;
        _size = rhs.size();
        _array = new t[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = rhs._array[i] ? rhs._array[i] : 0;
    }
    return *this;
}

template <typename t> Array<t>::~Array() {
    if (_array)
        delete[] _array;
}

template <typename t> t &Array<t>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::exception();
    }
    return _array[index];
}

template <typename t> unsigned int Array<t>::size() const { return _size; }

template <typename t> void Array<t>::print() const {
    for (unsigned int i = 0; i < _size; i++)
        std::cout << _array[i] << std::endl;
}
