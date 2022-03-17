#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList() : LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x) : LinkedList<T>(x)
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
  return LinkedList<T>::isEmpty();  // call to parent
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();  // call to parent
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  int i = 0;
  while (i < LinkedList<T>::getLength() && item > LinkedList<T>::getEntry(i+1)) 
      i++;
  
  LinkedList<T>::insert(i+1, item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");

  int i = 1;
  bool found = false;
  while (!found && i < getLength()) {
    if (LinkedList<T>::getEntry(i) == item) {
      LinkedList<T>::remove(i);
      found = true;
    }

    i++;
  }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  LinkedList<T>::remove(position+1);  // call to parent
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear(); // call to parent
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  return LinkedList<T>::getEntry(position+1); // call to parent
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  int i = 0;
  while (LinkedList<T>::getEntry(i+1) < newValue)
    i++;

  if (LinkedList<T>::getEntry(i+1) == newValue)
    return i;
  else return -i;

  return 0;
}