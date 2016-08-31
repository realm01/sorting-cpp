#ifndef MERGESORT_H
#define MERGESORT_H

#include <deque>

template <typename T>
T* msort(T* to_sort, const unsigned int& size);
template <typename T>
std::deque<T* >* real_msort(std::deque<T* >* to_sort, const unsigned int& size, const unsigned int& begin, const unsigned int& end);

#include "mergesort.cpp"

#endif
