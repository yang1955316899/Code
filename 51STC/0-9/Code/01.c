#include"reg51.h"
#define uchar unsigned char
#define uint unsigned int
uchar code tab[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
delay(uint t)
{
    uint i, j;
    for(j = t; j > 0; j--)
        for(i = 110; i > 0; i--);
}
main()
{
    uint n;
    while(1)
    {   for(n = 0; n < 10; n++)
        {
            P2 = ~tab[n];
            delay(1000);
        }
        for(n = 8; n > 0; n--) {
            P2 = ~tab[n];
            delay(1000);
        }
    }
}