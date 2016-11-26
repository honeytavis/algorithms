#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <vector>
#include <algorithm>

template<typename Object>
void 
merge(std::vector<Object>& a, std::vector<Object>& b, int p, int q, int r) {
  int i = p, j = q + 1; 
  int k = p; 
  while (i <= q && j <= r) {
    if (a[i] <= a[j])
      b[k++] = a[i++]; 
    else 
      b[k++] = a[j++]; 
  }
  while (i <= q)
    b[k++] = a[i++]; 
  while (j <= r)
    b[k++] = a[j++]; 

  std::move(b.begin()+p, b.begin()+r+1, a.begin()+p); 
}

template<typename Object>
void
mergeSort(std::vector<Object>& a, std::vector<Object>& b, int p, int r) {
  if (p < r) {
    int q = (p + r)/2; 
    mergeSort(a, b, p, q); 
    mergeSort(a, b, q+1, r); 
    merge(a, b, p, q, r); 
  }
}

template<typename Object>
void 
mergeSort(std::vector<Object>& a) {
  std::vector<Object> b(a.size());
  mergeSort(a, b, 0, a.size()-1);
}

#endif
