#include "bitset.hpp"
#include <iostream>

// default constructor
Bitset::Bitset() {
    bitset = new uint8_t[8];
    setSize = 8;
    valid = true;

    for(int i = 0; i < 8; i++)
        bitset[i] = 0;
}

// custom size constructor
Bitset::Bitset(intmax_t size) {
    if (size <= 0) {
        valid = false;
    }
    else {
        bitset = new uint8_t[size]();
        setSize = size;
        valid = true;
        std::fill(bitset, bitset + 8, 0);
    }
}

// custom bitset constructor
Bitset::Bitset(const std::string& value) {
    setSize = value.length();
    valid = true;
    bitset = new uint8_t[setSize];

    for (int i = 0; i < setSize; i++) {
        if (value[i] != '1' && value[i] != '0')
            valid = false;

        bitset[i] = (uint8_t)value[i];
    }
}

// destructor
Bitset::~Bitset() {
    if (bitset)
        delete [] bitset;
}

// size function
intmax_t Bitset::size() const {
    return setSize;
}

// check for validity function
bool Bitset::good() const {
    return valid;
}

// set bit function
void Bitset::set(intmax_t index) {
    if (index < 0 || index > setSize - 1)
        valid = false;
    else
        bitset[setSize - index - 1] = 1;

    std::cout << bitset[setSize - index - 1] << std::endl;
}

// reset bit function
void Bitset::reset(intmax_t index) {
    if (index < 0 || index > setSize - 1)
        valid = false;
    else
        bitset[setSize - index - 1] = 0;

    std::cout << bitset[setSize - index - 1] << std::endl;
}

// toggle function
void Bitset::toggle(intmax_t index) {
    if (index < 0 || index > setSize - 1)
        valid = false;
    else
        bitset[index] = !bitset[index];
}

// test function
bool Bitset::test(intmax_t index) {
    if (index < 0 || index > setSize - 1)
        valid = false;
    else
        return bitset[index];

    return false;
}

// to string function
std::string Bitset::asString() const {
    std::string set;

    for (size_t i = 0; i < setSize; i++) {
        set += std::string(1,bitset[i]);
        std::cout << set << std::endl;
    }

    return set;
}