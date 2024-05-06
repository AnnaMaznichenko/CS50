#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
    string name = get_string("Введите имя\n");
    int len = strlen(name);
    bool wordBegin = true;
    for (int i = 0; i < len; i++)
    {
        if (wordBegin == true)
        {
            if (name[i] >= 97 && name[i] <= 122)
            {
                printf("%c", name[i] - 32);
            }
            else if (name[i] >= 65 && name[i] <= 90)
            {
                printf("%c", name[i]);
            }
            else
            {
                continue;
            }
            wordBegin = false;
        }
        else if (name[i] == 32)
        {
            wordBegin = true;
        }
    }
}

