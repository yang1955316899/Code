#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define SEG6 P1
sbit K1 = P3 ^ 5;
uchar code DSY_CODE[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x86, 0x87};
uchar code SCAN[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
uchar  DSY_DISP[] = {0x2, 0x0, 0x0, 0x1, 0x1, 0x2, 0x3, 0x1};
void DelayMS(uint ms) //??
{
    uchar i;
    while(ms--) for(i = 0; i < 120; i++);
}

void main()
{   uint i;

    while(1)
    {
        for(i = 0; i < 8; i++)
        {   P2 = SCAN[7 - i];

            SEG6 = ~DSY_CODE[DSY_DISP[i]];
            if(i == 5 || i == 3) {
                SEG6 = ~DSY_CODE[DSY_DISP[i]] + 0x80;
            }
            DelayMS(4);
        }
    }
}