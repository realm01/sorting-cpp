#include "quicksort.h"
#include "common.h"

int main() {
    const unsigned int length = 1000000;
    int* to_sort = Realmar::Common::GenerateRandomArray(length);
    clock_t start_time = clock();

    Realmar::Sorting::Quick::qsort<int>(to_sort, length, 8);

    Realmar::Common::EvaluateTime(start_time);
    Realmar::Common::EvaluateArray(to_sort, length);

    return 0;
}
