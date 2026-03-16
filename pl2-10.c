#include <stdio.h>

int pascal(int i, int j) {
    if (j == 0 || j == i)
        return 1;
    return pascal(i - 1, j - 1) + pascal(i - 1, j);
}

int main() {
    int row;
    printf("how many rows u want: ");
    scanf("%d", &row);

    for (int i = 0; i < row; i++) 
    {
        for (int space = 0; space < row - i - 1; space++) 
        {
            printf("  ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%4d", pascal(i, j));
        }
        printf("\n");
    }
    return 0;
}