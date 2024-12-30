#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

 typedef struct {
    int month,day,year;
}Date;

 typedef struct {
    char transferID[10];
    char receivingID[10];
    double amount;
    char type[10];
    char message[50];
   
}Transaction;

 typedef struct {
    char userID[20];
    float balance;
    bool status;
}AccountInfo;

 typedef struct {
    char userID[10];
    char name[20];
    bool gender;
    char phone[10];
    char email[20];
}User;



void MENU();
void InPutInformation( User information[50] , int *length , int *curentlength);
void gender();
void OutPutInformation(User information[50], int *curentlength);
void addToFile(User information[50], int *curentlength);
void readFromFile(User information[50], int *curentlength);

int main(){

    int options,length,curentlength=0;
    User information[50];
    readFromFile(information, &curentlength);
    while(1){
        MENU();
        scanf("%d",&options);
        getchar();
        switch(options){
            case 1:
                printf("Show user list.\n");
                OutPutInformation(information,&curentlength);
                break;
            case 2:
                printf("Add user.\n");
                InPutInformation(information, &length, &curentlength);
                addToFile(information,&curentlength);
                break;
            case 3:
                printf("Incorrect format.\n");
                break;
            case 4:
                printf("Incorrect format.\n");
                break;
            case 5:
                printf("Incorrect format.\n");
                break;
            case 6:
                printf("Incorrect format.\n");
                break;
            case 7:
                printf("Incorrect format.\n");
                break;
            case 0:
                printf("See you again!!!\n");
                return 0;
                break;
            default:
                printf("Incorrect format.\n");
                break;

        }
    }
    printf("Hello world!\n");
    return 0;
}

void MENU(){
    printf("|=================================|\n");
    printf("       User Management\n");
    printf("|=================================|\n");
    printf(" 1.Show user list.\n");
    printf(" 2.Add user.\n");
    printf(" 3.Open/Lock account.\n");
    printf(" 4.View user details.\n");
    printf(" 5.Sort user list.\n");
    printf(" 6.Search for users by name.\n");
    printf(" 7.Check user data.\n");
    printf(" 0.Escape.\n");
    printf("|=================================|\n");
    printf("Your choice: ");
}

void InPutInformation(User information[50], int *length, int *curentlength) {
    printf("Number of accounts to add: ");
    scanf("%d", length);
    getchar();
    int gender;
    for (int i = *curentlength; i < *length + *curentlength; i++) {
        printf("\nEnter Trial Account Information %d:\n", i + 1);
        printf("User id: ");
        fgets(information[i].userID, sizeof(information[i].userID), stdin);
        information[i].userID[strcspn(information[i].userID, "\n")] = '\0';
        printf("Full name: ");
        fgets(information[i].name, sizeof(information[i].name), stdin);
        information[i].name[strcspn(information[i].name, "\n")] = '\0';
        printf("Gender identity (1: Boy, 2: Girl): ");
        while (1) {
            scanf("%d", &gender);
            getchar();
            if (gender == 1) {
                information[i].gender = true; // Nam
                break;
            } else if (gender == 2) {
                information[i].gender = false; // Nữ
                break;
            } else {
                printf("Invalid selection. Please select again (1: Boy, 2: Girl): ");
            }
        }
        printf("phone number: ");
        fgets(information[i].phone, sizeof(information[i].phone), stdin);
        information[i].phone[strcspn(information[i].phone, "\n")] = '\0';
        printf("Email: ");
        fgets(information[i].email, sizeof(information[i].email), stdin);
        information[i].email[strcspn(information[i].email, "\n")] = '\0';
        printf("The second account has been imported. %d.\n", i + 1);
    }
    *curentlength += *length;
}

void OutPutInformation(User information[50], int *curentlength) {
    printf("|=============================================================================|\n");
    printf("                           User information\n");
    printf("|=============================================================================|\n");
    printf("+------------+--------------------+---------+------------+--------------------+\n");
    printf("| User ID    | Name               | Gender  | Phone      | Email              |\n");
    printf("+------------+--------------------+---------+------------+--------------------+\n");
    for (int i = 0; i < *curentlength; i++) {
        printf("| %-10s | %-18s | %-7s | %-10s | %-18s |\n",information[i].userID,information[i].name,information[i].gender ? "nam" : "nu",information[i].phone,information[i].email);
    }
    printf("+------------+--------------------+---------+------------+--------------------+\n");
    printf("\n");

}

void addToFile(User information[50], int *curentlength) {
    FILE *fptr = fopen("project_04.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file for writing.\n");
        return;
    }
    fwrite(curentlength, sizeof(int), 1, fptr);
    fwrite(information, sizeof(User), *curentlength, fptr);
    fclose(fptr);
    printf("saved data to file.\n");
}

void readFromFile(User information[50], int *curentlength) {
    FILE *fptr = fopen("project_04.dat", "rb");
    if (fptr == NULL) {
        printf("Cannot open file for reading. File may be corrupted..\n");
        *curentlength = 0;
        return;
    }
    fread(curentlength, sizeof(int), 1, fptr);
    fread(information, sizeof(User), *curentlength, fptr);
    fclose(fptr);
    printf("Read data from file.\n");
}

