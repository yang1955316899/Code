#include <stdio.h>
int main()
{
    int number[4][4] = {18,9,11,23,34,7,43,26,6,28,14,37},max = -100,temp_x,temp_y;
    for (int x = 0; x < 4; x++) 
    {
        for (int y = 0; y < 4; y++)
        {
            if (number[x][y] > max)
            {
                max = number[x][y];
                temp_x = x;temp_y = y;                
            }
        }
    }
    printf("���������ǣ�%d�ڣ�%d��%d����",max,temp_x,temp_y);
}