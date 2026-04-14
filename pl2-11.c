#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char surname[50];
    int number;
};

struct Course {
    char code[20];
    char name[50];
};

struct Grade {
    int studentNumber;
    char courseCode[20];
    float midterm;
    float final;
};

int main() {
    struct Student students[2];
    struct Course courses[2];
    struct Grade grades[4];
    int i;
    
    printf("--- OGRENCI BILGILERINI GIRIN (2 Ogrenci) ---\n");
    for (i = 0; i < 2; i++) {
        printf("%d. Ogrenci Adi: ", i + 1);
        scanf("%s", students[i].name);
        printf("%d. Ogrenci Soyadi: ", i + 1);
        scanf("%s", students[i].surname);
        printf("%d. Ogrenci Numarasi: ", i + 1);
        scanf("%d", &students[i].number);
    }

    printf("\n--- DERS BILGILERINI GIRIN (2 Ders) ---\n");
    for (i = 0; i < 2; i++) {
        printf("%d. Ders Kodu (Orn: CENG101): ", i + 1);
        scanf("%s", courses[i].code);
        printf("%d. Ders Adi: ", i + 1);
        scanf("%s", courses[i].name);
    }

    printf("\n--- NOT BILGILERINI GIRIN (4 Not Kaydi) ---\n");
    for (i = 0; i < 4; i++) {
        printf("%d. Kayit - Ogrenci Numarasi: ", i + 1);
        scanf("%d", &grades[i].studentNumber);
        printf("%d. Kayit - Ders Kodu: ", i + 1);
        scanf("%s", grades[i].courseCode);
        printf("%d. Kayit - Vize Notu: ", i + 1);
        scanf("%f", &grades[i].midterm);
        printf("%d. Kayit - Final Notu: ", i + 1);
        scanf("%f", &grades[i].final);
    }

    printf("\n====================================\n");
    printf("ARAMA MODU (Cikmak icin Ogrenci Ismine -1 yazin)\n");
    printf("====================================\n");

    while (1) {
        char inputName[50] = "", inputSurname[50] = "", inputCourse[50] = "";
        int foundStudentNumber = -1;
        char foundCourseCode[20] = "";
        int gradeFound = 0;
        
        while (foundStudentNumber == -1) {
            printf("\nAranacak Ogrenci Ismi: ");
            scanf("%s", inputName);

            // -1 girildiyse programdan çıkış yap
            if (strcmp(inputName, "-1") == 0) {
                printf("Sistemden cikiliyor...\n");
                return 0; 
            }

            printf("Aranacak Ogrenci Soyismi: ");
            scanf("%s", inputSurname);

            for (i = 0; i < 2; i++) {
                if (strcmp(students[i].name, inputName) == 0 && strcmp(students[i].surname, inputSurname) == 0) {
                    foundStudentNumber = students[i].number;
                    break;
                }
            }

            if (foundStudentNumber == -1) {
                printf("HATA: Ogrenci bulunamadi. Lutfen tekrar deneyin veya cikmak icin -1 yazin.\n");
            }
        }

        while (foundCourseCode[0] == '\0') {
            printf("Aranacak Ders Ismi: ");
            scanf("%s", inputCourse);

            for (i = 0; i < 2; i++) {
                if (strcmp(courses[i].name, inputCourse) == 0) {
                    strcpy(foundCourseCode, courses[i].code);
                    break;
                }
            }

            if (foundCourseCode[0] == '\0') {
                printf("HATA: Ders bulunamadi. Lutfen tekrar deneyin.\n");
            }
        }

        for (i = 0; i < 4; i++) {
            if (grades[i].studentNumber == foundStudentNumber && strcmp(grades[i].courseCode, foundCourseCode) == 0) {
                printf("\n--- SONUC ---\n");
                printf("Ogrenci: %s %s (No: %d)\n", inputName, inputSurname, foundStudentNumber);
                printf("Ders: %s (Kod: %s)\n", inputCourse, foundCourseCode);
                printf("Vize: %.1f | Final: %.1f\n", grades[i].midterm, grades[i].final);
                gradeFound = 1;
                break;
            }
        }

        if (!gradeFound) {
            printf("\nBu ogrencinin bu derse ait not kaydi bulunamadi.\n");
        }
        
    }

    return 0;
}