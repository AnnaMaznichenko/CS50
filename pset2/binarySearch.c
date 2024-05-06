#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

bool search(int n, int array[], int lower, int upper);
int size;

int main()
{
    int array[8] = {1, 2, 3, 5, 6, 7, 9, 10};
    size = sizeof(array) / sizeof(array[0]);
    int n = get_int("Enter a integer from 1 to 10: ");
    if (n < 1 || n > 10)
    {
        printf("Integer is not valid.");

    }

    if (search(n, array, 0, size))
    {
        printf("Integer found!");
    }
    else
    {
        printf("Integer not found!");
    }
}

bool search(int n, int array[], int lower, int upper)
{
    if (array[lower] == n || array[upper] == n)
    {
        return true;
    }
    else if (array[lower] == array[upper] && array[lower] != n)
    {
        return false;
    }

    int midpoint = (lower + upper) / 2;

    if (array[midpoint] == n)
    {
         return true;
    }
    else if (n < midpoint)
    {
        return search(n, array, 0, midpoint);
    }
    else
    {
        return search(n, array, midpoint + 1, size);
    }
}