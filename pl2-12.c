#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BubbleSort(char **words, int n)
{
    char temp[100];
    int j, k;

    for (k = 0; k < n - 1; k++)
    {
        for (j = 0; j < n - 1 - k; j++)
        {
            if(strcmp(*(words + j), *(words + (j + 1))) > 0)
            {
                strcpy(temp, *(words + j));
                strcpy(*(words + j), *(words + (j + 1)));
                strcpy(*(words + (j + 1)), temp);
            }
        }
    }
}

int main()
{
    int n, i;
    printf("kac kelime: ");
    scanf("%d", &n);

    char **words = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        *(words + i) = (char *)malloc(100 * sizeof(char));
        printf("\n%d. kelimeyi gir: ", i + 1);
        scanf("\n%s", *(words + i));
    }

    BubbleSort(words, n);

    for (i = 0; i < n; i++)
    {
        printf("%s\n", *(words + i));
        free(*(words + i));
    }
    free(words);
    return 0;
}
