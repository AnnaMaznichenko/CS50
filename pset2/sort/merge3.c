#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void sort(int array[], int start, int end);
void merge(int array[], int start, int middle, int after, int end);

int main()
{
    int array[6] = {3, 5,  2, 6, 4, 1};
    int n = 6;

    sort(array, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%u ", array[i]);
    }
}

void sort(int array[], int start, int end)
{
    if (start == end)
    {
        return;
    }
    if (end > start)
    {
        int middle = (start + end) / 2;
        sort(array, start, middle);
        sort(array, middle + 1, end);
        merge(array, start, middle, middle + 1, end);
    }
}

void merge(int array[], int start, int middle, int after, int end)
{
    int left = start;
    int right = middle + 1;
    int tmp[end + 1];
    int i;

    for (i = 0; i < 6; i++)
    {
        printf("%u ", array[i]);
    }
    printf("\n%u \n", array[left]);
    printf("%u \n\n", array[right]);

    for (i = 0; i <= end; i++)
    {
        if ((array[left] < array[right]) || (right > end))
        {
            tmp[i] = array[left];
            if (start != middle)
            {
                left++;
            }
        }
        else
        {
            tmp[i] = array[right];
            if (end != middle + 1)
            {
                right++;
            }
        }
        printf("%u \n", tmp[i]);
    }
    for (i = 0; i <= end; i++)
    {
        printf("%u ", tmp[i]);
    }
    for (i = 0; i <= end; i++)
    {
        array[i] = tmp[i];
    }
}