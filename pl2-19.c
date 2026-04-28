#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[50];
    char surname[50];
    int number;
    struct Student *next;
};

struct Course {
    char code[20];
    char name[50];
    struct Course *next;
};

struct Grade {
    int studentNumber;
    char courseCode[20];
    float midterm;
    float final;
    struct Grade* next;
};

int main() {
    struct Student *headStudent = NULL, *tailStudent = NULL;
    struct Course *headCourse = NULL, *tailCourse = NULL;
    struct Grade *headGrade = NULL, *tailGrade = NULL;
    int i;
    
    printf("--- OGRENCI BILGILERINI GIRIN (2 Ogrenci) ---\n");
    for (i = 0; i < 2; i++) {
        struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));

        printf("%d. Ogrenci Adi: ", i + 1);
        scanf("%s", newStudent->name);
        printf("%d. Ogrenci Soyadi: ", i + 1);
        scanf("%s", newStudent->surname);
        printf("%d. Ogrenci Numarasi: ", i + 1);
        scanf("%d", &newStudent->number);

        newStudent->next = NULL;

        if(headStudent == NULL){

            headStudent = newStudent;
            tailStudent = newStudent;
        }else{
            tailStudent->next = newStudent;
            tailStudent = newStudent;
        }
    }

    printf("\n--- DERS BILGILERINI GIRIN (2 Ders) ---\n");
    for (i = 0; i < 2; i++) {
        struct Course *newCourse = (struct Course *)malloc(sizeof(struct Course));

        printf("%d. Ders Kodu (Orn: CENG101): ", i + 1);
        scanf("%s", newCourse->code);
        printf("%d. Ders Adi: ", i + 1);
        scanf("%s", newCourse->name);

        newCourse->next = NULL;

        if(headCourse == NULL){
            headCourse = newCourse;
            tailCourse = newCourse;
        }else{
            tailCourse->next = newCourse;
            tailCourse = newCourse;
        }
    }

    printf("\n--- NOT BILGILERINI GIRIN (4 Not Kaydi) ---\n");
    for (i = 0; i < 4; i++) {
        struct Grade *newGrade = (struct Grade *)malloc(sizeof(struct Grade));

        printf("%d. Kayit - Ogrenci Numarasi: ", i + 1);
        scanf("%d", &newGrade->studentNumber);
        printf("%d. Kayit - Ders Kodu: ", i + 1);
        scanf("%s", newGrade->courseCode);
        printf("%d. Kayit - Vize Notu: ", i + 1);
        scanf("%f", &newGrade->midterm);
        printf("%d. Kayit - Final Notu: ", i + 1);
        scanf("%f", &newGrade->final);

        newGrade->next = NULL;

        if(headGrade == NULL){
            headGrade = newGrade;
            tailGrade = newGrade;
        }else{
            tailGrade->next = newGrade;
            tailGrade = newGrade;
        }
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

                struct Student *currentS = headStudent;
                struct Student *nextS;

                while(currentS != NULL){
                    nextS = currentS->next;
                    free(currentS);
                    currentS = nextS;
                }
                
                struct Course *currentC = headCourse;
                struct Course *nextC;

                while(currentC != NULL){
                    nextC = currentC->next;
                    free(currentC);
                    currentC = nextC;
                }

                struct Grade *currentG = headGrade;
                struct Grade *nextG;

                while(currentG != NULL){
                    nextG = currentG->next;
                    free(currentG);
                    currentG = nextG;
                }

                return 0; 
            }

            printf("Aranacak Ogrenci Soyismi: ");
            scanf("%s", inputSurname);

            struct Student *currentStudent = headStudent;

            while(currentStudent != NULL){
                if(strcmp(currentStudent->name, inputName) == 0 && strcmp(currentStudent->surname, inputSurname) == 0){
                    foundStudentNumber = currentStudent->number;
                    break;
                }
                currentStudent = currentStudent->next;
            }

            if (foundStudentNumber == -1) {
                printf("HATA: Ogrenci bulunamadi. Lutfen tekrar deneyin veya cikmak icin -1 yazin.\n");
            }
        }

        while (foundCourseCode[0] == '\0') {
            printf("Aranacak Ders Ismi: ");
            scanf("%s", inputCourse);

            struct Course *currentCourse = headCourse;

            while(currentCourse != NULL){
                if(strcmp(currentCourse->name, inputCourse) == 0){
                    strcpy(foundCourseCode, currentCourse->code);
                    break;
                }
                currentCourse = currentCourse->next;
            }

            if (foundCourseCode[0] == '\0') {
                printf("HATA: Ders bulunamadi. Lutfen tekrar deneyin.\n");
            }
        }

        struct Grade *currentGrade = headGrade;

        while(currentGrade != NULL){
            if(currentGrade->studentNumber == foundStudentNumber && strcmp(currentGrade->courseCode, foundCourseCode) == 0){
                printf("\n--- SONUC ---\n");
                printf("Ogrenci: %s %s (No: %d)\n", inputName, inputSurname, foundStudentNumber);
                printf("Ders: %s (Kod: %s)\n", inputCourse, foundCourseCode);
                printf("Vize: %.1f | Final: %.1f\n", currentGrade->midterm, currentGrade->final);
                gradeFound = 1;
                break;
            }

            currentGrade = currentGrade->next;
        }

        if (!gradeFound) {
            printf("\nBu ogrencinin bu derse ait not kaydi bulunamadi.\n");
        }
        
    }

    
    return 0;
}