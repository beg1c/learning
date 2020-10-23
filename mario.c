#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //height input
    int h;
    do
    {
        h = get_int("Please enter desired pyramid heigth: \n");
    }
    while (h < 1 || h > 80);
  
    //pyramid print
    int z;
    for (z = 0; z < h; z++)
    {
        int e;
        for(e = 0; e < (h - (z + 1)); e++)
        {
            printf(" ");
        }
        int lj;
        for(lj = 0; lj < (1 + z); lj++)
        {
            printf("#");
        }
        int space;
        for (space = 0; space < 2; space++)
        {
            printf(" ");
        }
        int zwei;
        for(zwei = 0; zwei < (z + 1); zwei++)
        {
            printf("#");
        }
        printf("\n");
    }
}