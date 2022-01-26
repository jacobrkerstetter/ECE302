#ifndef ABSTRACT_BAG
#define ABSTRACT_BAG

#include <cstdlib>

template <typename T>
class AbstractBag {
    public:
        // function to get the size of the bag
        virtual std::size_t getCurrentSize() const = 0;

        // function to check if the bag is empty
        virtual bool isEmpty() const = 0;

        // function to add an item to the bag
        virtual bool add(const T& entry) = 0;

        // function to remove an item from the bag if the bag contains it
        virtual bool remove(const T& entry) = 0;

        // function to clear the bag
        virtual void clear() = 0;

        // function to check the frequency of an item in the bag
        virtual std::size_t getFrequencyOf(const T& entry) const = 0; 

        // function to check if the bag contains an item
        virtual bool contains(const T& entry) const = 0;
};

#endif