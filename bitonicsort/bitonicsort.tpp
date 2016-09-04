#include <iostream>

/*
https://en.wikipedia.org/wiki/Bitonic_sorter

Explanation:
The goal of bitonic sort is to create a bitonic sequence out of a given number of elements
and then merge them thogether so that they are sorted eighter ascending or descending
*/

template<typename T>
void bitonic_sort(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir) {
  const unsigned int size = (right - left) + 1;
  if(size <= 1)
    return;

  bitonic_sort(to_sort, left, (left + size / 2) - 1, ASCENDING);    // left
  bitonic_sort(to_sort, left + size / 2, right, DESCENDING);        // right

  bitonic_merge(to_sort, left, right, dir);
}

template<typename T>
void bitonic_merge(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir) {
  const unsigned int size = (right - left) + 1;
  if(size <= 1)
    return;

  bitonic_compare(to_sort, left, right, dir);
  bitonic_merge(to_sort, left, (left + size / 2) - 1, dir);
  bitonic_merge(to_sort, left + size / 2, right, dir);
}

template<typename T>
void bitonic_compare(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir) {
  const unsigned int size = (right - left) + 1;

  for(unsigned int i = left; i < left + size / 2; i++) {
    if(dir == (to_sort[i] > to_sort[i + size / 2]))
      bitonic_swap(to_sort, i, i + size / 2);
  }
}

template<typename T>
void bitonic_swap(T* to_sort, const unsigned int& left, const unsigned int& right) {
  T tmp = to_sort[left];
  to_sort[left] = to_sort[right];
  to_sort[right] = tmp;
}
