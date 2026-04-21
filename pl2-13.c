#include <stdio.h>
#include <ctype.h>

char *Upper(char *);

int main()
{
    char word[100];

    printf("stringi ver: ");
    fgets(word, 100, stdin);
    Upper(word);
    printf("\nbuyutme sonrasi: %s", word);
    return 0;
}

char *Upper(char *word)
{
    int i = 0;

    word[i] = toupper(word[i]);

    while(word[i] != '\n' && word[i] != '\0')
    {
        if(word[i] == 32)
            word[i + 1] = toupper(word[i + 1]);
        i++;
    }
    return word;
}