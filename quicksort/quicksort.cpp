/*
* Created by: Anastassios Martakos
*
* Copyright 2016 Anastassios Martakos
*
* This program is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*/

#include <iostream>

// #define DEBUG

using namespace std;

template <typename T>
void qsort(T* to_sort, const unsigned int& size) {
  real_qsort(to_sort, 0, size - 1);
}

template <typename T>
void qswap(T* to_sort, const unsigned int& left, const unsigned int& right) {
  T tmp = to_sort[left];
  to_sort[left] = to_sort[right];
  to_sort[right] = tmp;
}

template <typename T>
void real_qsort(T* to_sort, const unsigned int& left, const unsigned int& right) {
  if(left >= right)
    return void();

  #ifdef DEBUG
    cout << "LEFT : " << left << " RIGHT : " << right << endl;
  #endif

  unsigned int pivot = right;

  for(int i = right - 1; i > ((int)left) - 1; i--) {
    #ifdef DEBUG
      cout << "PIVOT : " << pivot << "(" << to_sort[pivot] << ")" << " i : " << i << "(" << to_sort[i] << ")" << endl;
    #endif
    if(to_sort[i] > to_sort[right]) {
      #ifdef DEBUG
        cout << "SWITCHING" << endl;
      #endif

      qswap<T>(to_sort, i, --pivot);
    }
  }

  bool unclean = false;

  for(int i = left; i < right; i++) {
    if(to_sort[i] > to_sort[i + 1]) {
      unclean = true;
      break;
    }
  }

  if(!unclean)
    return void();

  qswap<T>(to_sort, right, pivot);
  if(pivot > 1)
    real_qsort(to_sort, left, pivot - 1);
  if(pivot < right - 1)
    real_qsort(to_sort, pivot + 1, right);
}
