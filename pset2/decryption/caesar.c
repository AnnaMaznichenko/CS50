#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int k = atoi(argv[1]);
    if (argc != 2)
    {
        printf("Должен быть один аргумент\n");
        return 1;
    }
    if (k < 0)
    {
        printf("Ключ должен быть положительным целым числом\n");
        return 1;
    }
    string p = get_string("Введите текст\n");
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isalpha(p[i]))
        {
            int base = 97;
            if (isupper(p[i]))
            {
                base = 65;
            }
            int pos = (p[i] - base + k) % 26;
            printf("%c", base + pos);
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    return 0;
}