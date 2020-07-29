
#include <iostream>
#include "myHeader.h"

using namespace std;


int MUL(int c)
{
        return ((mul_y(c,0xa9,2)<<24)|(mul_y(c,0xa9,245)<<16)| (mul_y(c,0xa9,48)<<8)|mul_y(c,0xa9,239));
}

