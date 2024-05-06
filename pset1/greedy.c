#include <stdio.h>
#include <cs50.h>
int main(void)
{
    float n;
    int coins = 0;
    int coin25 = 25;
    int coin10 = 10;
    int coin5 = 5;
    int coin1 = 1;
    int currentcoins;
    while (true)
    {
        n = get_float("Назовите сумму сдачи: ");
        int cent = n * 100;
        if (cent < coin1)
        {
            printf("Введенные данные некорректны.\n");
            continue;
        }
        if (cent >= coin25)
        {
           currentcoins = cent / coin25;
           coins = coins + currentcoins;
           cent = cent - (currentcoins * coin25);
        }
        if (cent >= coin10)
        {
            currentcoins = cent / coin10;
            coins = coins + currentcoins;
            cent = cent - (currentcoins * coin10);
        }
        if (cent >= coin5)
        {
            currentcoins = cent / coin5;
            coins = coins + currentcoins;
            cent = cent - (currentcoins * coin5);
        }
        if (cent >= coin1)
        {
            currentcoins = cent / coin1;
            coins = coins + currentcoins;
            cent = cent - (currentcoins * coin1);
        }
        printf("Результат: %d\n", coins);
        break;
    }
}