#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

string cipher(string key, string plaintext);
bool is_digit(string s);
bool not_unique(string l);


int main(int argc, string argv[])
{


    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check if the characters are unique
    if (not_unique(argv[1]))
    {
        printf("Key must contain unique characters.\n");
        return 1;
    }

    if (is_digit(argv[1]))
    {
        string plaintext = get_string("plaintext:  ");

        printf("ciphertext:  %s\n", cipher(argv[1], plaintext));
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key!\n");
        return 1;
    }

}

string cipher(string key, string plaintext)
{
    int index;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]))
        {
            index = plaintext[i] - 'a';
            plaintext[i] = tolower(key[index]);
        }
        else if (isupper(plaintext[i]))
        {
            index = plaintext[i] - 'A';
            plaintext[i] = key[index];
        }

    }
    return plaintext;
}



bool is_digit(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) != 0)
        {
            return false;
        }
    }
    return true;
}

bool not_unique(string l)
{
    for (int i = 0, n = strlen(l); i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (toupper(l[i]) == toupper(l[j]))
            {
                return true;
            }
        }
    }
    return false;
}