#include <stdio.h>
typedef struct
{
    char name[100];
    int number;
    float exam_1, exam_2;
    float average;
} Student;
void List(FILE *, int);
void List_Greater_than_60(FILE *, int);
void Write_to_File(FILE *, int);
void Write_the_File_Size(int);
int main()
{
    FILE *ptr;
    int n, secim = 0;
    printf("Kac ogrenci gireceksiniz: ");
    scanf("%d", &n);
    Student student[n];
    if((ptr = fopen("student.txt", "w+")) == NULL)
    {
        printf("Hata: Dosya acilamadi.\n");
    }else
    {
        for (int i = 0; i < n; i++)
        {
            printf("\n--- %d. Ogrenci ---\n", i + 1);
            printf("Isim: ");
            scanf("%s", student[i].name);
            printf("Numara: ");
            scanf("%d", &student[i].number);
            printf("Vize notu: ");
            scanf("%f", &student[i].exam_1);
            printf("Final notu: ");
            scanf("%f", &student[i].exam_2);
            student[i].average = student[i].exam_1 * 0.4 + student[i].exam_2 * 0.6;
            fprintf(ptr, "%s %d %.2f %.2f %.2f\n", student[i].name, student[i].number, student[i].exam_1, student[i].exam_2, student[i].average);
        }
        while(secim != -1)
        {
            rewind(ptr);
            printf("\n=== MENU ===\n");
            printf("1 - Verileri listele\n");
            printf("2 - Ortalamasi 60 uzerinde olanlari listele\n");
            printf("3 - Gecenler ve kalanlari dosyaya yaz\n");
            printf("4 - Dosya boyutunu ekrana yazdir\n");
            printf("-1 - Cikis\n");
            printf("Seciminiz: ");
            scanf("%d", &secim);
            switch (secim)
            {
            case 1:
                List(ptr, n);
                break;
            case 2:
                List_Greater_than_60(ptr, n);
                break;
            case 3:
                Write_to_File(ptr, n);
                break;
            case 4:
                Write_the_File_Size(n);
                break;
            default:
                break;
            }
        }
        fclose(ptr);
    }
    return 0;
}
void List(FILE *ptr, int n)
{
    Student student;
    printf("\n%-20s %-10s %-8s %-8s %-8s\n", "Isim", "Numara", "Vize", "Final", "Ortalama");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        fscanf(ptr, "%s %d %f %f %f", student.name, &student.number, &student.exam_1, &student.exam_2, &student.average);
        printf("%-20s %-10d %-8.2f %-8.2f %-8.2f\n", student.name, student.number, student.exam_1, student.exam_2, student.average);
    }
}
void List_Greater_than_60(FILE *ptr, int n)
{
    Student student;
    printf("\n%-20s %-10s %-8s %-8s %-8s\n", "Isim", "Numara", "Vize", "Final", "Ortalama");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        fscanf(ptr, "%s %d %f %f %f", student.name, &student.number, &student.exam_1, &student.exam_2, &student.average);
        if(student.average >= 60)
            printf("%-20s %-10d %-8.2f %-8.2f %-8.2f\n", student.name, student.number, student.exam_1, student.exam_2, student.average);
    }
}
void Write_to_File(FILE *ptr, int n)
{
    Student student;
    FILE *ptr_greater = fopen("gecenler.txt", "w");
    FILE *ptr_not_greater = fopen("kalanlar.txt", "w");
    if(!ptr_greater || !ptr_not_greater)
    {
        printf("Hata: Dosya acilamadi.\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(ptr, "%s %d %f %f %f", student.name, &student.number, &student.exam_1, &student.exam_2, &student.average);
        if(student.average >= 60)
            fprintf(ptr_greater, "%s %d %.2f %.2f %.2f\n", student.name, student.number, student.exam_1, student.exam_2, student.average);
        else
            fprintf(ptr_not_greater, "%s %d %.2f %.2f %.2f\n", student.name, student.number, student.exam_1, student.exam_2, student.average);
    }
    fclose(ptr_greater);
    fclose(ptr_not_greater);
    printf("Gecenler 'gecenler.txt' dosyasina, kalanlar 'kalanlar.txt' dosyasina yazildi.\n");
}
void Write_the_File_Size(int n)
{
    printf("Dosyanin boyutu: %lu byte\n", n * sizeof(Student));
}