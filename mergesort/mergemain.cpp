/*
* Created by: Anastassios Martakos
*
* Copyright 2016 Anastassios Martakos
*
* This program is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>

// #define PRINT_STUFF

#include "mergesort.h"

using namespace std;

int main() {
  const unsigned int count = 10000;

  float* to_sort = new float[count];

  #ifdef PRINT_STUFF
  cout << "SIZE: " << count << endl;
  #endif

  srand((unsigned)time(NULL));


  for(unsigned int i = 0; i < count; i++)
    to_sort[i] = rand();

  for(unsigned int i = 0; i < count; i++)
    to_sort[i] = rand() % 21;

  #ifdef PRINT_STUFF
  for(unsigned int i = 0; i < count; i++)
    cout << to_sort[i] << endl;

  cout << "=========" << endl;
  #endif

  clock_t t0 = clock();
  float* sorted_arr = msort<float>(to_sort, count);
  clock_t t1 = clock();

  #ifdef PRINT_STUFF
  cout << "|";
  for(unsigned int i = 0; i < count; i++)
    cout << sorted_arr[i] << "|";

  cout << endl;

  cout << "CHECKING ARRAY ..." << endl;
  #endif

  bool integrity = true;

  for(unsigned int i = 0; i < count - 1; i++) {
    if(sorted_arr[i] > sorted_arr[i + 1])
      integrity = false;
  }

  if(integrity)
    cout << "sorted_arr is OK" << endl;
  else
    cout << "array sorted_arr is NOT ordered" << endl;

  cout << "MERGESORT TIME: " << 1000.0 * (t1 - t0) / CLOCKS_PER_SEC << endl;

  return 0;
}
