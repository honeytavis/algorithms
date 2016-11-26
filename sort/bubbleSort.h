#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#include <vector>
#include <algorithm>

template<typename Object>
void 
bubbleSort(std::vector<Object>& data) {
  const int N = data.size(); 
  for (int i = 0, j; i < N-1; ++i) {
    for (j = N-1; j > i; --j) {
      if (data[j] < data[j-1])
        std::swap(data[j], data[j-1]); 
    }
  }
}

#endif
