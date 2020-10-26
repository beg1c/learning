#include <stdio.h>
#include <cs50.h>
#include <string.h>

int letter_number();

int main(void)
{
    string text = get_string("Enter text: \n");
    int letters = 0;
    int words = 1;    //starts at 1 because there is no SPACE at beginning of first sentence
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        int letter = text[i];
        if (letter > 65 && letter < 123)
        {
            letters++;
        }
        else if (letter == 32)
        {
            words++;
        }
        else if (letter == 46 || letter == 63 || letter == 33)
        {
            sentences++;
        }
    }

    //calculates index
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //prints index
    if (index < 1)
    {
        printf("Before grade 1\n");
    }
    else if(index < 16)
    {
        printf("Grade %i\n", (int)index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
