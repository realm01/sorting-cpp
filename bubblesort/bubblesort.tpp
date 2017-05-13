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

namespace Realmar {
    namespace Sorting {
        namespace Bubble {
            template<typename T>
            void bsort(T *to_sort, const unsigned int &size) {
                T t0;
                for (int j = size; j > 0; j--) {
                    for (int i = 0; i < j; i++) {
                        if (to_sort[i] > to_sort[i + 1]) {
                            t0 = to_sort[i];
                            to_sort[i] = to_sort[i + 1];
                            to_sort[i + 1] = t0;
                        }
                    }
                }
            }
        }
    }
}
