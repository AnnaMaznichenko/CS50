#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
    {
        int array[5] = {2, 5, 4, 7, 3};
        for (int i = 0, n = 5; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (array[j] < array[min])
                {
                    min = j;
                }
            }
            if (min != i)
                {
                    int tmp = array[i];
                    array[i] = array[min];
                    array[min] = tmp;
                }
        }
        printf("%u %u %u %u %u", array[0], array[1], array[2], array[3], array[4]);
    }