#include <stdio.h>
#include <string.h>

unsigned char s[1024] = 
{0X74,
0X78,
0X4B,
0X65,
0X77,
0X48,
0X5C,
0X69,
0X68,
0X7E,
0X5C,
0X79,
0X77,
0X62,
0X46,
0X79,
0X77,
0X5,
0X46,
0X54,
0X73,
0X72,
0X59,
0X69,
0X68,
0X7E,
0X5C,
0X7E,
0X5A,
0X61,
0X57,
0X6A,
0X77,
0X66,
0X5A,
0X52,
0X2,
0X62,
0X5C,
0X79,
0X77,
0X5C,
0X0, 
0x7C, 0x57, 0x0D, 0x0D, 0x4D};

int main()
{
    unsigned char len = 48;
    unsigned char key[1024] = {0,};

    unsigned char ecx = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        // key[i] = (unsigned char)len ^ (unsigned char)((unsigned char)ecx ^ (unsigned char)s[i]); 
        key[i] = (unsigned char)len ^ (unsigned char)( (unsigned char)s[i]); 
    }
    printf("%s\n", key);
    printf("%d\n", len);
}