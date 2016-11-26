#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

#include <vector>

template<typename Object>
void 
shellSort(std::vector<Object>& data) {
  const int N = data.size(); 
  for (int gap = N/2; gap > 0; gap = gap/2) {
    for (int i, j = gap; j < N; ++j) {
      Object key = data[j]; 
      for (i = j-gap; (i >= 0) && (key < data[i]); i -= gap) {
        data[i + gap] = data[i]; 
      }
      data[i + gap] = key;
    }
  }
}

#endif
