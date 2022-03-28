#include "deque.hpp"

// constructor
template <typename T>
Deque<T>::Deque() : count(0)
{}

// copy constructor
template <typename T>
Deque<T>::Deque(Deque<T>& copy) {
  count = copy.count;
  LinkedList<T> newList(copy.l);
  l = newList;
}

// overloading = operator
template <typename T>
Deque<T>& Deque<T>::operator=(Deque<T>& other) {
  count = other.count;
  LinkedList<T> newList(other.l);
  l = newList;
  return *this;
}

// destructor
template <typename T>
Deque<T>::~Deque() 
{ } 

template <typename T>
bool Deque<T>::isEmpty() const noexcept {
  return count == 0;
}

template <typename T>
void Deque<T>::pushFront(const T & item) {
  l.insert(1, item);
  ++count;
}

template <typename T>
void Deque<T>::popFront() {
  if (isEmpty())
    throw (std::runtime_error("Deque Empty"));
  else {
    l.remove(1);
    --count;
  }
}

template <typename T>
T Deque<T>::front() const {
  if (isEmpty()) 
    throw(std::runtime_error("Deque Empty"));
  else
    return l.getEntry(1);
}

template <typename T>
void Deque<T>::pushBack(const T & item) {
    l.insert(count + 1, item);
    ++count;
}

template <typename T>
void Deque<T>::popBack() {
  if (isEmpty()) 
    throw(std::runtime_error("Deque Empty"));
  else {
    l.remove(count);
    --count;
  }
}

template <typename T>
T Deque<T>::back() const {
  if (isEmpty())
    throw(std::runtime_error("Deque Empty"));
  else 
    return l.getEntry(l.getLength());
}