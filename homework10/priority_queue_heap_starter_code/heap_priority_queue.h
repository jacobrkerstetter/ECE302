
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

    // recursive function to reorder heap after deletion
    void heapify(int root);
    
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
    // copy item from last item to root and delete last item (fill default value)
    lst.setEntry(0, lst.getEntry(lst.getLength() - 1));
    lst.remove(lst.getLength() - 1);

    heapify(0);
}

template <typename T>
void HeapPriorityQueue<T>::heapify(int root) {
    // check if root is a leaf node
    if (((2*root) + 1 < lst.getLength()) && ((2*root) + 2 < lst.getLength())) {
        // left/assumed larger child
        int largeChild = (2*root) + 1;

        // check if theres a right child
        if ((2*root) + 2 < lst.getLength()) {
            // right child
            int rightChild = largeChild + 1;
            // if right child is larger than left child, swap them
            if (lst.getEntry(rightChild) > lst.getEntry(largeChild))
                largeChild = rightChild;
        }

        // if root is smaller than the larger child, swap them and recurse to trickle down
        if (lst.getEntry(root) < lst.getEntry(largeChild)) {
            T temp = lst.getEntry(largeChild);
            lst.setEntry(largeChild, lst.getEntry(root));
            lst.setEntry(root, temp);

            heapify(largeChild);
        }
    }
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{   
    return lst.getEntry(0);
}

#endif // _HEAP_PRIORITY_QUEUE_H_