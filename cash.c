#include <cs50.h>
#include <stdio.h>


// To compile CS50 library in C, use clang -o name name.c -lcs50
// a greedy algorithm is one “that always takes the best immediate, or local,
// solution while finding an answer. Greedy algorithms find the overall, or
// globally, optimal solution for some optimization problems, but may find
// less-than-optimal solutions for some instances of other problems.”

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int c;
    // prompt user for number of cents
    do
    {
        c = get_int("How many cents do you owe:");
    }
    while (c < 0);
    return c;
}

int calculate_quarters(int cents)
{
    // calcuate number of quarters
    int q = cents / 25;
    return q;
}

int calculate_dimes(int cents)
{
    // calcuate number of dimes
    int d = cents / 10;
    return d;
}

int calculate_nickels(int cents)
{
    // calcuate number of nickels
    int n = cents / 5;
    return n;
}

int calculate_pennies(int cents)
{
    // calcuate number of pennies
    int p = cents / 1;
    return p;
}
