#include <stdio.h>
#include <cs50.h>

// To compile CS50 library in C, use clang -o name name.c -lcs50


int main(void)
{

    // prompt user asking for their card number

    long int card;
    int A, B, tot;
    int sumA = 0 , sumB = 0;
    int count = 2;

    



    do
    {
        card = get_long("Please enter your card number: ");
    }
    while(card <= 0);

    int long tmp_card = card;
    
    while (card != 0)
    {
        if (count % 2 == 0)
        {
            A = card % 10;
            sumA = sumA + A;
        }
        card = card / 10;
        count ++;
    } 

    count = 2;

    

    while (tmp_card != 0)
    {
        if (count % 2 != 0)
        {
            B = 2 * (tmp_card % 10);
            if (B / 10 != 0)
            {
                B = B / 10 + B % 10;
            }

            sumB = sumB + B;
        }
        tmp_card = tmp_card / 10;
        count ++;
    }

    tot = sumB + sumA;

    if (tot % 10 == 0)
    {
        printf("This card is VALID!\n");
    }
    else
    {
        printf("This card is INVALID!\n");
    }


}