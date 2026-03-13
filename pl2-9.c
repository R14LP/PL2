#include <stdio.h>

int Fibonacci(int number)
{
    if(number == 0 || number == 1)
        return 1;
    return Fibonacci(number - 1) + Fibonacci(number - 2);
}

int main()
{
    int number;
    printf("kac adim gormek istersin: ");
    scanf("%d", &number);
    for(int i = 0; i < number; i++) {
        printf("%d ", Fibonacci(i));
    }

    return 0;
}