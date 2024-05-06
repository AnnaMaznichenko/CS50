#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int wm = get_int("Сколько минут вы используете воду?");
    if(wm>=0)
    {
       printf("Количество бутылок: %i\n", wm*12);
    }
    else
    {
        printf("Введенные данные неокрректны.");
    }
}
