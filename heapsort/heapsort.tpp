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
#include <math.h>

namespace Realmar {
    namespace Sorting {
        namespace Heap {

            int getParent(const unsigned int &pos) {
                return floor((pos - 1) / 2);
            }

            int leftChild(const unsigned int &pos) {
                return (2 * pos) + 1;
            }

            template<typename T>
            void hswap(T *to_sort, const unsigned int &a, const unsigned int &b) {
                T tmp = to_sort[a];

                to_sort[a] = to_sort[b];
                to_sort[b] = tmp;
            }

            template<typename T>
            void heapify(T *to_sort, const unsigned int &size) {
                for (int parent = getParent(size - 1); parent >= 0; parent--) {
                    siftDown<T>(to_sort, parent, size - 1);
                }
            }

            template<typename T>
            void siftDown(T *to_sort, const unsigned int &start, const unsigned int &end) {
                unsigned int left_child, i = start;

                while (i <= end) {
                    left_child = leftChild(i);

                    if (left_child + 1 > end)
                        break;

                    if (to_sort[left_child + 1] > to_sort[i] && to_sort[left_child] < to_sort[left_child + 1]) {
                        hswap<T>(to_sort, i, left_child + 1);
                        i = left_child + 1;
                    } else if (to_sort[left_child] > to_sort[i]) {
                        hswap<T>(to_sort, i, left_child);
                        i = left_child;
                    } else {
                        break;
                    }
                }
            }

            template<typename T>
            void hsort(T *to_sort, const unsigned int &size) {
                heapify<T>(to_sort, size);

                for (int i = size - 1; i >= 2; i--) {
                    hswap<T>(to_sort, 0, i);
                    siftDown<T>(to_sort, 0, i - 1);
                }

                if (to_sort[0] > to_sort[1])
                    hswap<T>(to_sort, 0, 1);
            }
        }
    }
}
