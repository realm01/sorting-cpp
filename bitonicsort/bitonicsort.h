#ifndef BITONICSORT_H
#define BITONICSORT_H

const bool ASCENDING = true;
const bool DESCENDING = false;

const bool DIR = ASCENDING;

template<typename T>
void bitonic_sort(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir = DIR);
template<typename T>
void bitonic_merge(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir);
template<typename T>
void bitonic_compare(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir);
template<typename T>
void bitonic_swap(T* to_sort, const unsigned int& left, const unsigned int& right);

#include "bitonicsort.tpp"

#endif
