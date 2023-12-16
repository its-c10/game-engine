#include <iostream>
#include "./component.hpp";

// unsigned 32 bit number (0 to whatever 32 1s is)
// Each entity is simply a number (an ID)
using Entity = uint32_t;



struct Transform {
	double x;
	double y;
};