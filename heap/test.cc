#include "buildMaxHeap.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
  std::vector<int> A(a, a+12);

  buildMaxHeap(A); 

  std::move(A.begin(), A.end(), 
            std::ostream_iterator<int>(std::cout, " ")); 
  std::cout << std::endl; 

  return 0; 
}
