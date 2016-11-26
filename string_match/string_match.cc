#include <iostream>
using std::cin; 
using std::cout; 
using std::endl; 

#include <string>
using std::string; 

int match(const string& target, const string& pattern) {
  int target_length = target.size(); 
  int pattern_length = pattern.size(); 
  int target_index = 0; 
  int pattern_index = 0;
  while ((target_index < target_length) && (pattern_index < pattern_length)) {
    if (target[target_index] == pattern[pattern_index]) {
      ++target_index; 
      ++pattern_index; 
    } else {
      target_index -= pattern_index;
      ++target_index; 
      pattern_index = 0; 
    }
  }

  if (pattern_index == pattern_length) {
    return target_index - pattern_index;
  } else {
    return -1; 
  }
}

int main()
{
  cout << match("", "") << endl;
  cout << match("ababa", "") << endl;
  cout << match("ababa", "ababa") << endl;
  cout << match("ababcaaababa", "ababa") << endl;

  return 0; 
}
