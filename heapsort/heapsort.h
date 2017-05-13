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

#ifndef __HEAPSORT_H
#define __HEAPSORT_H

namespace Realmar {
    namespace Sorting {
        namespace Heap {

            int getParent(const unsigned int &pos);

            template<typename T>
            void hsort(T *to_sort, const unsigned int &size);

            template<typename T>
            void siftDown(T *to_sort, const unsigned int &start, const unsigned int &end);

            int leftChild(const unsigned int &pos);

            template<typename T>
            void heapify(T *to_sort, const unsigned int &size);

            template<typename T>
            void swap(T *to_sort, const unsigned int &a, const unsigned int &b);

        }
    }
}

#include "heapsort.tpp"

#endif
