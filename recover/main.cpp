#include <iostream>
#include <stdio.h>

using namespace std;

/*
.rodata:0000000000002004 unk_2004        db 0DEh                 ; DATA XREF: main+1B↑o
.rodata:0000000000002005                 db 0ADh
.rodata:0000000000002006                 db 0BEh
.rodata:0000000000002007                 db 0EFh

*/

unsigned salt[5] = {
    0xDE,
    0xAD,
    0xBE,
    0xEF
};

/*
while ( fread(&ptr, 1u, 1u, stream) == 1 )
  {
    ptr ^= v6[v5 % 4];
    ptr += 19;
    fwrite(&ptr, 1u, 1u, s);
    ++v5;
  }

*/

int main()
{
    // read encrypted
    FILE *enc = fopen("encrypted", "rb");
    FILE *dec = fopen("dec", "wb");

    if (!enc || !dec)
    {   
        cout << "fail" << endl;
        return 0;
    }

    // decrypt
    // write flag
    unsigned char buf;
    int i = 0;
    while (fread(&buf, 1, 1, enc) == 1)
    {
        buf -= (unsigned char)19;
        buf ^= salt[i % 4];
        i++;
        fwrite(&buf, 1, 1, dec);
    }
        cout << "done" << endl;
}