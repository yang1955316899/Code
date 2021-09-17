#include <reg51.h>
#include <math.h>
#include <intrins.h>
#define LED P1
void delay(int time) {
    int x, y;
    for(x = time; x > 0 ; x--)
        for(y = 120; y > 0 ; y--);
}
int change(int number[])
{
    int index, sum = 0;
    for (index = 0; index <= 6; index++)
    {

        sum += pow(number[index] * 2, 7 - index);

    }
    return sum + number[7];
}

main() {
    int tem, i, x, y, action[8];
    for(i = 0; i <= 7 ; i++) {
        action[i] = 1;
    }
    while(1)
    {
        LED = 0x00;
        delay(10);
        LED = 0xff;
        delay(10);
        LED = 0x00;
        delay(10);
        LED = 0xff;
        delay(10);
        for (tem = 0; tem <= 7; tem++)
        {
            LED = ~(1 << tem);
            delay(50);
        }
        for (tem = 7; tem >= 0; tem--)
        {
            LED = ~(1 << tem);
            delay(50);
        }

        for (x = 7; x >= 0; x--)
        {
            for (y = 0; y < x; y++)
            {
                action[y] = 0;
                LED = change(action);
                delay(100);
                action[y] = 1;
                LED = change(action);
                delay(100);
            }
            action[x] = 0;
        }
    }
}