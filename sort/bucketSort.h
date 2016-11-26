#ifndef _BUCKET_SORT_H_
#define _BUCKET_SORT_H_

#include <vector>
#include <algorithm>

#define MAX 100

template<typename Object>
void 
bucketSort(std::vector<Object>& A) {
  const int N = A.size(); 
  std::vector<int> C(MAX, 0); 
  
  for (int i = 0; (i < N) && (A[i] < MAX); ++i) {
    ++C[A[i]];
  }
  
  for (int i = 0, j = 0, count = 0; j < MAX; ++j) {
    count = C[j]; 
    while (count--) {
      A[i++] = j; 
    }
  }
}

#endif
