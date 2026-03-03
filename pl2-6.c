#include <stdio.h>


int Smallest(int array[], int n)
{
    if(n == 1)
        return array[0];

    int min = Smallest(array, n - 1);

    return (array[n - 1] < min) ? array[n - 1] : min;
}

int main()
{
    int n;
    printf("how many entries:\n");
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("enter the %d. number:\n", i + 1);
        scanf("%d", &array[i]);
    }

    printf("smallest number in the array:\n%d", Smallest(array, n));
    return 0;
}