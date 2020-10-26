#include <stdio.h>
#include <string.h>
#include <cs50.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score();

int main(void)
{
    //get words
    string word1 = get_string("Player 1: \n");
    string word2 = get_string("Player 2: \n");

    //score words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //print winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Even!\n");
    }
}

int compute_score(string word)
{
    int word_score = 0;
    for (int i = 0; i < strlen(word); i++) //takes ascii nr, checks if upper/lower case, subtract to zero, adds to score
    {
        int ascii_dec = word[i];
        if (ascii_dec < 97)
        {
            word_score += POINTS[ascii_dec - 65];
        }
        else
        {
            word_score += POINTS[ascii_dec - 97];
        }
    }
    return word_score;
}