#include "deque.hpp"

// constructor
template <typename T>
Deque<T>::Deque() {
    
}

// copy constructor
template <typename T>
Deque<T>::Deque(Deque<T>& copy) {

}

// overloading = operator
template <typename T>
Deque<T>& Deque<T>::operator=(Deque<T>& other) {
  
}

// destructor
template <typename T>
Deque<T>::~Deque() {

} 

template <typename T>
bool Deque<T>::isEmpty() const noexcept {
  return true;
}

template <typename T>
void Deque<T>::pushFront(const T & item) {

}

template <typename T>
void Deque<T>::popFront() {

}

template <typename T>
T Deque<T>::front() const {
  return T();
}

template <typename T>
void Deque<T>::pushBack(const T & item) {

}

template <typename T>
void Deque<T>::popBack() {

}

template <typename T>
T Deque<T>::back() const {

}