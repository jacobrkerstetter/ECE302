#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() : count(0) {
  items = new T[MAXSIZE];
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] items;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs) {
  items = new T[rhs.MAXSIZE];
  
  for (int i = 0; i < rhs.getLength(); i++)
    items[i] = rhs.items[i];

  count = rhs.count;
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs) {
  if (items)
    delete [] items;
  
  items = new T[rhs.MAXSIZE];

  for (int i = 0; i < rhs.getLength(); i++)
    items[i] = rhs.items[i];

  count = rhs.count;

  return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const{
  return count == 0;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return count;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  // invalid position
  if (position > count + 1 || position < 1)
    return false;

  // array is not big enough to add an element
  if (count == MAXSIZE - 1)
    upsize();

  // element needs to go at end
  if (position == count + 1) {
    items[position-1] = item;
    count++;
    return true;
  }

  // element needs to go in a spot already taken
  for (int i = count; i >= position; i--)
    items[i] = items[i-1];

  items[position - 1] = item; 
  count++;

  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  if (position < 1 || position > count + 1)
    return false;

  for (int i = position - 1; i < count - 1; i++)
    items[i] = items[i + 1];

  items[count] = 0;
  count--;
  return true;
}

template <typename T>
void ArrayList<T>::clear() {
  for (int i = 0; i < count; i++)
    items[i] = 0;

  count = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  if (position > count || position < 1)
    return T();

  return items[position-1];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  if (position > count || position < 1)
    return;

  items[position-1] = newValue;
}

template <typename T>
void ArrayList<T>::upsize() {
  // double the array size
  MAXSIZE *= 2;
  T* biggerArray = new T[MAXSIZE];

  // copy the items over
  for (int i = 0; i < count; i++)
    biggerArray[i] = items[i];

  // delete the old memory, switch pointers, and set biggerArray to null
  delete items;
  items = biggerArray;
  biggerArray = nullptr;
}