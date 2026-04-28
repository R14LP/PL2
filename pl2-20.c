#include <stdio.h>

int main()
{
    char array[3][3] = {{'A', 'D', 'G'}, {'B', 'E', 'H'}, {'C', 'F', 'I'}};
    int c, number, satir, sutun;

    printf("kac harf olacak: ");
    scanf("%d", &c);

    char sonuc[c + 1];

    for (int i = 0; i < c; i++)
    {
        printf("\n%d. harfe denk gelen sifreyi gir: ", i + 1);
        scanf("%d", &number);

        satir = number / 10;
        sutun = number % 10;

        sonuc[i] = array[satir - 1][sutun - 1];
    }

    sonuc[c] = '\0';

    printf("\nverilen sifrenin cozumlenmis hali: %s", sonuc);
    return 0;
}