#ifndef _KMP_STRING_MATCHER_H_
#define _KMP_STRING_MATCHER_H_

#include <iostream>
#include <string>
#include <vector>

void getNext(std::vector<int>& next, const std::string& P) {
  const int m = P.size(); 
  for (int k = 0, q = 1; q < m; ++q) {
    while (k > 0 && (P[k + 1] != P[q]))
      k = next[k - 1];

    if (P[k] == P[q])
      ++k; 
    next[q] = k; 
  }
}

void kmpStringMatcher(const std::string& T, const std::string& P) {
  const int n = T.size(); 
  const int m = P.size(); 
  std::vector<int> next(P.size(), 0); 

  getNext(next, P); 
  for (int i = 0; i < next.size(); ++i) 
    std::cout << next[i] << ' '; 
  std::cout << std::endl; 

  for (int i = 0, q = 0; i < n; ++i) {
    while (q > 0 && (P[q + 1] != T[i]))
      q = next[q]; 

    if (P[q + 1] == T[i])
      ++q; 

    if (q == m) {
      std::cout << "Pattern occurs with shift: "
                << (i - m) << std::endl; 
      q = next[q]; 
    }
  }
}

#endif
