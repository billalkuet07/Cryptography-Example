#include <iostream>
#include "myHeader.h"
#include<math.h>

using namespace std;

FSM::FSM ()
    {
        r1=0x00000000;
        r2=0x00000000;
        r3=0x00000000;
    }

int FSM::calculate_F(int s15, int s5)
{
int F,r;
F=(this->modulo(s15,r1))^r2;
r=this->modulo(r2,(r3^s5));
r3=Sbox2(r2);
r2=Sbox1(r1);
r1=r;
cout<<"\n FSM calculation is done......";
return F;
}

int FSM::modulo(int a, int b)
{
 unsigned long int out1=0x100000000; //2^32 in hex

 unsigned long int temp1;
 int temp2;
 temp1=a%out1;
 temp2=b%out1;
 temp1=temp1+temp2;
 temp1=(temp1)%out1; //(a+b)mod n = (a mod n+ b mod n) mod n
 temp2=temp1;
 return temp2;  // addition modulo operation

}
