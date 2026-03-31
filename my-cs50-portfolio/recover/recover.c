#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;
int main(int argc, char *argv[])
{

    if(argc != 2)
    {
        printf("usage : ./recover FILE\n");
        return 1;
    }

    FILE* card = fopen(argv[1],"r");
    if(card == NULL)
    {
        printf("card could not be opened");
        return 1;
    }

    BYTE buffer[512];


    char* file = malloc(8);
    int k = 0;
    FILE *img = NULL;
    int bytesread;

    while(fread(buffer,1,512,card))
    {

        if(buffer[0] == 0xff && buffer [1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
             if(img != NULL)
             {
                fclose(img);

             }
                k++;
                sprintf(file,"%03i.jpg",k-1);
                img = fopen(file,"w");



        }
        if(img != NULL && k >0)
        {
            for(int l = 0; l < 512 ; l+= 512)
            {
                   fwrite(&buffer[l],1,512,img);
            }

        }

    }



    free(file);
    fclose(card);
    if(img != NULL)
    {
        fclose(img);
    }


}

