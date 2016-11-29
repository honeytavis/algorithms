#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
  typedef enum {red, white, blue} color; 
  std::vector<color> A{blue, white, blue, red, blue, red, white, red, white, blue, white, red, blue}; 
  
  const int N = A.size(); 
  for (int i = -1, j = 0, k = N; j < k; ++j) {
    if (A[j] == red)
      std::swap(A[++i], A[j]); 
    if (A[j] == blue)
      std::swap(A[--k], A[j--]); 
  } // A[0...i] = red, A[i+1, j] = white, A[k, N-1] = blue

  std::move(A.begin(), A.end(), 
            std::ostream_iterator<color>(std::cout, " ")); 
  std::cout << std::endl; 

  return 0; 
}
