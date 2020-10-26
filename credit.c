#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    //credit card
    long credit_number;
    do
    {
        credit_number = get_long("Enter your credit card number: \n");
    }
    while(credit_number < 0);
    //luhn
    long modulo = 10;
    long divider = 1;
    int counter = 1;
    int luhn_sum = 0;
    for (int n = 0; n < 16; n++)
    {
        long digit = (credit_number % modulo) / divider;
        modulo *= 10;
        divider *= 10;
        if (counter % 2 == 0)
        {
            int double_digit = digit * 2;
            if (double_digit > 9)
            {
                luhn_sum += 1;
                luhn_sum += double_digit % 10;
                counter++;
            }
            else
            {
                luhn_sum += double_digit;
                counter++;
            }
        }
        else
        {
            luhn_sum += digit;
            counter++;
        }
    }
    //implement function to raise to expontent later
    int american = credit_number/10000000000000 == 34 || credit_number/10000000000000 == 37; 
    int master_card = credit_number/100000000000000 == 51 || credit_number/100000000000000 == 52 || credit_number/100000000000000 == 53 || credit_number/100000000000000 == 54 || credit_number/100000000000000 == 55;
    int visa = credit_number/1000000000000 == 4 || credit_number/1000000000000000 == 4;

    if (luhn_sum % 10 == 0 && american == true)
    {
        printf("American\n");
    }
    else if (luhn_sum % 10 == 0 && master_card == true)
    {
        printf("MasterCard\n");
    }
    else if (luhn_sum % 10 == 0 && visa == true)
    {
        printf("Visa\n");
    }
    else
    {
        printf("Invalid\n");
    }
}

