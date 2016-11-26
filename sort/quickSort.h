#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <vector> 
#include <algorithm>

template<typename Object>
void 
setPivot(std::vector<Object>& A, int p, int r) {
  int q = (p + r)/2; 
  if (A[p] > A[q])
    std::swap(A[p], A[q]);
  if (A[p] > A[r])
    std::swap(A[p], A[r]); 
  if (A[q] < A[r])
    std::swap(A[q], A[r]); 
}

template<typename Object>
int partition(std::vector<Object>& A, int p, int r) {
  int i = p-1; 
  for (int j = p; j < r; ++j) {
    if (A[j] <= A[r]) {
      std::swap(A[++i], A[j]); 
    }
  }
  std::swap(A[++i], A[r]); 
  return i; 
}

template<typename Object>
void quickSort(std::vector<Object>& A, int p, int r) {
  if (p < r) {
    setPivot(A, p, r); 
    int q = partition(A, p, r); 
    quickSort(A, p, q-1); 
    quickSort(A, q+1, r); 
  }
}

template<typename Object>
void 
quickSort(std::vector<Object>& A) {
  quickSort(A, 0, A.size()-1); 
}

#endif
