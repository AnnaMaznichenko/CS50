#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int array[5] = {2, 3, 5, 6, 4};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int element = array[i];
        while (j > 0 && array[j - 1] > element)
        {
            array[j] = array[j - 1];
            j = j - 1;
        }
        if (j != i)
        {
            array[j] = element;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%u ", array[i]);
    }
}