#include <stdio.h>

int astrlen(char *);
char *astrcmp(char *, char *);

int main()
{
    char word1[100],word2[100];

    printf("1.stringi ver: ");
    fgets(word1, 100, stdin);

    printf("\n2.stringi ver: ");
    fgets(word2, 100, stdin);

    printf("\nequality: %s", astrcmp(word1, word2));
    
    return 0;
}

int astrlen(char *word)
{
    int len = 0;
    while (word[len] != '\n' && word[len] != '\0')
    {
        len++;
    }
    return len;
}

char *astrcmp(char *word1, char *word2)
{
    int n1 = astrlen(word1);
    int n2 = astrlen(word2);

    if(n2 != n1)
        return "not equal";

    for (int i = 0; i < n2; i++)
    {
        if((word1[i] - word2[i]) != 0)
            return "not equal";
    }
    return "equal";
}