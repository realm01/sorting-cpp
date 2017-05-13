#include "mergesort.h"
#include "common.h"

int main() {
    const unsigned int length = 100000;
    int* to_sort = Realmar::Common::GenerateRandomArray(length);
    clock_t start_time = clock();

    Realmar::Sorting::Merge::msort<int>(to_sort, length);

    Realmar::Common::EvaluateTime(start_time);
    Realmar::Common::EvaluateArray(to_sort, length);

    return 0;
}
