#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

#include <vector>
#include <algorithm>

template<typename Object>
void 
selectionSort(std::vector<Object>& data) {
  const int N = data.size(); 
  for (int i = 0, j, min; i < N-1; ++i) {
    for (j = i+1, min= i; j < N; ++j) {
      if (data[j] < data[min]) 
        min = j; 
    }
    std::swap(data[min], data[i]); 
  }
}

#endif
