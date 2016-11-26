#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include <vector>

template<typename Object>
void 
insertionSort(std::vector<Object>& data) {
  const int N = data.size(); 
  for (int i = 1, j; i < N; ++i) {
    Object key = data[i]; 
    for (j = i-1; (j >= 0) && (data[j] > key); --j) {
      data[j+1] = data[j]; 
    }
    data[j+1] = key; 
  }
}

#endif
