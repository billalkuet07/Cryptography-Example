
#include <iostream>
#include "myHeader.h"

using namespace std;

    LFSR::LFSR (int k1[], int init[])
    {
        k[0]=k1[0];k[1]=k1[1];k[2]=k1[2];k[3]=k1[3];
        in_it[0]=init[0],in_it[1]=init[1],in_it[2]=init[2],in_it[3]=init[3];
        m=0xFFFFFFFF;
        s[15]=k[3] ^ in_it[0];
        s[11]=k[3] ^ m;
        s[7]=k[3];
        s[3]=k[3] ^ m;

        s[14]=k[2];
        s[10]=k[2] ^ in_it[2] ^ m;
        s[6]=k[2];
        s[2]=k[2] ^ m;

        s[13]=k[1];
        s[9]=k[1] ^ in_it[3] ^ m;
        s[5]=k[1];
        s[1]=k[1] ^ m;

        s[12]=k[0] ^ in_it[1];
        s[8]=k[0] ^ m;
        s[4]=k[0];
        s[0]=k[0] ^ m;
        cout << "\n LFSR initialization done.......";
    }

    void LFSR::initialization_mood(int F)
    {
        v=this->concatenate_last(s[0],0x00) ^ MUL((s[0] & 0xFF000000)>>24) ^ s[2] ^ this->concatenate_first(s[11],0x00) ^ DIV(s[11]&0xFF) ^ F;
        s[0]=s[1];
        s[1]=s[2];
        s[2]=s[3];
        s[3]=s[4];
        s[4]=s[5];
        s[5]=s[6];
        s[6]=s[7];
        s[7]=s[8];
        s[8]=s[9];
        s[9]=s[10];
        s[10]=s[11];
        s[11]=s[12];
        s[12]=s[13];
        s[13]=s[14];
        s[14]=s[15];
        s[15]=v;

        cout << "\n LFSR initialization Mode done.......";

    }

void LFSR::key_mood()
    {
        v=this->concatenate_last(s[0],0x00) ^ MUL((s[0] & 0xFF000000)>>24) ^ s[2] ^ this->concatenate_first(s[11],0x00) ^ DIV(s[11]&0xFF);
        s[0]=s[1];
        s[1]=s[2];
        s[2]=s[3];
        s[3]=s[4];
        s[4]=s[5];
        s[5]=s[6];
        s[6]=s[7];
        s[7]=s[8];
        s[8]=s[9];
        s[9]=s[10];
        s[10]=s[11];
        s[11]=s[12];
        s[12]=s[13];
        s[13]=s[14];
        s[14]=s[15];
        s[15]=v;
        cout << "\n LFSR keystream Mode done.......";

    }



int LFSR::concatenate_last(int a, int b) //concatenate at last
{
    return ((a<<8)|b);
}

int LFSR::concatenate_first(int a, int b) //concatenate at first
{
    return (b|a>>8);
}
