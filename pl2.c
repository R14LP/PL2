#include <stdio.h>

void Instructures();

void Table();

int Times, Number;

int main()
{
    Instructures();
    Table();
    return 0;
}

void Instructures()
{
    printf("How many numbers u want?\n");
    scanf("%d", &Number);
    
    printf("How many times do u want to see the numbers power?\n");
    scanf("%d", &Times);
}

void Table()
{
    int result;

    printf("Number |");

    for (int j = 1; j <= Times; j++)
    {
        printf(" Power %d", j);
    }

    printf("\n");
    printf("--------");

    for (int j = 1; j <= Times; j++)
    {
        printf("--------");
    }

    printf("\n");

    for (int i = 1; i <= Number; i++)
    {
        printf("  %-4d |", i); 
        result = 1;

        for (int j = 1; j <= Times; j++)
        {
            result *= i;
            printf("%8d", result); 
        }
        
        printf("\n");
    }
}