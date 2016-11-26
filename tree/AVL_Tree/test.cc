#include <iostream>

#include <vector>
using std::vector; 

#include "AvlTree.h"

int main() 
{
  vector<int> coll; 
  for (int i = 1; i < 32; ++i) {
    coll.push_back(i); 
  }

  AvlTree<int> tree; 
  vector<int>::iterator pos; 
  for (pos = coll.begin(); pos != coll.end(); ++pos) {
    tree.insert(*pos); 
  }
  tree.print(); 
  std::cout << "********************************************************" << std::endl; 

  if (tree.contains(8)) {
    tree.remove(8); 
  }
  tree.print(); 
  std::cout << "********************************************************" << std::endl; 

  tree.insert(8); 
  tree.print(); 
  std::cout << "********************************************************" << std::endl; 

  AvlTree<int> tree2(tree);
  tree2.print(); 
  std::cout << "********************************************************" << std::endl; 

  tree2.makeEmpty(); 
  tree2.print(); 
  std::cout << "********************************************************" << std::endl; 

  return 0;
}
