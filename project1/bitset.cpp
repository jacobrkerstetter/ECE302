#include "bitset.hpp"

// default constructor
Bitset::Bitset() {
    bitset = new u_int8_t[8];
    setSize = 8;
    valid = true;
}

// custom size constructor
Bitset::Bitset(intmax_t size) {
    if (size <= 0)
        valid = false;
    else {
        bitset = new u_int8_t[size];
        setSize = size;
        valid = true;
    }
}

// custom bitset constructor
Bitset::Bitset(const std::string& value) {
    setSize = value.length();
    valid = true;
    bitset = new u_int8_t[setSize];

    for (int i = 0; i < setSize; i++) {
        if (value[i] != '1' || value[i] != '0')
            valid = false;

        bitset[i] = (u_int8_t)value[i];
    }
}

// destructor
Bitset::~Bitset() {
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
        bitset[index] = 1;
}

// reset bit function
void Bitset::reset(intmax_t index) {
    if (index < 0 || index > setSize - 1)
        valid = false;
    else
        bitset[index] = 0;
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
    if (bitset[index] == 1) return true;
    else if (bitset[index] == 0) return false;
    else if (index < 0 || index > setSize - 1)
        valid = false;
    return false;
}

// to string function
std::string Bitset::asString() const {
    std::string set;

    for (size_t i = setSize; i >= 0; i--)
        set += bitset[i];

    return set;
}