/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int min, int max)
{
    if (values[min] == value || values[max] == value)
    {
        return true;
    }
    else if (min == max && values[min] != value)
    {
        return false;
    }

    int midpoint = (min + max) / 2;

    if (values[midpoint] == value)
    {
        return true;
    }
    else if (value < values[midpoint])
    {
        return search(value, values, min, midpoint);
    }
    else
    {
        return search(value, values, midpoint + 1, max);
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int element = values[i];
        while (j > 0 && values[j - 1] > element)
        {
            values[j] = values[j - 1];
            j = j - 1;
        }
        if (j != i)
        {
            values[j] = element;
        }
    }
    return;
}