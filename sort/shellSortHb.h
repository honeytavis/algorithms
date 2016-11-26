#ifndef _SHELL_SORT_HB_H_
#define _SHELL_SORT_HB_H_

#include <vector>

template<typename Object>
void 
shellSortHb(std::vector<Object>& data) {
  const int N = data.size(); 
  int gap; 
  for (gap = 1; gap <= N/4; gap = gap*2+1); 

  for ( ; gap > 0; gap = (gap-1)/2) {
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
