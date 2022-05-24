#include <stdio.h>
#include <cs50.h>

// To compile CS50 library in C, use clang -o name name.c -lcs50

void block(int n);

int main(void)
{
    //prompt user asking for the height of the block

    int n;

    do
    {
        n = get_int("Please type the height of blocks:\n");
    }
    while(n < 1 || n > 8);

    block(n);

}



void block(int n)
{
    for (int row = 0 ; row < n ; row++)
    {
        for (int space = 0 ; space < n - row + 1 ; space++)
        {
            printf(" ");
        }
        
        for (int i = 0 ; i < row + 1 ; i++)
        {
            printf("#");
        }

        printf("  ");

        for (int i = 0 ; i < row + 1 ; i++)
        {
            printf("#");
        }

        printf("\n");
    }
}