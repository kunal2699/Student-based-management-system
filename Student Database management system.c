/*Student Management system Developer: Kunal Yadav(24) */
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct Student
{
    char studentName[50];
    char studentId[15];
    char studentDept[10];
    char studentAddress[100];
    char studentContactNum[10];
    float studentCGPA;
} Student;

void student_login();
void menu();
void createAccount();
void displayInfo();
void updateInfo();
void deleteInfo();
void searchInfo();
void login();

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


int main(){
	printf("\n\t\t***************** Student Database Management System ***************** ");
	fordelay(1000000000);
	  
	char option1;

    while (option1 != '0')
    {printf("\n\t\t\t1. Admin");
     printf("\n\t\t\t2. Student");
     printf("\n\t\t\t0. Exit");
	printf("\n\n\n\t\t\tEnter Your Option: ");
    scanf(" %c", &option1);

        switch (option1)
        {
        case '1':
            login();
            break;
        case '2':
            student_login();
            break;
        case '0':
        printf("\n\t\t\t====== Thank You ======");    
            break;
		default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
 return 0;
}

void student_login(){
	
    char option2;

    while (option2 != '0')
    {
        system("cls");
        printf("\n\t\t***************** Student Database Management System ***************** ");
        printf("\n\t\t\t1. Display All Students Information");
        printf("\n\t\t\t2. Search Student Information");
        printf("\n\t\t\t0. Log out");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option2);

        switch (option2)
        {
        case '1':
            displayInfo();
            break;
        case '2':
            searchInfo();
            break;
        case '0':
			system("cls");
            printf("\n\t\t***************** Student Database Management System ***************** ");
		  break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
}


void login(){
      system("cls") ;     
      printf("\n\t\t***************** Student Database Management System ***************** ");
      int login_exit;
      char user[10],username[10]="kunal";//username and password =kunal
	 char pass[10],password[10]="kunal";
    int i=0;
    printf("\n\n\t\t          Username:");
    scanf("%s",user);
if(strcmp(user,username)==0)
{
	
    printf("\t\t          Password:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\t\t\tPassword Match!\n\t\tLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\t\t\tWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&login_exit);
            if (login_exit==1)
                    {

                        system("cls");
                        login();
                    }

            else if (login_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(100000000);       
                    system("cls");
                    goto login_try;}

    }
   }
else{ 
	  printf("\n\t\t\tWrong Username!!\a\a\a");
            login_try1:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&login_exit);
            if (login_exit==1)
                    {

                        system("cls");
                        login();
                    }

            else if (login_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(100000000);       
                    system("cls");
                    goto login_try1;}

    }
    
}

void menu()
{
    
    char option;
    int log;

    while (option != '0')
    {
        system("cls");
        printf("\n\t\t***************** Student Database Management System ***************** ");
        printf("\n\t\t\t1. Add Student Account");//to add a new student
        printf("\n\t\t\t2. Display All Students Information");// to display all the students info
    
        printf("\n\t\t\t3. Update Student Information");//to update the student info
        printf("\n\t\t\t4. Delete Student Information");// to delete the student info
        printf("\n\t\t\t5. Search Student Information");// to search by id or dept 
        printf("\n\t\t\t0. Log out");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);
        
        switch (option)
        {
        case '1':
            createAccount();
            break;
        case '2':
            displayInfo();
            break;
        case '3':
            updateInfo();
            break;
        case '4':
            deleteInfo();
            break;
        case '5':
            searchInfo();
            break;
        case '0':
		    printf("\n\t\t\tConfirm");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\n\n\t\t\tEnter Your Option: ");
            scanf(" %d", &log);
            if(log==2)
            option=6;
			system("cls");
			printf("\n\t\t***************** Student Database Management System ***************** ");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
}

void createAccount()
{
    FILE *fileOne = fopen("studentInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t====== ADD Student Account ======\n");

    printf("\n\t\t\tEnter Student's Name : ");
    getchar();
    gets(stundentInformation.studentName);
    printf("\t\t\tEnter Student's ID : ");
    gets(stundentInformation.studentId);
    printf("\t\t\tEnter Student's Department : ");
    gets(stundentInformation.studentDept);
    printf("\t\t\tEnter Student's Address : ");
    gets(stundentInformation.studentAddress);
    printf("\t\t\tEnter Student's Contact Number : ");
    gets(stundentInformation.studentContactNum);
    printf("\t\t\tEnter Student's Current CGPA : ");
    scanf("%f", &stundentInformation.studentCGPA);

    fwrite(&stundentInformation, sizeof(stundentInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void displayInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t\t====== All Students Information ======\n");

    printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Dept.", "Address", "Contact", "CGPA");
    printf("\t\t----------------------------------------------------------------------------------------");

    while (fread(&stundentInformation, sizeof(stundentInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", stundentInformation.studentName, stundentInformation.studentId, stundentInformation.studentDept, stundentInformation.studentAddress, stundentInformation.studentContactNum, stundentInformation.studentCGPA);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void updateInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Update Students Information ======\n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Student Name\n\t\t\t2.Update Student Dept.\n\t\t\t3.Update Student Address\n\t\t\t4.Update Student Contact No.\n\t\t\t5.Update Student CPGA");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Student's Name to Update: ");
                getchar();
                gets(tempInformation.studentName);
                strcpy(studentInformation.studentName, tempInformation.studentName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's Dept. to Update: ");
                getchar();
                gets(tempInformation.studentDept);
                strcpy(studentInformation.studentDept, tempInformation.studentDept);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Student's Address to Update: ");
                getchar();
                gets(tempInformation.studentAddress);
                strcpy(studentInformation.studentAddress, tempInformation.studentAddress);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Student's Contact No. to Update: ");
                getchar();
                gets(tempInformation.studentContactNum);
                strcpy(studentInformation.studentContactNum, tempInformation.studentContactNum);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Student's CGPA to Update: ");
                scanf("%f", &tempInformation.studentCGPA);
                studentInformation.studentCGPA = tempInformation.studentCGPA;

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void deleteInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Delete Student Information ======\n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void searchInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    Student studentInformation;

    int choice, flag = 0;
    char studentID[20], studentDept[10];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Search Student Information ======\n");

    printf("\n\t\t\tChoose your option :\n\t\t\t1.Search by Student ID\n\t\t\t2.Search by Student Dept.");
    printf("\n\n\t\t\tEnter Your Option : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student ID : ");
        getchar();
        gets(studentID);
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (strcmp(studentInformation.studentId, studentID) == 0)
            {
                flag++;
                printf("\n\t\t\tStudent Name : %s\n\t\t\tStudent ID : %s\n\t\t\tStudent Dept. : %s\n\t\t\tStudent Address : %s\n\t\t\tStudent Contact No. : %s\n\t\t\tStudent CGPA : %.2f\n", studentInformation.studentName, studentInformation.studentId, studentInformation.studentDept, studentInformation.studentAddress, studentInformation.studentContactNum, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student Dept. : ");
        getchar();
        gets(studentDept);
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Dept.", "Address", "Contact", "CGPA");
        printf("\t\t----------------------------------------------------------------------------------------");
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (stricmp(studentInformation.studentDept, studentDept) == 0)
            {
                flag++;
                printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", studentInformation.studentName, studentInformation.studentId, studentInformation.studentDept, studentInformation.studentAddress, studentInformation.studentContactNum, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fileOne);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}
