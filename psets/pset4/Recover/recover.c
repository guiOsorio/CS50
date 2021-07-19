// recovers deleted files

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 512

typedef uint8_t BYTE;

int is_start_of_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    FILE *infile = fopen(argv[1], "r");
    if(argv[1] == NULL)
    {
        printf("Usage: ./recover file_to_recover \n");
        return 1;
    }

    BYTE buffer[BUFFER_SIZE];
    int was_first_jpeg_found = 0;
    FILE *image = NULL;
    int file_count = 0;

    while(fread(buffer, BUFFER_SIZE, 1, infile))
    {
        if(is_start_of_jpeg(buffer))
        {
            if(!was_first_jpeg_found)
            {
                was_first_jpeg_found = 1;
            }
            else
            {
                fclose(image);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", file_count);
            image = fopen(filename, "w");
            file_count++;
        }

        if(was_first_jpeg_found)
        {
            fwrite(&buffer, BUFFER_SIZE, 1, image);
        }
    }

    fclose(image);
    fclose(infile);
}

int is_start_of_jpeg(BYTE buffer[])
{
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }

    return 0;
}
