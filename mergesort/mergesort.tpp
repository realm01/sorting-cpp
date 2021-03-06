#include <cmath>
#include <algorithm>
#include <iterator>

#include <iostream>

namespace Realmar {
    namespace Sorting {
        namespace Merge {
            template<typename T>
            void msort(T *to_sort, const unsigned int &size) {
                T **to_sort_p_arr = new T *[size];
                for (unsigned int i = 0; i < size; i++) to_sort_p_arr[i] = &(to_sort[i]);

                T **sorted = real_msort(to_sort_p_arr, size, 0, size - 1);
                T *new_sorted = new T[size];
                for (unsigned int i = 0; i < size; i++) new_sorted[i] = T(*(sorted[i]));
                std::copy(&new_sorted[0], &new_sorted[size], &to_sort[0]);
            }

            template<typename T>
            T **real_msort(T **to_sort, const unsigned int &size, const unsigned int &begin, const unsigned int &end) {
                T **left, **right;

                if (size > 1) {
                    left = real_msort(to_sort, size / 2, begin, begin + size / 2 - 1);
                    right = real_msort(to_sort, size - size / 2, begin + size / 2, end);
                } else {
                    T **single = new T *[1];
                    single[0] = to_sort[begin];
                    return single;
                }

                T **sorted = new T *[size];
                unsigned int counter = 0;
                for (unsigned int i = 0; i < size / 2; i++) {
                    if (left[i] == NULL)
                        continue;

                    for (unsigned int j = 0; j < size - size / 2; j++) {
                        if (right[j] == NULL)
                            continue;

                        if (*(left[i]) <= *(right[j])) {
                            sorted[counter] = left[i];
                            left[i] = NULL;
                            counter++;
                            break;
                        } else {
                            sorted[counter] = right[j];
                            right[j] = NULL;
                            counter++;
                        }
                    }
                }

                for (unsigned int i = 0; i < size - size / 2; i++)
                    if (right[i] != NULL) sorted[counter++] = right[i];

                for (unsigned int i = 0; i < size / 2; i++)
                    if (left[i] != NULL) sorted[counter++] = left[i];

                return sorted;
            }
        }
    }
}
