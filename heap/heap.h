#ifndef _HEAP_H_
#define _HEAP_H_

#include <vector>
#include <algorithm>

template<typename Object>
void 
maxHeapify(std::vector<Object>&A, int i, int N) {
  int l = 2*i + 1; 
  int r = 2*i + 2; 
  int max = i; 
  if ((l < N) && (A[l] > A[i]))
    max = l; 
  if ((r < N) && (A[r] > A[max]))
    max = r; 

  if (max != i) {
    std::swap(A[i], A[max]); 
    maxHeapify(A, max, N); 
  }
}

template<typename Object>
void 
buildMaxHeap(std::vector<Object>& A) {
  const int N = A.size(); 
  for (int i = N/2; i >= 0; --i) 
    maxHeapify(A, i, N); 
}

template<typename Object>
void 
heapSort(std::vector<Object>& A) {
  buildMaxHeap(A); 
  for (int i = A.size()-1; i > 0; --i) {
    std::swap(A[0], A[i]); 
    maxHeapify(A, 0, i); 
  }
}

#endif
