#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "Node.h"

template<typenaem T>
class const_iterator {
friend: class List<T>; 
public: 
  const_iterator()
  : _current{nullptr}
  {}

  const T& operator* () const {
    return retrieve(); 
  }

  const_iterator& operator++ () {
    _current = _current->_next; 
    return *this; 
  }
 
  const_iterator operator++ (int) {
    const_iterator old = *this; 
    ++(*this); // operator++
    return old; 
  }

  const_iterator& operator-- () {
    _current = _current->_prev; 
    return *this; 
  }
  
  const_iterator operator--(int) {
    const_iterator old = *this; 
    --(*this); 
    return old; 
  }

  bool operator== (const const_iterator& rhs) const {
    return _current == rhs._current;
  }

  bool operator!= (const const_iterator& rhs) const {
    return _current != rhs._current; 
  }

protected: 
  T& retrive() const {
    return current->_data; 
  }

  const_iterator(Node* p) 
  : _current{p}
  {}

protected: 
  Node* _current; 
}; // const_iterator

class iterator : public const_iterator {
// friend: class List<T>; 
public: 
  T& operator* () {
    return const_iterator::retrive(); 
  }

  const T& operator* () const {
    return const_iterator::operator*(); 
  } 

  iterator& operator++ () {
    this->_current = this->_current->_next; 
    return *this; 
  }

  iterator operator++ (int) {
    iterator old = *this; 
    ++(*this); 
    return old; 
  }

  iterator& operator-- () {
    this->_current = this->_current->_prev; 
    return *this; 
  }

  iterator operator-- (int) {
    iterator old = *this; 
    --(*this); 
    return old; 
  }

protected: 
  iterator(Node* p) 
  : const_iterator{p}
  {}
}; // iterator

#endif
