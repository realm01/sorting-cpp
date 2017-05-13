cmake_minimum_required(VERSION 3.7)
project(sorting_cpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(common)

set(SOURCE_COMMON
        common/common.h)

set(SOURCE_FILES_BITONIC
        bitonicsort/bitonicmain.cpp
        bitonicsort/bitonicsort.h)

set(SOURCE_FILES_BUBBLE
        bubblesort/bubblemain.cpp
        bubblesort/bubblesort.h)

set(SOURCE_FILES_HEAP
        heapsort/heapmain.cpp
        heapsort/heapsort.h)

set(SOURCE_FILES_MERGE
        mergesort/mergemain.cpp
        mergesort/mergesort.h)

set(SOURCE_FILES_QUICK
        quicksort/quickmain.cpp
        quicksort/quicksort.h)

add_executable(sorting_bitonic ${SOURCE_COMMON} ${SOURCE_FILES_BITONIC})
add_executable(sorting_bubble ${SOURCE_COMMON} ${SOURCE_FILES_BUBBLE})
add_executable(sorting_heap ${SOURCE_COMMON} ${SOURCE_FILES_HEAP})
add_executable(sorting_merge ${SOURCE_COMMON} ${SOURCE_FILES_MERGE})
add_executable(sorting_quick ${SOURCE_COMMON} ${SOURCE_FILES_QUICK})