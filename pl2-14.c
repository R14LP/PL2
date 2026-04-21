#include <stdio.h>

char *astrcpy(char *, char *);

int main()
{
    char word[100], copyword[100];

    printf("stringi ver: ");
    fgets(word, 100, stdin);

    astrcpy(copyword, word);
    printf("\ncopy: %s", copyword);

    return 0;
}

char *astrcpy(char *copyword, char *word)
{
    int i = 0;
    while (word[i] != '\n' && word[i] != '\0')
    {
        copyword[i] = word[i];
        i++;
    }
    copyword[i] = '\0';
    return copyword;
}