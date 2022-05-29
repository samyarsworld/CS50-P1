#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// We are using coleman-liau formula to assess the readability level of a text

int get_level(string text);


int main(void)
{
    // Prompt user for the text
    char *text = get_string("Please enter your text:\n");

    // Compute the level
    int level = get_level(text);


    // Print out the level
    if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", level);
    }

}





int get_level(string text)
{
    int w_count = 1; // Word count
    int l_count = 0; // Letter count
    int s_count = 0; // Sentence count

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Letter count
        if (text[i] - 'A' <= 26 && text[i] - 'A' >= 0)
        {
            l_count++;
        }
        else if (text[i] - 'a' <= 26 && text[i] - 'a' >= 0)
        {
            l_count++;
        }

        // Word count
        if (text[i] == ' ')
        {
            w_count++;
        }

        // Sentence count
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            s_count++;
        }

    }

    // Compute the average number of letters per 100 words
    float L = 100.0 * (float) l_count / (float) w_count;

    // Compute the average number of sentences per 100 words
    float S = 100.0 * (float) s_count / (float) w_count;

    // The Coleman-Liau index formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}

