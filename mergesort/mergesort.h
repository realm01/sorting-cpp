#ifndef MERGESORT_H
#define MERGESORT_H

namespace Realmar {
    namespace Sorting {
        namespace Merge {

            template<typename T>
            void msort(T *to_sort, const unsigned int &size);

            template<typename T>
            T **real_msort(T **to_sort, const unsigned int &size, const unsigned int &begin, const unsigned int &end);

        }
    }
}

#include "mergesort.tpp"

#endif
