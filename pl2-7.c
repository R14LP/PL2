#include <stdio.h>

int Biggest(int array[], int n)
{
    if(n == 1)
        return array[0];

    int biggest = Biggest(array, n - 1);

    return (array[n-1] > biggest) ? array[n-1] : biggest;
}

int main()
{
    int n;
    printf("give the array size:\n");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("give the %d. entry:\n", i + 1);
        scanf("%d", &array[i]);
    }
    printf("the biggest number on the array:%d", Biggest(array, n));
    return 0;
}