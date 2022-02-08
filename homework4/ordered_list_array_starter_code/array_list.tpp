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
  return count == 0;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return MAXSIZE;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  if (position-1 >= MAXSIZE)
    upsize()

  items[position-1] = item;
  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  
}

template <typename T>
void ArrayList<T>::clear() {
  count = 0;
  for (int i = 0; i < size; i++)
    items[i] = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  return items[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {}
