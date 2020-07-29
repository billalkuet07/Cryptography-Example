/* this function take 16 bit input and convert it to 8bit output*/
/* Section 2.1*/

#include <iostream>
#include "myHeader.h"

using namespace std;


int mul_x(int V,int c)
{
  // print output to user
    int out=0x00;
    if ((V&0x80)!=0x00) //check the MSB of V==1?
        out= ((V<<1)^c)&0xFF;
    else
      out=(V<<1);
    return out;
}
