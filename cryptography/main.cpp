/* Author: MD BILLAL HOSSAIN
the objectives is to demonstrate the operation of cryptographic algorithm in C++
This is a part of assignment*/

#include<iostream>
#include "myHeader.h"
using namespace std;
int main()
{
  std::cout.setf(std::ios::hex, std::ios::basefield); //to show the output
  // variable initialization
  int F,i; // F register to store the value from FSM
  int key_input[] = { 0x12345678, 0x90abcdef, 0xfedcba90, 0x8765421 };  //key input 128 bit
  int init_input[] = { 0x12345678, 0x90abcdef, 0xfedcba90, 0x8765421 }; //initialized input 128 bit
  int text[]={0x01234567,0x89abcdef}; // text input PQ, RS combined to make 32 bit (this could be make automated according to user input but i have done for simple example)
  int len = sizeof(text)/sizeof(text[0]); // find the length of
  int enc_key[len-1]; //store the encrypted output key


  FSM f; //object creation and initialized r1,r2,r3=0x00000000
  LFSR l(key_input,init_input); //object creation and initialized with 128 bit key and initialized parameter
  //initialization mode of FSM and LFSR
  for (i=0;i<=31;i++) //run for 32 times
  {
    F=f.calculate_F(l.s[15], l.s[5]); //FSM is clocked producing the 32 bit word F
    l.initialization_mood(F); //LFSR is clocked in initialization mode consuming F
  }
  cout<<"\n";
  cout<<"\n ****************initialization done (run for 32 times)******************";
  cout<<"\n";
  //key-stream generation
  F=f.calculate_F(l.s[15], l.s[5]); //FSM is clocked once and the output is discarded
  l.key_mood(); //LFSR key mode is clocked once
  //run for each 32 bit ASCII text pair and encrypt by XOR with key and text
  cout<<"\n";
  cout<<"\n *****************start of key generation**************************";
  cout<<"\n";
  for (i=0;i<len;i++)
  {

    F=f.calculate_F(l.s[15], l.s[5]); //FSM is clocked once
    enc_key[i]=F^l.s[0];  //keystream calculation
    cout<<"\n key"<<i<<"="<<enc_key[i];
    l.key_mood(); //LFSR in keystram mode
  }
  cout<<"\n";
  cout<<"\n *********************end of key generation************************";
  cout<<"\n";


  return 0;
}
