#include "insertionSort.h"
#include "shellSort.h"
#include "shellSortHb.h"

#include "selectionSort.h"

#include "bubbleSort.h"
#include "quickSort.h"

#include "mergeSort.h"
#include "countingSort.h"
#include "bucketSort.h"

#include <iostream>
#include <vector>
#include <iterator>

int main()
{
  int coll[] = {0, 50, 18, 14, 16, 15, 13, 12, 11, 10, 17, 9, 8, 7, 4, 5, 6, 3, 2, 1}; 
  std::vector<int> data(coll, coll+20); 
  // std::vector<int> data;

  // insertionSort(data); 
  // shellSort(data); 
  // shellSortHb(data); 

  // selectionSort(data); 

  // bubbleSort(data); 
  // quickSort(data); 

  // mergeSort(data); 
  // countingSort(data); 
  // bucketSort(data); 

  std::copy(data.begin(), data.end(), 
            std::ostream_iterator<int>(std::cout, " ")); 
  std::cout << std::endl; 

  return 0; 
}
