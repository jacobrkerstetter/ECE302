#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : count(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
  this->clear();
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
  // swap head pointers?
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
  // check if position is valid (at end or less)
  if (position > count + 1)
    return false;
  // check if this is the first insert
  else if (count == 0) {
    head = new Node<T>(item, nullptr);
    count++;
    return true;
  }
  // test if inserting at front
  else if (position == 1) {
    head = new Node<T>(item, head);
    count++;
    return true;
  }

  // loop until position before insert
  int i = 1;
  Node<T>* curr = head;
  while (i < position - 1) {
    curr = curr->getNext();
    i++;
  }

  // create a new Node<T> and set it to be the next node<T>
  Node<T>* temp = new Node<T>(item, curr->getNext());
  curr->setNext(temp);
  
  // increment count
  count++;

  return true;
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
  // set two points to keep track of
  Node<T>* curr = head;
  Node<T>* temp;

  // before you hit end of list...
  while (curr) {
    temp = curr->getNext(); // set temp to next node<T>
    curr->setNext(nullptr); // set the next pointer of current node<T> to nullptr
    delete curr; // free the memory the node<T> is taking up
    curr = temp; // advance curr
  }

  head = nullptr;
}

// ASK ABOUT THIS ONE
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  // try to see if position is higher than the number of node<T>, cannot get
  try {
    if (position > count)
      throw(position);
    // if position is valid, loop through to that entry
    int i = 1;
    Node<T>* curr = head;
    while (i != position) {
      curr = curr->getNext();
      i++;
    }
    return curr->getItem();
  }
  catch (int position) {
    std::cout << "Fatal Error: Position " << position << " is out of range! Exiting";
    exit(EXIT_FAILURE);
  }
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  // if position is higher than the number of node<T>s, cannot set
  if (position > count)
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

template <typename T>
void LinkedList<T>::printList() {
  Node<T>* curr = head;
  while (curr) {
    std::cout << curr->getItem() << std::endl;
    curr = curr->getNext();
  }
}