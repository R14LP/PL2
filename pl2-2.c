#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GuessTheNumber();

int main()
{
    GuessTheNumber();
    return 0;
}

void GuessTheNumber()
{
    srand(time(NULL));
    int given_number, random_number = (rand() % 100) + 1;
    
    printf("1-100 arasinda bir tam sayi tuttum 5 denemede tahmin et\n");

    for (int i = 1; i <= 5; i++)
    {
        scanf("%d", &given_number);
        if(given_number == random_number)
        {
            printf("DOGRU! %d. denemede bildin\n", i);
            return;
        }

        if(i == 5)
        {
            printf("Bilemedin! Tuttugum sayi: %d\n", random_number);
        }else
        {
            if (given_number < random_number) 
            {
                printf("Tuttugum sayi daha buyuk\n");
            } 
            else 
            {
                printf("Tuttugum sayi daha kucuk\n");
            }
        }
    }
}