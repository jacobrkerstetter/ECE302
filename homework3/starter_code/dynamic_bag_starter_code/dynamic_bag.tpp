#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
  bagArray = new T[10];
  size = 0;
  MAXSIZE = 10;
}
  
template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x) {
  bagArray = new T[x.MAXSIZE];
  size = x.size;
  MAXSIZE = x.MAXSIZE;

  for (int i = 0; i < x.size; i++)
    bagArray[i] = x.bagArray[i];
}
    
template<typename T>
DynamicBag<T>::~DynamicBag() { 
  delete [] bagArray;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  
  for (int i = 0; i < x.size; i++)
    bagArray[i] = x.bagArray[i];

  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  if(size >= MAXSIZE) {
    upsize();
  }

  bagArray[size] = item;
  ++size;
  
  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  if(size == 0) return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(bagArray[i] == item) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  for(std::size_t i = idx; i < size; ++i){
    bagArray[i] = bagArray[i+1];
  }

  return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return size == 0;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  return getFrequencyOf(item) != 0;
}

template<typename T>
void DynamicBag<T>::clear() {
  size = 0;
}

template<typename T>
void DynamicBag<T>::upsize() {
  MAXSIZE *= 2;
  T* biggerArray = new T[MAXSIZE];
  delete [] bagArray;
  bagArray = biggerArray;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(bagArray[i] == item) ++freq;
  }
  
  return freq;
};
