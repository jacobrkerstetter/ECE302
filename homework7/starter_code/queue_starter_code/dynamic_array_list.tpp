#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T> DynamicArrayList<T>::DynamicArrayList() : size(0), capacity(10) {
  data = new T[capacity];
}

template <typename T> DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x){
  data = new T[x.capacity];
  size = x.size;
  capacity = x.capacity;

  for(int i = 0; i < size; i++)
    *(data + i) = *(x.data + i);
}

template <typename T> DynamicArrayList<T>::~DynamicArrayList(){
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  delete [] data;
}

template <typename T> DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x){
  if(this != &x){
    size = x.size;
    capacity = x.capacity;
  }

  for (int i = 0; i < x.size; i++)
    *(data + i) = *(x.data + i);

  return *this;
}

template <typename T> void DynamicArrayList<T>::swap(DynamicArrayList<T>& y){
  DynamicArrayList<T> temp = this;
  this = y;
  y = temp;
}

template <typename T> bool DynamicArrayList<T>::isEmpty(){
  return size == 0; //returns if the data array is empty or not
}

template <typename T> std::size_t DynamicArrayList<T>::getLength(){
  return size; //size is the allocated memory size of the array
}

template <typename T> void DynamicArrayList<T>::insert(std::size_t position, const T& item){
  if (size >= capacity) upsize();

  ++size;
  for (int i = size-1; i > position; --i)
    data[i+1] = data[i];

  data[position] = item;
}

template <typename T> void DynamicArrayList<T>::remove(std::size_t position){
  if(position >= size) return;

  --size;
  for(std::size_t i = position; i < size; ++i)
    data[i] = data[i+1];
}

template <typename T> void DynamicArrayList<T>::clear(){
  size = 0;
}

template <typename T> T DynamicArrayList<T>::getEntry(std::size_t position){
  if (position < size)
    return data[position];
  else
    return T();
}

template <typename T> void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue){
  if (position < size)
    *(data + position) = newValue;
}

template <typename T> void DynamicArrayList<T>::upsize() {
  capacity *= 2;
  T* biggerArray = new T[capacity];
  delete [] data;
  data = biggerArray;
}