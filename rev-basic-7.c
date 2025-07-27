#include <stdio.h>

unsigned char in[] = {
    0x52, 0xDF, 0xB3, 0x60, 0xF1, 0x8B, 0x1C, 0xB5, 0x57, 0xD1, 
    0x9F, 0x38, 0x4B, 0x29, 0xD9, 0x26, 0x7F, 0xC9, 0xA3, 0xE9, 
    0x53, 0x18, 0x4F, 0xB8, 0x6A, 0xCB, 0x87, 0x58, 0x5B, 0x39, 
    0x1E, 0x00 
};

#define ROR8(x,y) ((unsigned)(x) >> (y)) | ((unsigned)(x) << (8 - (y)))       


int main()
{
    unsigned char i;
    unsigned char out[1024] = {0, };

    for (i = 0; i < sizeof(in); i++)
    {
        
        out[i] = ((unsigned char)(in[i] ^ i) >> (unsigned char)(i & 0x07)) |
                    ((unsigned char)(in[i] ^ i) << (0x08 - (unsigned char)(i & 0x07)));
        // same as
        // #define ROR8(x,y) (x >> y) | (x << (8 - y))       
        // out[i] = ROR8(in[i] ^ i, i & 0x07);

        printf("[%x] [%x] [%x] [%x]\n", 
            out[i], (unsigned char)(in[i] ^ i), (unsigned char)(i & 0x07), (unsigned char)(in[i] ^ i) & 0x01);

    }

    printf("%s\n", out);

    return 0;
}

