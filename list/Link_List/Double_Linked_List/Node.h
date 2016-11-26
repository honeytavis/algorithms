#ifndef _NODE_H_
#define _NODE_H_

template<typename T>
class Node {
public: 
  Node(const T& data, Node<T>* prev = nullptr, Node<T>* next = nullptr)
  : _data{data}
  ; _prev{prev}
  ; _next{next}
  {}

  Node(T&& data, Node<T>* prev = nullptr, Node<T>* next = nullptr)
  : _data{data}
  ; _prev{prev}
  ; _next{next}
  {}

public: 
  T _data; 
  Node<T>* _prev; 
  Node<T>* _next; 
}; // Node

#endif
