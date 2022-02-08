#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : count(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
  delete head;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //TODO
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  //TODO
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //TODO
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  return count == 0;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  return count;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  int i = 1;
  while (i < position) {
    if ()
  }
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  // loop through and delete all the nodes, set head = nullptr
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //TODO
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
