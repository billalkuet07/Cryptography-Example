
#include <iostream>
#include "myHeader.h"

using namespace std;
int Sbox1(int ww)
{
 int r[3],w[3],rr;
 w[3]=ww&0xFF; //LSB 8bit
 w[2]=(ww & 0xFF00)>>8; //next 8bit
 w[1]=(ww & 0xFF0000)>>16; //next 8bit
 w[0]=(ww & 0xFF000000)>>24; //MSB

 r[0]= mul_x(SR(w[0]),0x1b)                 ^       SR(w[1])                           ^ SR(w[2])                              ^ (mul_x(SR(w[3]),0x1b)^ SR(w[3]));

 r[1]=(mul_x(SR(w[0]),0x1b)^SR(w[0]))       ^ mul_x(SR(w[1]),0x1b)                     ^ SR(w[2])                              ^ SR(w[3]);

 r[2]=SR(w[0])                              ^       (mul_x(SR(w[1]),0x1b)^SR(w[1]))    ^ mul_x(SR(w[2]),0x1b)                  ^ SR(w[3]);

 r[3]=SR(w[0])                              ^ SR(w[1])                                 ^ (mul_x(SR(w[2]),0x1b)^SR(w[2]))       ^ mul_x(SR(w[3]),0x1b);

 rr=(r[0]<<24) | (r[1]<<16) | (r[2]<<8) | r[3];

 return rr;
}

