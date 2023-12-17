#include <iostream>
#include <bitset>
#include "../constants.h";

// entity id that can be unsigned 32 bit integer.
using Entity = std::uint32_t;
using ComponentType = std::uint8_t;

// represents a set of bits that indicate whether a component is present or not.
using Signature = std::bitset<MAX_COMPONENTS>;