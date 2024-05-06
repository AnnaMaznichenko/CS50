/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

const int PIXELBYTESIZE = 3;

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize move infile outfile\n");
        return 1;
    }

    int move = atoi(argv[1]);

    if (move <= 0 || move > 100)
    {
        printf("move must be an integer no greater than 100\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    BITMAPINFOHEADER biInptr;
    BITMAPFILEHEADER bfInptr;

    biInptr.biWidth = bi.biWidth;
    biInptr.biHeight = bi.biHeight;
    biInptr.biSizeImage = bi.biSizeImage;
    bfInptr.bfSize = bf.bfSize;

    bi.biWidth = bi.biWidth * move;
    bi.biHeight = bi.biHeight * move;
    bi.biSizeImage = bi.biWidth * bi.biHeight;
    bf.bfSize = bi.biSizeImage + 54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int rowCount = 0;
    long rowReversion = biInptr.biWidth * PIXELBYTESIZE * -1;

    // iterate over infile's scanlines
    for (int rowIndex = 0, biHeight = abs(bi.biHeight); rowIndex < biHeight; rowIndex++)
    {
        // iterate over pixels in scanline
        for (int columnIndex = 0; columnIndex < biInptr.biWidth; columnIndex++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int columnCount = 0; columnCount < move; columnCount++)
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        // then add it back (to demonstrate how)
        for (int i = 0; i < padding; i++)
        {
            fputc(0x00, outptr);
        }

        rowCount++;

        if (rowCount != move)
        {
            fseek(inptr, rowReversion, SEEK_CUR);
        }
        else
        {
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
            rowCount = 0;
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
