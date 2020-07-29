
#include <iostream>
#include "myHeader.h"

using namespace std;


int DIV(int c)
{
        return ((mul_y(c,0xa9,16)<<24)|(mul_y(c,0xa9,39)<<16)| (mul_y(c,0xa9,6)<<8)|mul_y(c,0xa9,64));
}

