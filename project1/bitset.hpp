#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>

class Bitset{
public:

  // default constructor: allocates default size 8 bits
  Bitset();

  // custom constructor: allocates user input size
  Bitset(intmax_t size);

  // string constuctor: allocates a bitset with an input string
  Bitset(const std::string & value);

  // destructor to destroy the memory occupied by the bitset
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // returns the size of the bitset
  intmax_t size() const;

  // returns whether the bitset is valid
  bool good() const;

  // sets the indexed bit to 1
  void set(intmax_t index);

  // sets the indexed bit to 0
  void reset(intmax_t index);

  // toggles the indexed bit
  void toggle(intmax_t index);

  // returns whether the indexed bit is set or reset, and if the set is valid
  bool test(intmax_t index);

  // returns the bitset as a string 
  std::string asString() const;

private:
  int* bitset = nullptr;
  intmax_t setSize;
  bool valid;
};

#endif
