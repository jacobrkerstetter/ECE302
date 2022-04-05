
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>
{
public:
    
    // return true if the priority queue is empty
    bool isEmpty();
    
    // insert item into the queue
    void add(const T& item);
    
    // remove highest priority item from the queue
    void remove();
    
    // get the item with the highest priority from the queue
    T peek();
    
private:
    
    DynamicArrayList<T> lst;
};

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    return lst.isEmpty();
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    // insert new data at bottom of heap
    lst.insert(lst.getLength(), item);

    // if insert is first item, do base case
    if (lst.getLength() == 1) 
        return;

    // trickle up algorithm
    int idx = lst.getLength() - 1, parentIdx;
    bool inPlace = false;
    while (idx > 0 && !inPlace) {
        parentIdx = (idx - 1) / 2;

        std::cout << idx << " " << parentIdx << std::endl;
        if (lst.getEntry(idx) < lst.getEntry(parentIdx)) 
            inPlace = true;
        else {
            lst.setEntry(idx, lst.getEntry(parentIdx));
            lst.setEntry(parentIdx, item);
            idx = parentIdx;
        }
    }
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    // copy item from last item to root
    lst.setEntry(0, lst.getEntry(lst.getLength() - 1));
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{   
    return lst.getEntry(0);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
