ды/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>

const unsigned char FIRST_BITES[3] = {(char)0xff, (char)0xd8, (char)0xff};
const int BUFF_SIZE = 512;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    char* infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    FILE *outptr = NULL;

    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    char jpgName = 0;
    unsigned char buff[BUFF_SIZE];
    int count = 0;
    int readBites = 0;

    while((readBites = fread(&buff, sizeof(char), BUFF_SIZE, inptr)))
    {
        if(buff[0] == FIRST_BITES[0] && buff[1] == FIRST_BITES[1] && buff[2] == FIRST_BITES[2])
        {
            sprintf(&jpgName, "%03d.jpg", ++count);
            outptr = fopen(&jpgName, "w");
        }

        if(outptr != NULL)
        {
            fwrite(&buff, sizeof(char), BUFF_SIZE, outptr);
        }

        if(readBites < BUFF_SIZE)
        {
            break;
        }
    }
}
