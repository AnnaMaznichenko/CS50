#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int array[4] = {8, 6, 4, 2};
    int counter;
    do
    {
        counter = 0;
        for (int i = 0, n = 4; i < n - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                counter++;
                printf("%u %u %u %u\n", array[0], array[1], array[2], array[3]);
            }
        }
    }
    while (counter > 0);
    printf("%u %u %u %u", array[0], array[1], array[2], array[3]);
}