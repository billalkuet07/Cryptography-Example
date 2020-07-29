/* this function take 16 bit,i input and convert it to 8bit output*/
/* Section 2.2*/
#include <iostream>
#include "myHeader.h"

using namespace std;


int mul_y(int V,int c, int i)
{
  // print output to user
    if (i==0) //check the MSB of V==1?
    {
     return V;
    }

    else
    {
     return mul_x(mul_y(V,c,i-1),c);

    }

}

