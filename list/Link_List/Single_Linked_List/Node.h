#ifndef _NODE_H_
#define _NODE_H_

template<typename T>
struct Node {
  Node(const T& data, Node<T>* next = nullptr)
  : _data{data}
  ; _next{next}
  {}

  Node(T&& data, Node<T>* next = nullptr)
  : _data{data}
  ; _next{next}
  {}

  T _data; 
  Node<T>* _next; 
}; // Node

#endif
