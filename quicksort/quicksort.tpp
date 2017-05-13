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
#include <cmath>

namespace Realmar {
    namespace Sorting {
        namespace Quick {

            template<typename T>
            void qsort(T *to_sort, const unsigned int &size, const unsigned int &threads) {
                real_qsort(to_sort, 0, size - 1, 0, threads);
            }

            template<typename T>
            void qswap(T *to_sort, const unsigned int &left, const unsigned int &right) {
                T tmp = to_sort[left];
                to_sort[left] = to_sort[right];
                to_sort[right] = tmp;
            }

            template<typename T>
            void real_qsort(T *to_sort, const unsigned int &left, const unsigned int &right, unsigned int layer,
                            const unsigned int &threads) {
                if (left >= right)
                    return;

                unsigned int pivot = right;

                for (int i = right - 1; i > ((int) left) - 1; i--) {
                    if (to_sort[i] > to_sort[right])
                        qswap<T>(to_sort, i, --pivot);
                }

                bool unclean = false;

                for (unsigned int i = left; i < right; i++) {
                    if (to_sort[i] > to_sort[i + 1]) {
                        unclean = true;
                        break;
                    }
                }

                if (!unclean)
                    return;

                qswap<T>(to_sort, right, pivot);

                bool do_threading = false;
                if (pow(2, layer) <= threads)
                    do_threading = true;

                std::thread t_left;
                std::thread t_right;

                if (pivot > 1) {
                    if (do_threading) {
                        t_left = std::thread(real_qsort<T>, to_sort, left, pivot - 1, layer + 1, threads);
                    } else {
                        real_qsort(to_sort, left, pivot - 1, ++(layer), threads);
                    }
                }
                if (pivot < right - 1) {
                    if (do_threading) {
                        t_right = std::thread(real_qsort<T>, to_sort, pivot + 1, right, layer + 1, threads);
                    } else {
                        real_qsort(to_sort, pivot + 1, right, ++(layer), threads);
                    }
                }

                if (t_left.joinable())
                    t_left.join();
                if (t_right.joinable())
                    t_right.join();
            }
        }
    }
}