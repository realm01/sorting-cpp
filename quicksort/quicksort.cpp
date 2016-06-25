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

#include <thread>

template <typename T>
void qsort(T* to_sort, const unsigned int& size, const unsigned int& threads) {
  real_qsort(to_sort, 0, size - 1, 1, threads);
}

template <typename T>
void qswap(T* to_sort, const unsigned int& left, const unsigned int& right) {
  T tmp = to_sort[left];
  to_sort[left] = to_sort[right];
  to_sort[right] = tmp;
}

template <typename T>
void real_qsort(T* to_sort, const unsigned int& left, const unsigned int& right, unsigned int layer, const unsigned int& threads) {
  if(left >= right)
    return void();

  unsigned int pivot = right;

  for(int i = right - 1; i > ((int)left) - 1; i--) {
    if(to_sort[i] > to_sort[right])
      qswap<T>(to_sort, i, --pivot);
  }

  bool unclean = false;

  for(unsigned int i = left; i < right; i++) {
    if(to_sort[i] > to_sort[i + 1]) {
      unclean = true;
      break;
    }
  }

  if(!unclean)
    return void();

  qswap<T>(to_sort, right, pivot);

  bool do_threading = false;
  if((2 ^ layer) <= threads)
    do_threading = true;

  if(pivot > 1) {
    if(do_threading) {
      std::thread t_left(real_qsort<T>, to_sort, left, pivot - 1, ++(layer), threads);
      t_left.join();
    }else{
      real_qsort(to_sort, left, pivot - 1, ++(layer), threads);
    }
  }
  if(pivot < right - 1) {
    if(do_threading) {
      std::thread t_right(real_qsort<T>, to_sort, pivot + 1, right, ++(layer), threads);
      t_right.join();
    }else{
      real_qsort(to_sort, pivot + 1, right, ++(layer), threads);
    }
  }
}
