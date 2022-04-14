#include "frontier_queue.hpp"

template <typename T>
State<T> frontier_queue<T>::pop() {
  
  // save value to return 
  State<T> returnVal = queue[0];

  // copy item from last item to root and delete last item (fill default value)
  queue[0] = queue[queue.size() - 1];
  queue.erase(queue.begin() + queue.size() - 1);

  // trickle item back down if needed
  int index = 0, small, right;
  bool inPlace = false;

  // if the node is NOT a leaf and is not in place already
  while ((2*index) + 1 < queue.size() && !inPlace) {
    // calculate left child value (assumed cheapest)
    small = 2*index + 1;

    // check for right child
    if ((2*index) + 2 < queue.size()) {
      right = small + 1;

      // if right is smaller than left, swap them
      if (queue[right] < queue[small]) small = right;
    }
    
    // if root is greater than smallest child, swap them
    if (queue[index] > queue[small]) {
      State<T> temp = queue[small];
      queue[small] = queue[index];
      queue[index] = temp;
    }
    // if not, it is in place
    else inPlace = true;
  }


        // if root is smaller than the larger child, swap them and recurse to trickle down
        if (lst.getEntry(root) < lst.getEntry(largeChild)) {
            T temp = lst.getEntry(largeChild);
            lst.setEntry(largeChild, lst.getEntry(root));
            lst.setEntry(root, temp);

            heapify(largeChild);
        }
  }

  // return popped value
  return returnVal;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  // item to add
  State<T> item(p, cost, heur);
  queue[queue.size()] = item;

  // loop to add to bottom and shift up
  int index = queue.size() - 1, parent;
  bool inPlace = false;
  while (index > 0 && !inPlace) {
    parent = (index - 1) / 2;

    // if cost of current item is greater than parent, leave it
    if (queue[index].getFCost() >= queue[parent].getFCost()) inPlace = true;
    // if cost of current item is less than parent, trickle up
    else {
      queue[index] = queue[parent];
      queue[parent] = item;
      index = parent;
    }
  }
}

template <typename T>
bool frontier_queue<T>::empty() {

  return queue.empty();
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  //TODO

  return false;

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

}


