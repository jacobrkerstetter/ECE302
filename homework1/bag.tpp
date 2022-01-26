#include "bag.hpp"                                                                                                    

// constructor: set size = 0, create a new array to hold the data
template <typename T> Bag<T>::Bag() {}

template <typename T> Bag<T>::~Bag() {}

template <typename T> std::size_t Bag<T>::getCurrentSize() const { return bag.size(); }

template <typename T> bool Bag<T>::isEmpty() const { return bag.size() == 0; }

template <typename T> bool Bag<T>::add(const T& entry) {
    try {
        bag.push_back(entry);
        return true;
    }
    catch(...) {
        return false;
    }
}

template <typename T> bool Bag<T>::remove(const T& entry) {
    for (size_t i = 0; i < getCurrentSize(); i++)
        if (bag[i] == entry) {
            bag.erase(bag.begin() + i);
            return true;
        }

    return false;
}

template <typename T> void Bag<T>::clear() { bag.clear(); }

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const {
    size_t count = 0;

    for (size_t i = 0; i < bag.size(); i++)
        if (bag[i] == entry)
            count++;

    return count;
}

template <typename T> bool Bag<T>::contains(const T& entry) const {
    for (size_t i = 0; i < bag.size(); i++)
        if (bag[i] == entry)
            return true;
    return false;
}

