#include "bitset.hpp"

// default constructor
Bitset::Bitset() {
    bitset = new int[8];
    setSize = 8;
    valid = true;

    for (int i = 0; i < 8; i++)
        bitset[i] = 0;
}

// custom size constructor
Bitset::Bitset(intmax_t size) {
    if (size <= 0) {
        valid = false;
    }
    else {
        bitset = new int[size];
        setSize = size;
        valid = true;

        for(int i = 0; i < size; i++)
            bitset[i] = 0;
    }
}

// custom bitset constructor
Bitset::Bitset(const std::string& value) {
    setSize = value.length();
    valid = true;
    bitset = new int[setSize];

    for (int i = 0; i < setSize; i++) {
        if (value[i] != '1' && value[i] != '0')
            valid = false;

        bitset[i] = (int)(value[i] - '0');
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
    if (!valid || index < 0 || index > setSize - 1)
        valid = false;
    else
        bitset[setSize - index - 1] = 1;
}

// reset bit function
void Bitset::reset(intmax_t index) {
    if (!valid || index < 0 || index > setSize - 1)
        valid = false;
    else
        bitset[setSize - index - 1] = 0;
}

// toggle function
void Bitset::toggle(intmax_t index) {
    if (!valid || index < 0 || index > setSize - 1)
        valid = false;
    else
        bitset[setSize - index - 1] = !bitset[setSize - index - 1];
}

// test function
bool Bitset::test(intmax_t index) {
    if (!valid || index < 0 || index > setSize - 1)
        valid = false;
    else
        return bitset[setSize - index - 1];

    return false;
}

// to string function
std::string Bitset::asString() const {
    std::string set;

    for (size_t i = 0; i < setSize; i++)
        set += std::to_string(bitset[i]);

    return set;
}