#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  items = new T[MAXSIZE];
  size = 0;
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] items;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs) {}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const{
  return size == 0;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return size;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  return false;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  return false;
}

template <typename T>
void ArrayList<T>::clear() {
  size = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  return items[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {}
