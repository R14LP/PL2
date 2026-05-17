#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[100];
    int age;
    char illness[100];
} Patient;

void Add(FILE *, int *);
void Remove(FILE *, int);
Patient Search(FILE *, int, int *);
void Update(FILE *, int);
void List(FILE *, int);
void TransferToSequential(FILE*, int);

int main()
{
    FILE *ptr;
    int n, index, secim = 0;
    printf("kac hasta gireceksin: ");
    scanf("%d", &n);
    Patient patient[n];

    

    if((ptr = fopen("patient.dat", "w+")) == NULL)
    {
        printf("\ndosya acilamadi");
    }else
    {
        for (int i = 0; i < n; i++)
        {
            printf("\n%d. hastanin adini yasini ve hastalik sebebini gir: ", i + 1);
            scanf("%s %d %s", patient[i].name, &patient[i].age, patient[i].illness);

            fwrite(&patient[i], sizeof(Patient), 1, ptr);
        }

        while (secim != -1)
        {
            rewind(ptr);

            printf("\neklemek icin 1\nsilmek icin 2\naramak icin 3\ngüncellemek icin 4\nlistelemek icin 5\nsequential dosyaya aktarmak icin 6");
            printf("\ncikmak icin -1\n");
            scanf("%d", &secim);

            switch (secim)
            {
            case 1:
                Add(ptr, &n);
                break;
            case 2:
                Remove(ptr, n);
                break;
            case 3:
                Search(ptr, n, &index);
                break;
            case 4:
                Update(ptr, n);
                break;
            case 5:
                List(ptr, n);
                break;
            case 6:
                TransferToSequential(ptr, n);
                break;
            default:
                break;
            }
        }
    }
    fclose(ptr);
    return 0;
}

void Add(FILE *ptr, int *n)
{
    Patient patient;

    printf("\nhastanin adini yasini ve hastalik sebebini gir: ");
    scanf("%s %d %s", patient.name, &patient.age, patient.illness);

    fseek(ptr, 0, SEEK_END);
    fwrite(&patient, sizeof(Patient), 1, ptr);
    (*n)++;
}

Patient Search(FILE *ptr, int n, int *index)
{
    Patient patient = {"", 0, ""};

    char searchingName[100];
    int searchingAge;

    printf("\nhastanin adini yasini gir: ");
    scanf("%s %d", searchingName, &searchingAge);

    for (int i = 0; i < n; i++)
    {
        fread(&patient, sizeof(Patient), 1, ptr);
        if((searchingAge == patient.age) && (strcmp(searchingName, patient.name) == 0))
        {
            *index = i;
            printf("\n%s : %d : %s", patient.name, patient.age, patient.illness);
            return patient;
        }
    }
    *index = -1;
    printf("\nhasta bulunamadi");
    return patient;
}

void Remove(FILE *ptr, int n)
{
    int index;
    Patient patient = Search(ptr, n, &index);
    Patient empty = {"", 0, ""};

    if(index != -1)
    {
        fseek(ptr, index * sizeof(Patient), SEEK_SET);
        fwrite(&empty, sizeof(Patient), 1, ptr);
    }
}

void Update(FILE *ptr, int n)
{
    int index;
    Patient patient = Search(ptr, n, &index);
    
    if(index != -1)
    {
        printf("\nyeni bilgileri gir: ");
        scanf("%s %d %s", patient.name, &patient.age, patient.illness);
        fseek(ptr, index * sizeof(Patient), SEEK_SET);
        fwrite(&patient, sizeof(Patient), 1, ptr);
    }
}

void List(FILE *ptr, int n)
{
    Patient patient;

    for (int i = 0; i < n; i++)
    {
        fread(&patient, sizeof(Patient), 1, ptr);
        printf("\n%s : %d : %s", patient.name, patient.age, patient.illness);
    }
}

void TransferToSequential(FILE *ptr, int n)
{
    FILE *txtPtr;
    Patient patient;
    if((txtPtr = fopen("patient.txt", "w")) == NULL)
    {
        printf("\ndosya acilamadi");
        return;
    }
    rewind(ptr);
    for (int i = 0; i < n; i++)
    {
        fread(&patient, sizeof(Patient), 1, ptr);
        if(patient.name[0] != '\0')
            fprintf(txtPtr, "%s %d %s\n", patient.name, patient.age, patient.illness);
    }
    fclose(txtPtr);
    printf("\nveriler aktarildi");
}