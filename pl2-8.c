#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char str[], int sol, int sag)
{
    if(sol >= sag)
        return true;

    if(str[sol] != str[sag])
        return false;

    return isPalindrome(str, sol + 1, sag - 1);

}

int main()
{
    int length;
    printf("kelimenin uzunlugunu girin: ");
    scanf("%d", &length);

    char word[length + 1];

    printf("kelimeyi girin:\n");
    scanf("%s", word);

    if(isPalindrome(word, 0, length - 1))
    {
        printf("'%s' bir palindromdur.\n", word);
    }else
    {
        printf("'%s' bir palindrom degildir.\n", word);
    }
    return 0;
}