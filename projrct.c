#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct Account
{
    char accountName[40];
    char accountNumber[20];
    char DateOfBirth[15];
    char address[50];
    char contactNum[15];
    float accountBalance;
} Account;

void createAccount();
void displayAllAccount();
void updateAccount();
void deleteAccount();
void searchAccount();
void transaction();

int main()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\t\t\t====== Bank Management System ======\n");
        printf("\n\t\t\t1. Create Account");
        printf("\n\t\t\t2. Display All Accounts Information");
        printf("\n\t\t\t3. Update Account Information");
        printf("\n\t\t\t4. Delete Account Information");
        printf("\n\t\t\t5. Serach Account Information");
        printf("\n\t\t\t6. Transaction");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            createAccount();
            break;
        case '2':
            displayAllAccount();
            break;
        case '3':
            updateAccount();
            break;
        case '4':
            deleteAccount();
            break;
        case '5':
            searchAccount();
            break;
        case '6':
            transaction();
            break;
        case '0':
            printf("\n\t\t\t====== Thank You ======\n\t\t====== Created By : Shahriar Imtiaz Saikat ======\n");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
    return 0;
}

void createAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Account accountInformation;

    system("cls");

    printf("\t\t\t====== Create Student Account ======\n");

    printf("\n\t\t\tEnter Account's Name : ");
    getchar();
    gets(accountInformation.accountName);
    printf("\t\t\tEnter Account's Number : ");
    gets(accountInformation.accountNumber);
    printf("\t\t\tEnter Account Holder's Date of birth : ");
    gets(accountInformation.DateOfBirth);
    printf("\t\t\tEnter Account Holder's Address : ");
    gets(accountInformation.address);
    printf("\t\t\tEnter Account Holder's Contact Number : ");
    gets(accountInformation.contactNum);
    printf("\t\t\tEnter Current Account Balance : $  ");
    scanf("%f", &accountInformation.accountBalance);

    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);

    printf("\n\n\t\t\tAccount has been opened sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void displayAllAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Account accountInformation;

    system("cls");

    printf("\t\t\t====== Display All Account's Information ======\n\n");

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        printf("\t\t\tAccount Name : %s\n\t\t\tAccount Number : %s\n\t\t\tDate of Birth : %s\n\t\t\tAddress : %s\n\t\t\tContact Number : %s\n\t\t\tCurrent Account's Balance : %.2f\n", accountInformation.accountName, accountInformation.accountNumber, accountInformation.DateOfBirth, accountInformation.address, accountInformation.contactNum, accountInformation.accountBalance);
        printf("\t\t\t---------------------------------------------------\n");
    }

    fclose(fileOne);
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void updateAccount()
{
    printf("Done");
}
void deleteAccount()
{
    printf("Done");
}
void searchAccount()
{
    printf("Done");
}
void transaction()
{
    printf("Done");
}