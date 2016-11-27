#ifndef _BUILD_MAX_HEAP_H_
#define _BUILD_MAX_HEAP_H_

#include "maxHeapify.h"

template<typename Object>
void 
buildMaxHeap(std::vector<Object>& A) {
  for (int i = A.size()/2; i >= 0; --i) 
    maxHeapify(A, i); 
}

#endif
