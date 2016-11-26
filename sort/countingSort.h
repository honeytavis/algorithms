#ifndef _COUNTING_SORT_H_
#define _COUNTING_SORT_H_

#include <vector>
#include <algorithm>

#define MAX 100

template<typename Object>
void 
countingSort(std::vector<Object>& A) {
  const int N = A.size(); 
  std::vector<Object> B(N); 
  std::vector<int> C(MAX, 0); 

  for (int i = 0; (i < N) && (A[i] < MAX); ++i) {
    ++C[A[i]]; 
  }

  for (int i = 1; i < MAX; ++i) {
    C[i] += C[i - 1]; 
  }

  for(int i = N-1; i >= 0; --i) {
    B[C[A[i]] - 1] = A[i]; // !!!
    --C[A[i]]; 
  }

  std::move(B.begin(), B.end(), A.begin()); 
}

#endif
