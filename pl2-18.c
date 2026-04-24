#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int number;
    char name[100];
    char surname[100];
    float midtermgrade;
    float finalgrade;
};

void BubbleSort(struct student *students[]);
void SearchbyName(struct student *students[], char *);

int main()
{
    int i;
    struct student *students[5];

    for (i = 0; i < 5; i++)
    {
        students[i] = (struct student *)malloc(sizeof(struct student));

        printf("-------------\n\n%d. ogrenci\n", i+1);
        
        printf("\nnumara: ");
        scanf("%d", &students[i]->number);
        
        printf("\nad: ");
        scanf("%s", students[i]->name);
        
        printf("\nsoyad: ");
        scanf("%s", students[i]->surname);
        
        printf("\nvize notu: ");
        scanf("%f", &students[i]->midtermgrade);
        
        printf("\nfinal notu: ");
        scanf("%f", &students[i]->finalgrade);
    }

    printf("\n\n-------------------");
    printf("Ogrencilerin ortalamasi");
    printf("-------------------\n");

    for (i = 0; i < 5; i++)
    {
        float yilsonu = (students[i]->midtermgrade * 0.4) + (students[i]->finalgrade * 0.6);

        printf("\n%s %s ogrencinin ortalamasi: %.2f", students[i]->name, students[i]->surname, yilsonu);
    }

    printf("\n\n-------------------");
    printf("Isme gore siralanmis liste");
    printf("-------------------\n");

    BubbleSort(students);

    for (i = 0; i < 5; i++)
    {
        printf("%d. %s %s\n", i + 1, students[i]->name, students[i]->surname);
    }

    printf("\n-------------------\n");
    printf("Ogrenci Arama Ekrani\n");
    printf("-------------------\n");

    char arananAd[100];

    printf("aramak istedigin ismi gir: ");
    scanf("%s", arananAd);

    SearchbyName(students ,arananAd);

    for (i = 0; i < 5; i++)
    {
        free(students[i]);
    }

    return 0;
}

void BubbleSort(struct student *students[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if(strcmp(students[j]->name, students[j+1]->name) > 0)
            {
                struct student *temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void SearchbyName(struct student *students[], char *arananAd)
{
    int bulundu = 0;
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(students[i]->name, arananAd) == 0)
        {
            printf("\n---Ogrenci bulundu---\n");

            printf("numara: %d\n", students[i]->number);
            printf("ad: %s\n", students[i]->name);
            printf("soyad: %s\n", students[i]->surname);
            printf("vize notu: %.2f\n", students[i]->midtermgrade);
            printf("final notu: %.2f\n", students[i]->finalgrade);

            bulundu = 1;
            break;
        }
    }

    if(bulundu == 0)
    {
        printf("\n%s adinda bir ogrenci kayitli degil\n", arananAd);
    }
}