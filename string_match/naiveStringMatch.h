#ifndef _NAIVE_STRING_MATCH_
#define _NAIVE_STRING_MATCH_

#include <iostream>
#include <string>

void naiveStringMatch(std::string T, std::string P) {
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
