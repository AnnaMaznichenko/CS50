#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int sigma(int n);

int main()
{
    int n = get_int("Enter a positive integer: ");
    printf("%d", sigma(n));
}

int sigma(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + sigma(n - 1);
}