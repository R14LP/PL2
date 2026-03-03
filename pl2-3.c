#include <stdio.h>

int Sum(int);

int main()
{
    int number;
    printf("give a number to see the sum of the sequence:");
    scanf("%d", &number);
    printf("sum=%d", Sum(number));
    return 0;
}

int Sum(int number)
{
    if (number == 1)
        return 1;
    return number + Sum(number - 1);
}