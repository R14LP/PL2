#include <stdio.h>

int Power(int, int);

int main()
{
    int number, power;
    printf("give 2 numbers, the first one is the number and the second one is the power:\n");
    scanf("%d %d", &number, &power);
    printf("result:%d", Power(number, power));
    return 0;
}

int Power(int x, int y)
{
    if(y == 0)
        return 1;
    return x * Power(x, y - 1);
}