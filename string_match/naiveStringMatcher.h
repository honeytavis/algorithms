#ifndef _NAIVE_STRING_MATCHER_
#define _NAIVE_STRING_MATCHER_

#include <iostream>
#include <string>

void naiveStringMatcher(const std::string& T, const std::string& P) {
  int n = T.size(); 
  int m = P.size(); 

  for (int i = 0; i <= n-m; ++i) {
    std::string tmp(T, i, m); 
    if (tmp == P) {
      std::cout << "Pattern occurs with shift: " 
                << i << std::endl; 
    }
  }
}

#endif
