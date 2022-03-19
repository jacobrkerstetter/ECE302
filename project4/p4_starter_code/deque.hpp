#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{
  public:
    Deque(); // constructor
    Deque(Deque& copy) // copy constructor
    Deque operator=(Deque& other) // overloading = operator
    ~Deque(); // destructor
  private:
    LinkedList<T> l;
    int count;
};

#include "deque.tpp"

#endif
