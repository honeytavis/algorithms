#ifndef _AVL_TREE_
#define _AVL_TREE_

#include <algorithm>
#include <iostream>

// class AvlTree {
// public: 
//   AvlTree(); 
//   AvlTree(const AvlTree& rhs); 
//   AvlTree(const AvlTree&& rhs); 
//   ~AvlTree(); 
// 
//   AvlTree& operator= (const AvlTree& rhs); 
//
//   void insert(const T& x); 
//   void insert(const T&& x); 
//
//   void remove(const T& x); 
// 
//   const T& findMin() const; 
//   const T& findMax() const; 
// 
//   bool contains(const T& x) const; 
//   bool isEmpty() const; 
//   void print() const; 
// 
//   void makeEmpty(); 
// 
// private: 
//   AvlNode* _root; 
// }

template<typename T> 
bool Less(const T& x, T& y) {
  return x < y; 
}

template<typename T> 
bool Less(T& x, const T& y) {
  return x < y; 
}

template<typename T>
class AvlTree {
public: 
  AvlTree()
  : _root{nullptr}
  {}

  AvlTree(const AvlTree& rhs)
  : _root{nullptr}
  {
    _root = clone(rhs._root); 
  }

  AvlTree(AvlTree&& rhs) 
  : _root{rhs._root}
  {
    rhs._root = nullptr; 
  }

  ~AvlTree() {
    makeEmpty(); 
  }

  AvlTree& operator= (const AvlTree& rhs) {
    AvlTree copy = rhs; // AvlTree(const AvlTree& rhs); 
    std::swap(*this, copy); 
    return *this; 
  }

  AvlTree& operator= (AvlTree& rhs) {
    AvlTree copy = rhs; // AvlTree(const AvlTree& rhs); 
    std::swap(*this, copy); 
    return *this; 
  }

  void insert(const T& x) {
    insert(x, _root); 
  }

  void insert(const T&& x) {
    insert(std::move(x), _root); // !!!!!
  }

  void remove(const T& x) {
    remove(x, _root); 
  }

  const T& findMin() const {
    if (!isEmpty()) {
      return findMin(_root)->_data; 
    }
  }

  const T& findMax() const {
    if (!isEmpty()) {
      return findMax(_root)->_data; 
    }
  }

  bool contains(const T& x) const {
    return contains(x, _root); 
  }

  bool isEmpty() const {
    return _root == nullptr; 
  }

  void print() const {
    if (!isEmpty()) {
      print(_root, 0, 5, '.'); 
      //print(_root); 
    }
  }

  void makeEmpty() {
    makeEmpty(_root); 
  }

private: 
  class AvlNode {
  public: 
    AvlNode(const T& data, AvlNode* left, AvlNode* right, int height = 0)
    : _data{data}
    , _left{left}
    , _right{right}
    {}

    AvlNode(const T&& data, AvlNode* left, AvlNode* right, int height = 0)
    : _data{data}
    , _left{left}
    , _right{right}
    {}

  public: 
    T _data; 
    AvlNode* _left; 
    AvlNode* _right; 
    int _height; 
  }; // AvlNode

  AvlNode* _root; 

private: 
  int height(AvlNode* t) {
    return t == nullptr ? -1 : t->_height; 
  }

  int max(int lhs, int rhs) const {
    return lhs > rhs ? lhs : rhs; 
  }
  
  void leftLeftRotate(AvlNode*& root) {
    AvlNode* leftChild = root->_left; 
    root->_left = leftChild->_right; 
    leftChild->_right = root; 

    root->_height = max(height(root->_left), height(root->_right)) + 1; 
    leftChild->_height = max(height(leftChild->_left), root->_height) + 1; 
    
    root = leftChild; 
  }

  void rightRightRotate(AvlNode*& root) {
    AvlNode* rightChild = root->_right; 
    root->_right = rightChild->_left; 
    rightChild->_left = root; 

    root->_height = max(height(root->_left), height(root->_right)) + 1; 
    rightChild->_height = max(root->_height, height(rightChild->_right)) + 1;

    root = rightChild; 
  }

  void leftRightRotate(AvlNode*& grandpa) {
    AvlNode* parent = grandpa->_left; 
    AvlNode* child = grandpa->_right; 

    parent->_right = child->_left; 
    child->_left = parent; 
    grandpa->_left = child->_right; 
    child->_right = grandpa; 

    parent->_height = max(height(parent->_left), height(parent->_right)) + 1; 
    grandpa->_height = max(height(grandpa->_left), height(grandpa->_right)) + 1; 
    child->_height = max(parent->_height, grandpa->_height) + 1; 

    grandpa = child; 
  }

