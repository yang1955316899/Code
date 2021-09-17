#include <reg51.h>
void delay_ms(int x)
{
    int i, j;
    for (i = 0; i < x; i++)
        for (j = 0; j < 600; j++)
            ;
}
void port_init(void)
{
    P0 = 0XFF;
    P1 = 0XFF;
    P2 = 0XFF;
    P3 = 0XFF;
}
void main(void)
{
    unsigned char i;
    port_init();
    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            P0 = ~(1 << i);
            delay_ms(200);
        }
        P0 = 0X00;
        delay_ms(200);
        P0 = 0XFF;
        for (i = 0; i < 8; i++)
        {
            P1 = ~(1 << i);
            delay_ms(200);
        }
        P1 = 0X00;
        delay_ms(200);
        P1 = 0XFF;
        for (i = 0; i < 8; i++)
        {
            P2 = ~(1 << i);
            delay_ms(200);
        }
        P2 = 0X00;
        delay_ms(200);
        P2 = 0XFF;
        for (i = 0; i < 8; i++)
        {
            P3 = ~(1 << i);
            delay_ms(200);
        }
        P3 = 0X00;
        delay_ms(200);
        P3 = 0XFF;
    }
}
