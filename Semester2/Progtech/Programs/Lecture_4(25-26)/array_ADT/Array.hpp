#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
public:
    Array(unsigned n=0, int b=0);
    Array(const Array &a);
    ~Array();
    Array & operator = (const Array &a);
    T & operator [] (int i);
    const T & operator [] (int i) const;
protected:
    T *data;
    int base;
    unsigned length;
    unsigned loc(int i) const; // may throw out_of_range
};

template <typename T>
Array<T>::Array(unsigned n, int b)
    : base(b), length(n), data(new T[n]) {}

template <typename T>
Array<T>::Array(const Array &a)
    : base(a.base), length(a.length), data(new T[a.length]){
        for (unsigned i=0; i<length; i++)
            data[i] = a.data[i];
    }

template <typename T>
Array<T>::~Array() {
    delete [] data;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array &a) {
    delete [] data;
    length = a.length;
    data = new T[length];
    base = a.base;
    for (unsigned i=0; i<length; i++)
        data[i] = a.data[i];
    return *this;
}

template <typename T>
unsigned Array<T>::loc(int i) const {
    int di = i - base;
    if (di < 0 || di >= length)
        throw std::out_of_range("invalid index");
    return di;
}

template <typename T>
T & Array<T>::operator[] (int i) {
    return data[loc(i)];
}

template <typename T>
const T & Array<T>::operator [] (int i) const {
    return data[loc(i)];
}

#endif