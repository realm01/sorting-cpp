#include <iostream>

template<typename T>
void bitonic_sort(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir) {
  const int id = rand() % 100;
  std::cout << "start id: " << id << std::endl;

  const unsigned int size = (right - left) + 1;
  if(size <= 1) {
    std::cout << "size is 1" << std::endl;
    return;
  }

  std::cout << "left: " << left << " right: " << right << " middle: " << left + size / 2 - 1 << " size: " << size << std::endl;

  bitonic_sort(to_sort, left, (left + size / 2) - 1, ASCENDING);    // left
  bitonic_sort(to_sort, left + size / 2, right, DESCENDING);        // right

  std::cout << "continue id: " << id << std::endl;
  std::cout << "LLLLLLLLLLLLLLLLLLOOOL" << std::endl;
  for(unsigned int i = left; i < right + 1; i++)
    std::cout << to_sort[i] << "|";
  std::cout << std::endl;

  bitonic_merge(to_sort, left, right, dir);
}

template<typename T>
void bitonic_merge(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir) {
  const unsigned int size = (right - left) + 1;
  if(size <= 1)
    return;

  //std::cout << "MERGE:" << left << " : " << right << " : " << left + size / 2 << " : " << size << std::endl;
  std::cout << "MERGE: left: " << left << " right: " << right << std::endl;

  bitonic_compare(to_sort, left, right, dir);
  bitonic_merge(to_sort, left, (left + size / 2) - 1, dir);
  bitonic_merge(to_sort, left + size / 2, right, dir);
}

template<typename T>
void bitonic_compare(T* to_sort, const unsigned int& left, const unsigned int& right, const bool dir) {
  const unsigned int size = (right - left) + 1;

  std::cout << "COMPARE: size: " << size << " right: " << right << " left: " << left << std::endl;

  for(unsigned int i = left; i < left + size / 2; i++) {
    std::cout << i << " : " << i + size / 2 << " comparing stuff: " << to_sort[i] << " : " << to_sort[i + size / 2] << std::endl;
    if(dir == (to_sort[i] > to_sort[i + size / 2]))
      bitonic_swap(to_sort, i, i + size / 2);
  }
}

template<typename T>
void bitonic_swap(T* to_sort, const unsigned int& left, const unsigned int& right) {
  std::cout << "swapping the stuff: " << left << " : " << right << std::endl;
  T tmp = to_sort[left];
  to_sort[left] = to_sort[right];
  to_sort[right] = tmp;

  std::cout << "swaped the stuff" << std::endl;
}
