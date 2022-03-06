#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>(), count(0)
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  /*
  if (list.getLength() == 0) {
    list.insert(1, item);
    return;
  }
  else if (list.getLength() == 1) {
    if (item > list.getEntry(1)) list.insert(2, item);
    else list.insert(1, item);
    return;
  }
  */

  int i = 0;
  while (i < list.getLength() && item > list.getEntry(i+1)) {
      std::cout << list.getEntry(i+1);
      i++;
  }
  
  LinkedList<T>::insert(i+1, item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");

  int i = 0;
  while (i < list.getLength() && list.getEntry(i+1) != item) {
      std::cout << i;
      i++;
  }
  
  std::cout << list.getEntry(i+1);
  LinkedList<T>::remove(i+1);
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  return LinkedList<T>::getEntry(position+1);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  // todo
  return 0;
}