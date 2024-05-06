/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Если количество аргументов командной строки не равно 2 или 3,
    // сообщить, что программа ожидает один или два аргумента командной строки.
    // Возвратить значение 1.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // В переменную n типа int поместить количество псевдослучайных чисел.
    int n = atoi(argv[1]);

    // Если количество аргументов командной строки равно 3, вызвать функцию srand48,
    // используя в качестве семени третий аргумент командной строки, приведенный к типу int, затем к типу long int.
    // Иначе вызвать функцию srand48, используя в качестве семени значение функции time, приведенное к типу int.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Пока значение переменной i меньше переменной n, выводить значение функции drand48,
    // ограниченное константой LIMIT и приведенное к типу int.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}