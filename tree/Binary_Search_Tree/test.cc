#include <iostream>
#include <vector>
using std::vector; 
#include "BinarySearchTree.h"

void remove_test(BinarySearchTree<int>& tree); 
void insert_test(BinarySearchTree<int>& tree); 
void copy_constructor(const BinarySearchTree<int>& tree); 
void convertToList_test(BinarySearchTree<int>& tree); 
void makeEmpty_test(BinarySearchTree<int>& tree); 

int main() 
{
  int ia[] = {16, 8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 
              9, 11, 14, 13, 15, 24, 20, 18, 17, 19, 
              22, 21, 23, 28, 26, 25, 27, 30, 29, 31}; 
  vector<int> coll{ia, ia+31}; 

  BinarySearchTree<int> tree; 
  vector<int>::iterator pos; 
  for (pos = coll.begin(); pos != coll.end(); ++pos) {
    tree.insert(*pos); 
  }
  tree.print(); 
  std::cout << std::endl; 

  remove_test(tree); 
  insert_test(tree); 
  copy_constructor(tree); 
  // convertToList_test(tree); 
  makeEmpty_test(tree); 
}

void remove_test(BinarySearchTree<int>& tree) {
  if (tree.contains(8)) {
    tree.remove(8); 
  }
  tree.print(); 
  std::cout << std::endl; 
}

void insert_test(BinarySearchTree<int>& tree) {
  tree.insert(8); 
  tree.print(); 
  std::cout << std::endl; 
}

void copy_constructor(const BinarySearchTree<int>& tree) {
  BinarySearchTree<int> copy(tree);
  copy.print(); 
  std::cout << std::endl; 
}

void convertToList_test(BinarySearchTree<int>& tree) {
  BinarySearchNode<int>* list = tree.convertToList(); 
  while (list != nullptr) {
    std::cout << list->_data << ' ';  
    list = list->_right; 
  }
  std::cout << std::endl; 

  BinarySearchNode<int>* tmp;
  while (list != nullptr) {
    tmp = list; 
    list = list->_right; 
    delete tmp; 
  }
}

void makeEmpty_test(BinarySearchTree<int>& tree) {
  tree.makeEmpty(); 
  if (tree.isEmpty())
    std::cout << "This tree is empty!" <<std::endl; 
}
