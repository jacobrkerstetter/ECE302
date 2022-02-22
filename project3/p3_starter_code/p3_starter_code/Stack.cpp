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
	// initialize head and current size to defaults
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor

template<class ItemType>
Stack<ItemType>::~Stack()
{
	// clear stack and set head to null
	clear();
	headPtr = nullptr;
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
	if (!head) { // if head is null
		head = new Node(newItem); // create a new node for head
		return true;
	}

	// keep doing insert at front
	
	
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	ItemType returnItem;
	return returnItem;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	return false;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
}  // end clear

