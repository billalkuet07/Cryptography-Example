
#ifndef MY_HEADER
#define MY_HEADER
 int mul_x(int, int);
 int mul_y(int,int,int);
 int SR(int);
 int SQ(int);
 int Sbox1(int);
 int Sbox2(int);
 int MUL(int);
 int DIV(int);

 class LFSR {

public:
    int k[],in_it[],v,m,s[15];
    LFSR (int k1[], int init[]);
    void initialization_mood(int F);
    void key_mood();

    int concatenate_last(int a, int b);
    int concatenate_first(int a, int b);
};


class FSM{

public:
    int r1,r2,r3;
    FSM ();
    int calculate_F(int s15, int s5);
    int modulo(int a, int b);
};

#endif
