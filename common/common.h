#ifndef SORTING_CPP_COMMON_H
#define SORTING_CPP_COMMON_H

#include <ctime>

namespace Realmar {
    namespace Common {
        // template<typename T>
        int* GenerateRandomArray(const unsigned int length);

        void EvaluateTime(const clock_t &startTime);

        template<typename T>
        void EvaluateArray(const T *arr, const unsigned int length);
    }
}

#include "common.tpp"

#endif //SORTING_CPP_COMMON_H
