#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

string cipher(int key, string plaintext);
bool is_digit(string s);

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Please provide the key!\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Please provide only one key!\n");
        return 1;
    }


    if (is_digit(argv[1]))
    {
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext:  ");

        printf("ciphertext:  %s\n", cipher(key, plaintext));
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key!\n");
        return 1;
    }
}


string cipher(int key, string plaintext)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]))
        {
            plaintext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        }
        else if (isupper(plaintext[i]))
        {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
    }

    return plaintext;
}


bool is_digit(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}