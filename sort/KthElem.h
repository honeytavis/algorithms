#ifndef _KTH_ELEM_H_
#define _KTH_ELEM_H_

template<typename Object>
Object& KthElem(std::vector<Object>& A, int p, int r, const int& k) {
  std::swap(A[k], A[r]); // setPivot
  // partition
  int i = p-1; 
  for (int j = p; j < r; ++j) { 
    if (A[j] < A[r])
      std::swap(A[++i], A[j]); 
  }
  std::swap(A[++i], A[r]); 
  
  if (i > k)
    return KthElem(A, p, i-1, k); 
  else if (i < k)
    return KthElem(A, i+1, r, k); 
  else 
    return A[k];
}

template<typename Object>
Object& KthElem(std::vector<Object>& A, const int& k) {
  return KthElem(A, 0, A.size()-1, k-1); 
}

#endif
