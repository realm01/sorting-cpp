#include <cmath>
#include <algorithm>
#include <iterator>
#include <deque>

#include <iostream>

template <typename T>
T* msort(T* to_sort, const unsigned int& size) {
  std::deque<T* >* to_sort_p_arr = new std::deque<T* >();
  std::for_each(&to_sort[0], &to_sort[size],
    [to_sort_p_arr](T& item){ to_sort_p_arr->push_back(&item); }
  );

  std::deque<T* >* sorted = real_msort(to_sort_p_arr, size, 0, size - 1);
  std::cout << "sorted" << std::endl;

  T* new_sorted = new T[size];
  for(unsigned int i = 0; i < size; i++) {
    new_sorted[i] = *(sorted->at(i));
  }
  /*unsigned int counter = 0;
  std::for_each(sorted->begin(), sorted->end(),
    [&new_sorted, &counter](T* item){ new_sorted[counter++] = *item; }
  );*/


  return new_sorted;
}

template <typename T>
std::deque<T* >* real_msort(std::deque<T* >* to_sort, const unsigned int& size, const unsigned int& begin, const unsigned int& end) {
  std::deque<T* > *left, *right;
  unsigned int  size_left = size / 2,
                size_right = size - size / 2;

  if(size > 1) {
    left = real_msort(to_sort, size_left, begin, begin + size_left - 1);
    right = real_msort(to_sort, size_right, begin + size_left, end);
  }else{
    std::deque<T* >* single = new std::deque<T* >();
    single->push_back(to_sort->at(begin));
    return single;
  }

  std::deque<T* >* sorted = new std::deque<T* >();
  for(typename std::deque<T* >::iterator i = left->begin(); i < left->end(); i++) {     // left
    for(typename std::deque<T* >::iterator j = right->begin(); j < right->end(); j++) {  // right
      if(**i <= **j) {
        sorted->push_back(*i);
        break;
      }else{
        sorted->push_back(*j);
        right->erase(j);
        j = right->begin();
      }
    }
  }

  for(typename std::deque<T* >::iterator i = right->begin(); i != right->end(); i++)
    sorted->push_back(*i);

  for(typename std::deque<T* >::iterator i = left->begin(); i != left->end(); i++)
    sorted->push_back(*i);

  delete left;
  delete right;

  return sorted;
}
