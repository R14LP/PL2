#include <stdio.h>

int astrlen(char *);

int main()
{
    char word[100];

    printf("stringi ver: ");
    fgets(word, 100, stdin);

    printf("uzunluk: %d", astrlen(word));
    
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