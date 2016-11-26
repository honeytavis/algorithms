#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <vector> 

template<typename Object>
const Object& median3(std::vector<Object>& A, int p, int r) {
  int q = (p + r)/2; 
  if (A[p] < A[r])
    std::swap(A[p], A[r]); 
}

template<typename Object>
void quickSort(std::vector<Object>& A, int p, int r) {
  if (p < r) {
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
