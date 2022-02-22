//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

template<class ItemType>
Stack<ItemType>::Stack() 
{
	// initialize headPtr and current size to defaults
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor

template<class ItemType>
Stack<ItemType>::~Stack()
{
	// clear stack which also sets headPtr to null
	clear();
}  // end destructor

template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	// test is current size is equal to zero
	return currentSize == 0;
}  // end isEmpty

template<class ItemType>
int Stack<ItemType>::size() const
{
	// return the current size of stack
	return currentSize;
}  // end size

template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	// add a new item to stack
	if (!headPtr) { // if headPtr is null
		headPtr = new Node<ItemType>(newItem); // create a new node for headPtr
		currentSize++;	// increment size
		return true;
	}

	// do insert at front and increment size
	headPtr = new Node<ItemType>(newItem, headPtr);
	currentSize++;
	return true;
	
}  // end push

template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	// if there is no item at the top of the stack, throw logic error
	if (isEmpty())
		throw(logic_error("Peeking at Empty Stack"));
	// if the stack has an item, return it
	return headPtr->getItem();
}  // end peek

template<class ItemType>
bool Stack<ItemType>::pop() 
{
	// if stack is empty, return false, cannot pop
	if (!headPtr)
		return false;

	// remove top item
	// set temp to point to top element, advance headPtr, and deallocate temp
	Node<ItemType>* temp = headPtr;
	headPtr = headPtr->getNext();

	temp->setNext(nullptr);
	delete temp;
	temp = nullptr;

	// decrement size counter
	currentSize--;
	return true;

}  // end pop

template<class ItemType>
void Stack<ItemType>::clear()
{
	// traverse through stack, deleting each Node and setting headPtr to nullptr
	Node<ItemType>* curr = headPtr, *temp;
	while (curr) {
		temp = curr;
		curr = curr->getNext();
		delete temp;
	}

	headPtr = nullptr;
}  // end clear

