#include <cmath>
#include <algorithm>
#include <iterator>

#include <iostream>

template <typename T>
void msort(T* to_sort, const unsigned int& size) {
  T** to_sort_p_arr = new T*[size];
  for(unsigned int i = 0; i < size; i ++) to_sort_p_arr[i] = &(to_sort[i]);

  T** sorted = real_msort(to_sort_p_arr, size, 0, size - 1);
  std::cout << "sorted" << std::endl;
  T* new_sorted = new T[size];
  for(unsigned int i = 0; i < size; i ++) new_sorted[i] = T(*(sorted[i]));
  std::copy(&new_sorted[0], &new_sorted[size - 1], &to_sort[0]);
}

template <typename T>
T** real_msort(T** to_sort, const unsigned int& size, const unsigned int& begin, const unsigned int& end) {
  T **left, **right;

  std::cout << "new real_msort" << std::endl;

  if(size > 1) {
    left = real_msort(to_sort, size / 2, begin, begin + size / 2 - 1);
    std::cout << "finished left" << std::endl;
    right = real_msort(to_sort, size - size / 2, begin + size / 2, end);
    std::cout << "finished right" << std::endl;
  }else{
    T** single = new T*[1];
    single[0] = to_sort[begin];
    return single;
  }

  for(unsigned int i = 0; i < size / 2; i++) {
    std::cout << "print " << left << " : " << right << " : " << size << " : " << size / 2 <<  std::endl;
    std::cout << *(left[i]) << std::endl;
  }

  for(unsigned int i = 0; i < size - size / 2; i++) {
    std::cout << *(right[i]) << std::endl;
  }

  std::cout << "CURR SIZE: " << size << std::endl;

  T** sorted = new T*[size];
  unsigned int counter = 0;
  for(unsigned int i = 0; i < size / 2; i++) {
    if(left[i] == NULL)
      continue;

    bool did_operations = false;

    for(unsigned int j = 0; j < size - size / 2; j++) {
      if(right[j] == NULL)
        continue;

      did_operations = true;

      if(*(left[i]) <= *(right[j])) {
        std::cout << "left is smaller" << std::endl;
        sorted[counter] = left[i];
        left[i] = NULL;
        counter++;
        break;
      }else{
        std::cout << "right is smaller" << std::endl;
        sorted[counter] = right[i];
        right[i] = NULL;
        counter++;
      }
    }

    if(!did_operations) {
      std::cout << "didnt do any operations" << std::endl;
      sorted[counter] = left[i];
      left[i] = NULL;
      counter++;
    }
  }

  for(unsigned int i = 0; i < size - size / 2; i++) {
    if(right[i] != NULL) {
      sorted[counter] = right[i];
      counter++;
    }
  }

  for(unsigned int i = 0; i < size / 2; i++) {
    if(left[i] != NULL) {
      sorted[counter] = left[i];
      counter++;
    }
  }

  std::cout << "-----" << std::endl;
  for(unsigned int i = 0; i < size; i++) {
    std::cout << *(sorted[i]) << std::endl;
  }

  return sorted;
}