  void rightLeftRotate(AvlNode*& grandpa) {
    AvlNode* parent = grandpa->_right; 
    AvlNode* child = parent->_left; 

    parent->_left = child->_right; 
    child->_right = parent; 
    grandpa->_right = child->_left; 
    child->_left = grandpa; 

    grandpa->_height = max(height(grandpa->_left), height(grandpa->_right)) + 1; 
    parent->_height = max(height(parent->_left), height(parent->_right)) + 1; 
    child->_height = max(grandpa->_height, parent->_height) + 1; 

    grandpa = child; 
  }

  static const int ALLOWED_IMBALANCE = 1;  
  void balance(AvlNode*& t) {
    if (t == nullptr) {
      return ; 
    } 
    if (height(t->_left) - height(t->_right) > ALLOWED_IMBALANCE) {
      if (height(t->_left->_left) >= height(t->_left->_right)) {
        leftLeftRotate(t); 
      } else {
        leftRightRotate(t); 
      }
    } else if (height(t->_right) - height(t->_left) > ALLOWED_IMBALANCE) {
        if (height(t->_right->_right) >= height(t->_right->_left)) {
          rightRightRotate(t); 
        } else {
          rightLeftRotate(t); 
        }
    }

    t->_height = max(height(t->_left), height(t->_right)) + 1; // !!!!!
  }

  void insert(const T& x, AvlNode*& t) {
    if (t == nullptr) {
      t = new AvlNode{x, nullptr, nullptr}; 
    } else if (Less(x, t->_data)) {
      insert(x, t->_left); 
    } else if (Less(t->_data, x)) {
      insert(x, t->_right); 
    } 

    balance(t); // !!!
  }

  void insert(const T&& x, AvlNode*& t) {
    if (t == nullptr) {
      t = new AvlNode{x, nullptr, nullptr}; 
    } else if (Less(x, t->_data)) {
      insert(x, t->_left); 
    } else if (Less(t->_data, x)) {
      insert(x, t->_right); 
    } 

    balance(t); // !!!
  }

  void remove(const T& x, AvlNode*& t) {
    if (t == nullptr) {
      return ; // Item not found
    } 
    if (Less(x, t->_data)) {
      remove(x, t->_left); 
    } else if (Less(t->_data, x)) {
      remove(x, t->_right); 
    } else if ((t->_left != nullptr) && (t->_right != nullptr)) {
      // t->_data = findMin(t->_right)->_data; 
      // remove(t->_data, t->_right); 
      t->_data = findMax(t->_left)->_data; 
      remove(t->_data, t->_left); 
    } else {
      AvlNode* tmp = t; 
      t = (t->_left != nullptr) ? t->_left : t->_right; 
      delete tmp; 
    }

    balance(t); // !!!
  }
  
  AvlNode* findMin(AvlNode* t) const {
    if (t == nullptr || t->_left == nullptr) {
      return t; 
    } 
    return findMin(t->_left); 
  }

  AvlNode* findMax(AvlNode* t) const {
    if (t != nullptr) {
      while (t->_right != nullptr) {
        t = t->_right; 
      }
    }
    return t; 
  }
  
  bool contains(const T& x, AvlNode* t) const {
    while (t != nullptr) {
      if (Less(x, t->_data)) {
        t = t->_left; 
      } else if (Less(t->_data, x)) {
        t = t->_right; 
      } else { // match
        return true; 
      }
    }
    return false; 
  }
  
  void print(AvlNode* t) {
    if (t != nullptr) {
      print(t->_left); 
      std::cout << t->_data << ' '; 
      print(t->_right); 
    }
  }

  void print(AvlNode* t, int format, int gap, const char div) const {
    if (t != nullptr) {
      if (format) {
        for (int i = 0; i < format-gap; ++i) {
          std::cout << ' '; 
        }
        std::cout << '|'; 
        for (int i = 0; i < gap-1; ++i) {
          std::cout << div; 
        }
      }

      std::cout << t->_data << ' ' 
                << '[' << t->_height << ']' << std::endl; 

      print(t->_left, format+gap, gap, div); 
      print(t->_right, format+gap, gap, div); 
    }
  }
  
  void makeEmpty(AvlNode*& t) { // !!!!!
    if (t != nullptr) {
      makeEmpty(t->_left); 
      makeEmpty(t->_right); 
      delete t; 
    }
    t = nullptr; 
  }

  AvlNode* clone(AvlNode* t) const {
    if (t == nullptr) {
      return nullptr; 
    } else {
      return new AvlNode{t->_data, clone(t->_left), clone(t->_right)}; 
    }
  }

}; // end of class AvlTree

#endif
