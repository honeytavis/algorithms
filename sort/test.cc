#include "insertionSort.h"
#include "shellSort.h"
#include "shellSortHb.h"

#include "selectionSort.h"

#include "bubbleSort.h"

#include "mergeSort.h"

#include <iostream>
#include <vector>
#include <iterator>

int main()
{
  int coll[] = {20, 19, 18, 14, 16, 15, 13, 12, 11, 10, 17, 9, 8, 7, 4, 5, 6, 3, 2, 1}; 
  std::vector<int> data(coll, coll+20); 
  // std::vector<int> data;

  // insertionSort(data); 
  // shellSort(data); 
  // shellSortHb(data); 

  // selectionSort(data); 

  // bubbleSort(data); 

  // mergeSort(data); 

  std::copy(data.begin(), data.end(), 
            std::ostream_iterator<int>(std::cout, " ")); 
  std::cout << std::endl; 

  return 0; 
}
