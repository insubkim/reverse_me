#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

unsigned char out[33] = {
    0XF8,                 
    0XE0,
    0XE6,
    0X9E,
    0X7F ,
    0X32 ,
    0X68 ,
    0X31 ,
    0X5,
    0XDC,
    0XA1,
    0XAA,
    0XAA,
    0X9,
    0XB3,
    0XD8,
    0X41 ,
    0XF0,
    0X36 ,
    0X8C,
    0XCE,
    0XC7,
    0XAC,
    0X66 ,
    0X91,
    0X4C ,
    0X32 ,
    0XFF,
    0X5,
    0XE0,
    0XD9,
    0X91,
    0
};

unsigned char c_402068[5] = {
    0XDE,                
    0XAD,
    0XBE,
    0XEF,
    0
};

unsigned char c_40206D[5] = {
    0XEF,                 
    0XBE,
    0XAD,
    0XDE,
    0
};

unsigned char c_402072[8] = {
    0x11,                
    0x33, 
    0x55, 
    0x77, 
    0x99,
    0xBB,
    0xDD,
    0
};


int v4;

void sub_401263(unsigned char a1, unsigned char *a2)
{
  unsigned char result[33] = {0,}; // rax
  unsigned char *tmp= 0; // rax
  int i; // [rsp+14h] [rbp-Ch]

  for ( i = 0; i <= 31; ++i )
  {
    *(result+i) = *(a2) - a1;
  }
  memcpy(a2, result, 33);
}

void sub_4012B0(unsigned char a1, unsigned char* a2)
{
  unsigned char result[33] = {0,}; // rax
  unsigned char *tmp= 0; // rax
  int i; // [rsp+14h] [rbp-Ch]
  unsigned int v4; // [rsp+18h] [rbp-8h]

  v4 = strlen((char*)a2);
  for ( i = 0; i <= 31; ++i )
  {
    tmp = (unsigned char *)(i + a1);
    *(result+i) ^= *(i % v4 + a2);
  }
  memcpy(a2, result, 33);
}

void sub_4011EF(unsigned char* a1, unsigned char* a2)
{
  unsigned char result[33] = {0,}; // rax
  unsigned char *tmp= 0; // rax
  int i; // [rsp+14h] [rbp-Ch]
  unsigned int v4; // [rsp+18h] [rbp-8h]

  v4 = strlen((char*)a2);
  for ( i = 0; i <= 31; ++i )
  {
    tmp = (unsigned char *)(i + a1);
    *(result+i) ^= *(i % v4 + a2);
  }
  memcpy(a2, result, 33);
}

void sub_4011EF(unsigned char *i, unsigned char *o);
void sub_401263(unsigned char i, unsigned char *o);
void sub_4012B0(unsigned char i, unsigned char *o);

int main()
{
    sub_4011EF(c_402072, out);
    sub_401263(0xF3, out);
    sub_4012B0(0x4D, out);
    sub_4011EF(c_40206D, out);
    sub_4012B0(0X5A, out);
    sub_401263(0x1F, out);
    sub_4011EF(c_402068, out);
    cout << out << endl;
}
