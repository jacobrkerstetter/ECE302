#include "deque.hpp"

// constructor
template <typename T>
Deque<T>::Deque() : count(0)
{}

// copy constructor
template <typename T>
Deque<T>::Deque(Deque<T>& copy) {
  count = copy.count;
}

// overloading = operator
template <typename T>
Deque<T>& Deque<T>::operator=(Deque<T>& other) {
  return *this;
}

// destructor
template <typename T>
Deque<T>::~Deque() {
  l.clear();
} 

template <typename T>
bool Deque<T>::isEmpty() const noexcept {
  return count == 0;
}

template <typename T>
void Deque<T>::pushFront(const T & item) {

}

template <typename T>
void Deque<T>::popFront() {
  if (isEmpty())
    throw (std::runtime_error("Deque Empty"));
  else 
    l.remove(1);
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
  if (isEmpty()) 
    throw(std::runtime_error("Deque Empty"));
  else
    l.insert(count + 1, item);
}

template <typename T>
void Deque<T>::popBack() {
  if (isEmpty()) 
    throw(std::runtime_error("Deque Empty"));
  else
    l.remove(count);
}

template <typename T>
T Deque<T>::back() const {

}