#ifndef _MAX_HEAPIFY_H__
#define _MAX_HEAPIFY_H__

#include <vector>
#include <algorithm>

template<typename Object>
void 
maxHeapify(std::vector<Object>&A, int i) {
  int l = 2*i + 1; 
  int r = 2*i + 2; 
  int max = i; 

  if ((l < A.size()) && (A[l] > A[i]))
    max = l; 
  if ((r < A.size()) && (A[r] > A[max]))
    max = r; 
  if (max != i) {
    std::swap(A[i], A[max]); 
    maxHeapify(A, max); 
  }
}

#endif
