#include <stdio.h>

typedef struct{
    char name[20];
    char surname[25];
    int account;
    double deposit;
} Customer;

int listIndebtedAccounts(FILE *, int);
Customer findMaxDeposit(FILE *, int);
void transferRecords(FILE *, int);
void updateRecords(FILE *, int);

int main()
{
    int secim = 0, n;
    printf("Kac musteri gireceksiniz: ");
    scanf("%d", &n);
    Customer customer[n];
    FILE *ptr;

    if((ptr = fopen("customer.dat", "w+")) == NULL)
    {
        printf("Hata: Dosya acilamadi.\n");
    }else
    {
        for (int i = 0; i < n; i++)
        {
            printf("\n--- %d. Musteri ---\n", i + 1);
            printf("Adi      : ");
            scanf("%s", customer[i].name);
            printf("Soyadi   : ");
            scanf("%s", customer[i].surname);
            printf("Hesap No : ");
            scanf("%d", &customer[i].account);
            printf("Bakiye   : ");
            scanf("%lf", &customer[i].deposit);
            fwrite(&customer[i], sizeof(Customer), 1, ptr);
        }

        while(secim != -1)
        {
            rewind(ptr);

            printf("\n=== MENU ===\n");
            printf("1 - Bakiyesi sifirin altinda olan musteri sayisi\n");
            printf("2 - En yuksek bakiyeli musteri\n");
            printf("3 - Bakiyesi 300 ve uzeri olanlari list.txt'ye aktar\n");
            printf("4 - Bakiyeleri %%50 artir ve 300 uzeri olanlari guncelle\n");
            printf("-1 - Cikis\n");
            printf("Seciminiz: ");
            scanf("%d", &secim);

            switch (secim)
            {
            case 1:
                printf("Borclu musteri sayisi: %d\n", listIndebtedAccounts(ptr, n));
                break;
            case 2:
            {
                Customer max = findMaxDeposit(ptr, n);
                printf("\n%-20s %-25s %-10s %-10s\n", "Adi", "Soyadi", "Hesap No", "Bakiye");
                printf("--------------------------------------------------------------\n");
                printf("%-20s %-25s %-10d %-10.2lf\n", max.name, max.surname, max.account, max.deposit);
                break;
            }
            case 3:
                transferRecords(ptr, n);
                printf("Kayitlar list.txt'ye aktarildi.\n");
                break;
            case 4:
                updateRecords(ptr, n);
                printf("Bakiyeler guncellendi.\n");
                break;
            default:
                break;
            }
        }
    }
    fclose(ptr);
    return 0;
}

int listIndebtedAccounts(FILE *ptr, int n)
{
    Customer customer;
    int customer_in_debt = 0;

    for (int i = 0; i < n; i++)
    {
        fread(&customer, sizeof(Customer), 1, ptr);
        if(customer.deposit < 0)
            customer_in_debt++;
    }
    return customer_in_debt;
}

Customer findMaxDeposit(FILE *ptr, int n)
{
    Customer customer, max;
    fread(&max, sizeof(Customer), 1, ptr);

    for (int i = 1; i < n; i++)
    {
        fread(&customer, sizeof(Customer), 1, ptr);
        if(customer.deposit > max.deposit)
            max = customer;
    }
    return max;
}

void transferRecords(FILE *ptr, int n)
{
    Customer customer;
    FILE *ptr_greater_than_300 = fopen("list.txt", "w");

    for (int i = 0; i < n; i++)
    {
        fread(&customer, sizeof(Customer), 1, ptr);
        if(customer.deposit >= 300)
            fprintf(ptr_greater_than_300, "%s %s %d %.2lf\n", customer.name, customer.surname, customer.account, customer.deposit);
    }
    fclose(ptr_greater_than_300);
}

void updateRecords(FILE *ptr, int n)
{
    Customer customer;

    for (int i = 0; i < n; i++)
    {
        fread(&customer, sizeof(Customer), 1, ptr);
        customer.deposit *= 1.5;
        if(customer.deposit >= 300)
        {
            fseek(ptr, -(long)sizeof(Customer), SEEK_CUR);
            fwrite(&customer, sizeof(Customer), 1, ptr);
        }
    }
}