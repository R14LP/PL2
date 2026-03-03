#include <stdio.h>

int EBOB(int x, int y);

int main()
{
    int number1, number2;
    printf("give me 2 numbers to see their EBOB:\n");
    scanf("%d %d", &number1, &number2);
    printf("EBOB(%d,%d):%d", number1, number2, EBOB(number1, number2));
    return 0;
}

int EBOB(int x, int y)
{
    if(y == 0)
        return x;
    return EBOB(y, x % y);
}