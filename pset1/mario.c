 #include <stdio.h>
#include <cs50.h>
int main(void)
{
    int n;
    do
    {
        n = get_int("Назовите число от 1 до 23: ");
        if (n > 0 && n < 24)
        {
            for (int i = 0; i < n; i++)
                {
                    for (int s = 0; s < n - 1 - i; s++)
                    {
                        printf(" ");
                    }
                    for (int h = 0; h < i + 2; h++)
                    {
                        printf("#");
                    }
                    printf("\n");
                }
        }
        else
        {
            printf("Введенные данные некорректны.\n");
        }
    }
    while (n < 1 || n > 23);
}