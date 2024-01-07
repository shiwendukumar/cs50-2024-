/*
TODO
- Prompt for input
- Calculate checksum
    - Multiply every other digit by 2, starting from second to last digit.
    - Add those products digits together
    - Add the sum to the sum of the digits that weren't multiplied by 2
    - If the total's last digit is 0, number is valid!
- Check for card length and starting digits
- Print AMEX, MASTERCARD, VISA or INVALID
    Example - 4003600000000014
*/
#include <cs50.h>
#include <stdio.h>

int checksum(long long cardnum);
int length(long long num);
void cardname(int num2, long long input);

int main(void)
{
    // prompting for credit card number
    long long card = get_long("Number: ");

    if (checksum(card))
    {
        int credit = length(card);
        cardname(credit, card);
    }

    else
    {
        printf("INVALID\n");
    }
}

int checksum(long long cardnum)
{
    // declaring variables
    int formula;
    int sum1 = 0;
    int sum2 = 0;

     // checksum
    while (cardnum > 0) //4003600000000014
    {
        // calculation 1
        formula = (cardnum / 10) % 10;
        formula *= 2;
        if (formula > 9)
        {
           sum1 += (formula / 10) % 10;
           sum1 += formula % 10;
        }
        else
        {
            sum1 += formula;
        }

        // calculation 2
        sum2 += cardnum % 10;

        cardnum /= 100;
    }

    if ((sum1 + sum2) % 10 == 0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int length(long long num)
{
    int i;
    for (i = 0; num > 0; i++)
    {
        num /= 10;
    }
    return i;
}

void cardname(int num2, long long input)
{
    if (num2 == 15)
    {
        if (input / 10000000000000 == 34 || input / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else if (num2 == 16)
    {
        if (input / 100000000000000 == 51 || input / 100000000000000 == 52 || input / 100000000000000 == 53 || input / 100000000000000 == 54 || input / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }

        else if (input / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else if (num2 == 13)
    {
        if (input / 1000000000000 == 4)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}
