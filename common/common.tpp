#include <random>
#include <limits>
#include <iostream>
#include <ctime>

namespace Realmar {
    namespace Common {

        // template <typename T>
        int *GenerateRandomArray(const unsigned int length) {
            int *arr = new int[length];

            std::random_device rd;
            std::default_random_engine gen(rd());

            std::uniform_int_distribution<int> uniform_dist(std::numeric_limits<int>::min(),
                                                            std::numeric_limits<int>::max());

            for (unsigned int i = 0; i < length; i++) {
                arr[i] = uniform_dist(gen);
            }

            return arr;
        }

        void EvaluateTime(const clock_t &startTime) {
            std::cout << "sorting time: " << 1000.0 * (clock() - startTime) / CLOCKS_PER_SEC << std::endl;
        }

        template<typename T>
        void EvaluateArray(const T *arr, const unsigned int length) {
            for (unsigned int i = 0; i < length - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    std::cout << "Array is NOT sorted." << std::endl;
                    return;
                }
            }

            std::cout << "Array is sorted" << std::endl;
        }
    }
}