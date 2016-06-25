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

#ifndef __QUICKSORT_H
#define __QUICKSORT_H

template <typename T>
void qsort(T* to_sort, const unsigned int& size, const unsigned int& threads);

template <typename T>
void swap(T* to_sort, const unsigned int& left, const unsigned int& right);

template <typename T>
void real_qsort(T* to_sort, const unsigned int& left, const unsigned int& right, unsigned int layer, const unsigned int& threads);

#include "quicksort.cpp"

#endif
