#include "naiveStringMatcher.h"
#include "kmpStringMatcher.h"

int main()
{
  // naiveStringMatcher("ababcabababaababa", "ababa"); 
  kmpStringMatcher("ababcabababaababa", "ababacd"); 

  return 0; 
}
