#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "linked_list.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{
  public:
    /** Constructs a deque ojbect
     */
    Deque();

    /** Constructs a copy of a deque object
     */
    Deque(Deque<T>& copy);

    /** Creates a deep copy of the right hand deque
     */
    Deque<T>& operator=(Deque<T>& other);

    /** Destructs the deque object when it is out of scope
     */
    ~Deque();

    /** Returns true if the deque is empty, else false
     */
    virtual bool isEmpty() const noexcept = 0;

    /** Add item to the front of the deque
     * may throw std::bad_alloc
     */
    virtual void pushFront(const T & item) = 0;

    /** Remove the item at the front of the deque
     * throws std::runtime_error if the deque is empty
     */
    virtual void popFront() = 0;

    /** Returns the item at the front of the deque
     * throws std::runtime_error if the deque is empty
     */
    virtual T front() const = 0;

    /** Add item to the back of the deque
     * may throw std::bad_alloc
     */
    virtual void pushBack(const T & item) = 0;

    /** Remove the item at the back of the deque
     * throws std::runtime_error if the deque is empty
     */
    virtual void popBack() = 0;


    /** Returns the item at the back of the deque
     * throws std::runtime_error if the deque is empty
     */
    virtual T back() const = 0;
  private:
    LinkedList<T> l;
    int count;
};

#include "deque.tpp"

#endif
