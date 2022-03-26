#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), count(0)
{}

template <typename T>
LinkedList<T>::~LinkedList()
{
  // empty the linked list
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  count = x.count;
  Node<T>* origHead = x.head;

  // copy all of the nodes from the other linked this to this one
  // if other list is empty, make this list empty
  if (!origHead) head = nullptr;
  else {
    // make copy of first node
    head = new Node<T>(origHead -> getItem());

    // copy remaining nodes
    Node<T>* newPtr = head;
    while (origHead) {
      newPtr -> setNext(new Node<T>(origHead -> getItem()));
      origHead = origHead -> getNext();
      newPtr = newPtr -> getNext();
    }
  }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  LinkedList<T> temp(x);
  x = y;
  y = temp;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  count = x.count;
  Node<T>* origHead = x.head;

  if (!origHead) head = nullptr;
  else {
    // make copy of first node
    head = new Node<T>(origHead -> getItem());

    // copy remaining nodes
    Node<T>* newPtr = head;
    while (origHead) {
      newPtr -> setNext(new Node<T>(origHead -> getItem()));
      origHead = origHead -> getNext();
      newPtr = newPtr -> getNext();
    }
  }

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
  // cannot insert in postion less than 1 or greater than 1 past end
  if (position < 1 || position > count + 1) return false;
  // insert to empty list
  else if (count == 0) {
    head = new Node<T>(item);
    ++count;
    return true;
  }
  // insert at front
  else if (position == 1) {
    head = new Node<T>(item, head);
    ++count;
    return true;
  }
  
  // insert anywhere else
  // loop to position
  int i = 1;
  Node<T>* curr = head;
  while (i < position - 1) {
    curr = curr -> getNext();
    ++i;
  }

  // set new node and pointers
  curr -> setNext(new Node<T>(item, curr -> getNext()));
  ++count;
  return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  // check for valid position
  if (position < 1 || position > count) return false;

  Node<T>* temp = nullptr;
  // remove from pos. 1
  if (position == 1) {
    temp = head
    head = head -> getNext();
  }
  // remove from other positions
  else {
    Node<T>* curr = head;
    int i = 1;
    while (i != position - 1) {
      ++i;
      curr = curr -> getNext();
    }
    temp = curr -> getNext();
    curr -> setNext(temp -> getNext());
  }

  // delete the node marked for deletion
  temp -> setNext(nullptr);
  delete temp;
  temp = nullptr;

  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  // continuously remove first element
  while (!isEmpty()) remove(1);
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //preconditions
  if (position < 1 || position > count)
    throw(std::range_error("error in position range"));
  else {
    int i = 1;
    Node<T>* curr = head;
    while (i != position) {
      ++i;
      curr = curr -> getNext();
    }

    return curr -> getItem();
  }
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  // if position invalid return
  if (position > count || position < 1)
    return;

  // if position is valid, loop through to that entry
  int i = 1;
  Node<T>* curr = head;
  while (i != position) {
    curr = curr->getNext();
    i++;
  }

  curr->setItem(newValue);
}
