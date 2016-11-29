#include "heap.h"

#include <iostream>
#include <vector>
#include <iterator>

int main()
{
  int coll[] = {0, 50, 18, 14, 16, 15, 13, 12, 11, 10, 17, 9, 8, 7, 4, 5, 6, 3, 2, 1}; 
  std::vector<int> data(coll, coll+20); 

  heapSort(data); 

  std::copy(data.begin(), data.end(), 
            std::ostream_iterator<int>(std::cout, " ")); 
  std::cout << std::endl; 

  return 0; 
}
