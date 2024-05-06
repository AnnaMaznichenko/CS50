#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string k = argv[1];
    int lenk = strlen(k);
    int mod = 1;
    if (argc != 3)
    {
        printf("Необходимо использовать два аргумента\n");
        return 1;
    }
    for (int j = 0; j < lenk; j++)
    {
        if (!isalpha(k[j]))
            {
                printf("Ключ должен состоять из букв латинского алфавита\n");
                return 1;
            }
    }
    if (strcmp(argv[2], "0") == 0)
        {
            mod = -1;
        }
    string p = get_string("Введите текст\n");
    for (int i = 0, s = 0, lenp = strlen(p); i < lenp; i++)
    {
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        s++;
        int kpos = s % lenk;
        if (kpos == 0)
        {
            kpos = lenk;
        }
        kpos = kpos - 1;
        int base = 97;
        int kbase = 97;
        if (isupper(k[kpos]))
        {
            kbase = 65;
        }
        if (isupper(p[i]))
        {
            base = 65;
        }
        int res = (p[i] - base + k[kpos] - kbase) % 26;
        printf("%c", (base + res) * mod);
    }
    return 0;
}