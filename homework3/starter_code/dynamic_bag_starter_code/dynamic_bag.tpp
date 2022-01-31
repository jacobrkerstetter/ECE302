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
    bagArray[i] = x[i];
}
    
template<typename T>
DynamicBag<T>::~DynamicBag() { 
  delete [] bagArray;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  
  return *this; // SHALLOW OR DEEP COPY??
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  if(size >= MAXSIZE){
    return false;
  }

  data[size] = entry;
  ++size;
  
  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  return false;
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
  return false;
}

template<typename T>
void DynamicBag<T>::clear() {
  size = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  return 0;
};
