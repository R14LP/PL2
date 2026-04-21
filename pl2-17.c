#include <stdio.h>

char *astrrev(char *);

int main()
{
    char word[100];

    printf("stringi ver: ");
    fgets(word, 100, stdin);

    astrrev(word);

    printf("\ntersten: %s", word);
    return 0;
}

char *astrrev(char *word)
{
    int len = 0;
    char temp;

    while(word[len] != '\0' && word[len] != '\n')
    {
        len++;
    }

    int start = 0;
    int end = len - 1;

    while(start < end)
    {
        temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        
        end--;
        start++;
    }
    return word;
}