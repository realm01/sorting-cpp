#include "bitonicsort.h"
#include "common.h"

int main() {
    const unsigned int length = 1048576;
    int* to_sort = Realmar::Common::GenerateRandomArray(length);
    clock_t start_time = clock();

    Realmar::Sorting::Bitonic::bitonic_sort<int>(to_sort, 0, length - 1);

    Realmar::Common::EvaluateTime(start_time);
    Realmar::Common::EvaluateArray(to_sort, length);

    return 0;
}
