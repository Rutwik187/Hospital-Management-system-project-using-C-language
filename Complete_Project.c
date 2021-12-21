#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include <time.h>    //capcha
#include <windows.h> // loading bar, gotoxy
#include <ctype.h>   //isalpha

#define Amoxicillin_PRICE 80.00
#define Lisinopril_PRICE 9.20

void WelcomeScreen();
void Title();
void LoginScreen();
void first();
void Patient();
void MainMenu();
void loadingBar();
void Add_rec();
void List_rec();
void Search_rec();
void Edit_rec();
void Del_rec();

void Employee();
void MainMenuE();
void Add_recE();
void List_recE();
void search_recE();
void Edit_recE();
void Del_recE();

void Vaccination_system();
void MainMenuV();
void Add_Vaccines();
void List_recV();
void Add_recV();
void Vaccination_status();
void Vaccination();
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Billing_System();

struct patient
{
    char First_Name[15];
    char Last_Name[15];
    char Gender;
    int Age;
    char Contact_no[15];
    char Address[30];
    char SPO2[5];
    char Temperature[5];
    char Prescribed_Doctor[20];
};
struct employee
{
    char First_Name[15];
    char Last_Name[15];
    char Gender;
    int Age;
    char Contact_no[15];
    char Address[30];
    char Adhar_No[20];
    char Sallery[7];
    char Current_Position[10];
};
struct person
{
    char First_Name[15];
    char Last_Name[15];
    char Gender;
    int Age;
    char Contact_no[15];
    char Address[30];
    char Adhar_No[20];
};
struct vaccine
{
    int Available_vaccine;
    int Patients_vaccinated;
};
struct vaccine a;
struct person v;
int valid, exist;
struct patient p, temp_c;
struct employee e;
char ans;

/**************************** MAIN FUNCTION *********************************/
int main()
{
    loadingBar();
    WelcomeScreen();
    LoginScreen();
    system("cls");
    Title();
    first();

    return 0;
}

void first()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3  MENU  \xB3\xB2=\xB2=\xB2-\xB3\n\n");
    int option;
    printf("\n\n\t\t\t\t\t\t\t1. Patient's Record");
    printf("\n\n\t\t\t\t\t\t\t2. Employee's Record");
    printf("\n\n\t\t\t\t\t\t\t3. Vaccination System");
    printf("\n\n\t\t\t\t\t\t\t4. Billing System");
    printf("\n\n\t\t\t\t\t\t\t5. Exit");

    printf("\n\n\n\n\n\t\t\t\t\t\t\tChoose from 1 to 6...  ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        Patient();
        break;
    case 2:
        Employee();
        break;
    case 3:
        Vaccination_system();
        break;
    case 4:
        Billing_System();
        break;
    case 5:
        exit(0);
        break;

    default:
        break;
    }
}
/*********************************LOADING BAR************************************/

void loadingBar()
{
    system("cls");
    // system("color 0F");
    char a = 177, b = 219;

    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t Loading...\n\n");
    printf("\t\t\t\t\t");

    for (int i = 0; i < 26; i++)
        printf("%c", a);

    printf("\r");
    printf("\t\t\t\t\t");

    for (int i = 0; i < 26; i++)
    {
        printf("%c", b);
        Sleep(200);
    }
}

/****************************** WELCOME SCREEN ************************************/
void WelcomeScreen()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t********************************************************************************************\n");
    printf("\n\t\t\t\t\t\t\t\t\tWELCOME TO SAI HOSPITAL MANAGEMENT SYSTEM   \t   \n");
    printf("\n\t\t\t\t\t\t********************************************************************************************\n");

    printf("\tPress any key to continue.......");
    getch();
    system("cls");
}

/****************************** TITLE ************************************************/
void Title()
{
    printf("\n\n\t\t\t\t\t\t********************************************************************************************\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t  SAI HOSPITAL  \t   \n");
    printf("\n\t\t\t\t\t\t********************************************************************************************\n");
}

/***********************************LOGIN SCREEN ***********************************************/
void LoginScreen()
{
    system("cls");
    Title();
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3  LOGIN PAGE  \xB3\xB2=\xB2=\xB2-\xB3\n\n");

    char username[20];
    char password[20];
    int i = 0;

    char original_username[20] = "Rutwik";
    char original_password[20] = "P@ss123";

    do
    {
        printf("\t\t\t\t USERNAME: ");
        scanf("%s", username);
        printf("\n\n\t\t\t\t PASSWORD: ");
        char password[15];
        int characterPosition = 0;
        char ch;
        while (1)
        {
            ch = getch();

            if (ch == 13) // Enter has the ASCII value of 13 and getch stores the value in terms of ASCII values
            {
                break;
            }
            else if (ch == 8) // backspace has the ASCII value of 8
            {
                if (characterPosition > 0)
                {
                    characterPosition--;
                    password[characterPosition] = '\0';
                    printf("\b \b");
                }
            }
            else
            {
                password[characterPosition] = ch;
                characterPosition++;
                printf("*");
            }
        }
        password[characterPosition] = '\0';

        printf("\n\n\n\t\t\t\t CAPTCHA: ");
        int captcha, entered_captcha;
        srand(time(0));
        captcha = (rand() % (9999 - 1000)) + 1;
        printf("%d", captcha);

        printf("\n\n\t\t\tEnter The Captcha: ");
        scanf("%d", &entered_captcha);

        if (strcmp(username, original_username) == 0 && strcmp(password, original_password) == 0 && entered_captcha == captcha)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t  ....LOGIN SUCESSFULL.... :)\n\n");
            printf("Press any key to continue....");
            getch();

            first();
            break;
        }
        else
        {
            if (strcmp(username, original_username) != 0 || strcmp(password, original_password) != 0)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t\t INVALID LOGIN ID OR PASSWORD :(  ");
            }

            else if (entered_captcha != captcha)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\tINVALID CAPTCHA :(  ");
            }
            if ((2 - i) > 0)
            {
                printf("\n\n \t\t\t\t\t\t\t\t\t\t\t   TRY AGAIN :) \n\n");
                printf(" %d attempt remaining....\n", (2 - i));
            }
            i++;
        }
    } while (i <= 2);

    if (i > 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t MORE THAN 3 UNSUCESSFULL ATEMPTS :(");
        printf("\n\n \t\t\t\t\t\t\t\t\t\t\tTRY AGAIN LATER.... :(");
        getch();
        exit(0);
    }
}

/************************ Patient ******************************/
void Patient()
{
    MainMenu();
}
/******************************************* MAIN MENU *************************************/
void MainMenu()
{
    system("cls");
    Title();
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3  MAIN MENU  \xB3\xB2=\xB2=\xB2-\xB3\n\n");

    int option;
    printf("\n\n\t\t\t\t\t\t\t1. Add Patients Record");
    printf("\n\n\t\t\t\t\t\t\t2. List Patients Record");
    printf("\n\n\t\t\t\t\t\t\t3. Search Patients Record");
    printf("\n\n\t\t\t\t\t\t\t4. Edit Patients Record");
    printf("\n\n\t\t\t\t\t\t\t5. Delete Patients Record");
    printf("\n\n\t\t\t\t\t\t\t6. Exit");

    printf("\n\n\n\n\n\t\t\t\t\t\t\tChoose from 1 to 6...  ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        Add_rec();
        break;
    case 2:
        List_rec();
        break;
    case 3:
        Search_rec();
        break;
    case 4:
        Edit_rec();
        break;
    case 5:
        Del_rec();
        break;
    case 6:
        first();
        break;
    default:
        printf("\t\t\t Invalid Entry!!");
        printf("\n\n\t\t\t Press Enter to choose Anathor Option :)");
        getch();
        MainMenu();
    }
}
/********************************* ADD RECORD *************************************/
void Add_rec()
{
    system("cls");

    char ans;
    FILE *ek;
    ek = fopen("Record2.dat", "a");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tADD PATIENTS RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");

    /************************ FIRST NAME *********************************/

A: // We can also use do while loop instead of adding level(A:)

    printf("\n\n\n\n\t\t\tFirst Name: ");
    scanf("%s", p.First_Name);
    p.First_Name[0] = toupper(p.First_Name[0]);
    if (strlen(p.First_Name) > 20 || strlen(p.First_Name) < 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
        goto A;
    }
    else
    {
        for (int i = 0; i < strlen(p.First_Name); i++)
        {
            if (isalpha(p.First_Name[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 0)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                goto A;
            }
        }
    }
    /************************ Last NAME *********************************/

B:
    printf("\n\n\t\t\tLast Name: ");
    scanf("%s", p.Last_Name);
    p.Last_Name[0] = toupper(p.Last_Name[0]);
    if (strlen(p.Last_Name) > 20 || strlen(p.Last_Name) < 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
        goto B;
    }
    else
    {
        for (int i = 0; i < strlen(p.Last_Name); i++)
        {
            if (isalpha(p.Last_Name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (valid == 0)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
            goto B;
        }
    }

    /************************* GENDER ********************************/

    do
    {
        printf("\n\n\t\t\tGender[M/F]: ");
        fflush(stdin);
        scanf("%c", &p.Gender);
        p.Gender = toupper(p.Gender);
        fflush(stdin);
        if (p.Gender == 'M' || p.Gender == 'F')
        {
            valid = 1;
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
            valid = 0;
        }
    } while (valid == 0);

    /************************* AGE ********************************/

    printf("\n\n\t\t\tAge: ");
    scanf("%d", &p.Age);

    /************************ ADDRESS *********************************/

    do
    {
        printf("\n\n\t\t\tAddress: ");
        scanf("%s", p.Address);
        p.Address[0] = toupper(p.Address[0]);
        if (strlen(p.Address) > 20 || strlen(p.Address) < 3)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
            valid = 0;
        }
        else
        {
            valid = 1;
        }
    } while (valid == 0);

    /************************ CONTACT NUMBER ***************************/

    do
    {
        printf("\n\n\t\t\tContact NO.: ");
        scanf("%s", p.Contact_no);
        for (int i = 0; i < strlen(p.Contact_no); i++)
        {
            if (isalpha(p.Contact_no[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                break;
            }
        }

    } while (valid == 1);

    /****************************** TEMPERATURE **********************************/
    do
    {
        printf("\n\n\t\t\tTemperatute(F): ");
        scanf("%s", p.Temperature);
        for (int i = 0; i < strlen(p.Temperature); i++)
        {
            if (isalpha(p.Temperature[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                break;
            }
        }

    } while (valid == 1);

    /****************************** SPO2 **********************************/
    do
    {
        printf("\n\n\t\t\tSPO2 Level: ");
        scanf("%s", p.SPO2);
        for (int i = 0; i < strlen(p.SPO2); i++)
        {
            if (isalpha(p.SPO2[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                break;
            }
        }

    } while (valid == 1);

    /*************************************** PRESCRIBED DOCTOR *****************************/
D:

    printf("\n\n\t\t\tPrescribed Doctor: ");
    scanf("%s", p.Prescribed_Doctor);
    p.Prescribed_Doctor[0] = toupper(p.Prescribed_Doctor[0]);
    if (strlen(p.Prescribed_Doctor) > 20 || strlen(p.Prescribed_Doctor) < 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
        goto D;
    }
    else
    {
        for (int i = 0; i < strlen(p.Prescribed_Doctor); i++)
        {
            if (isalpha(p.Prescribed_Doctor[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 0)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                goto D;
            }
        }
    }

    /********** PRINTING INFORMAINION IN FILE ************/

    fprintf(ek, "%s %s %c %d %s %s %s %s %s\n", p.First_Name,
            p.Last_Name,
            p.Gender,
            p.Age,
            p.Contact_no,
            p.Address,
            p.SPO2,
            p.Temperature,
            p.Prescribed_Doctor);
    printf("\nInformation Entered Sucessfully......");
    fclose(ek);

sd:
    getch();
    printf("\n\n\t\t\t\t\t\t\t\t\tDo You Want to Add more Records? [Y/N]...");
    fflush(stdin);
    scanf("%c", &ans);

    if (toupper(ans) == 'Y')
    {
        Add_rec();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\n\t\t\t\t\t\t\t\t\tThank You :) ");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Input :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Press [Y/N] :) ");
        goto sd;
    }
}
/****************************** LIST RECORD ********************/
void List_rec()
{
    int row;
    system("cls");
    FILE *ek;
    ek = fopen("Record2.dat", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tLIST PATIENTS RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    gotoxy(1, 15);
    printf("Full Name");
    gotoxy(20, 15);
    printf("Gender");
    gotoxy(30, 15);
    printf("Age");
    gotoxy(40, 15);
    printf("Address");
    gotoxy(60, 15);
    printf("Contact No.");
    gotoxy(78, 15);
    printf("Temperature");
    gotoxy(92, 15);
    printf("SPO2");
    gotoxy(99, 15);
    printf("Prescribed Doctor");

    printf("\n=============================================================================================================================\n");

    row = 17;
    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", p.First_Name,
                  p.Last_Name,
                  &p.Gender,
                  &p.Age,
                  p.Contact_no,
                  p.Address,
                  p.Temperature,
                  p.SPO2,
                  p.Prescribed_Doctor) != EOF)
    {
        gotoxy(1, row);
        printf("%s %s ", p.First_Name, p.Last_Name);
        gotoxy(20, row);
        printf("%c", p.Gender);
        gotoxy(30, row);
        printf("%d", p.Age);
        gotoxy(40, row);
        printf("%s", p.Address);
        gotoxy(60, row);
        printf("%s", p.Contact_no);
        gotoxy(78, row);
        printf("%s", p.Temperature);
        gotoxy(92, row);
        printf("%s", p.SPO2);
        gotoxy(99, row);
        printf("%s", p.Prescribed_Doctor);
        row++;
    }
    fclose(ek);
    getch();
    MainMenu();
}
/****************************** SEARCH RECORD ********************/
void Search_rec()
{
    char Name[20];
    system("cls");
    FILE *ek;
    ek = fopen("Record2.dat", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tSearch PATIENTS RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    gotoxy(12, 8);
    printf("\nEnter the patients name of whose data is to be viewed: ");
    scanf("%s", Name);
    fflush(stdin);
    Name[0] = toupper(Name[0]);

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", p.First_Name,
                  p.Last_Name,
                  &p.Gender,
                  &p.Age,
                  p.Contact_no,
                  p.Address,
                  p.Temperature,
                  p.SPO2,
                  p.Prescribed_Doctor) != EOF)
    {
        if (strcmp(p.First_Name, Name) == 0)
        {
            gotoxy(1, 15);
            printf("Full Name");
            gotoxy(20, 15);
            printf("Gender");
            gotoxy(30, 15);
            printf("Age");
            gotoxy(40, 15);
            printf("Address");
            gotoxy(60, 15);
            printf("Contact No.");
            gotoxy(78, 15);
            printf("Temperature");
            gotoxy(92, 15);
            printf("SPO2");
            gotoxy(99, 15);
            printf("Prescribed Doctor");
            printf("\n===========================================================================================================================\n");
            gotoxy(1, 18);
            printf("%s %s", p.First_Name, p.Last_Name);
            gotoxy(20, 18);
            printf("%c", p.Gender);
            gotoxy(30, 18);
            printf("%d", p.Age);
            gotoxy(40, 18);
            printf("%s", p.Address);
            gotoxy(60, 18);
            printf("%s", p.Contact_no);
            gotoxy(78, 18);
            printf("%s", p.Temperature);
            gotoxy(92, 18);
            printf("%s", p.SPO2);
            gotoxy(99, 18);
            printf("%s", p.Prescribed_Doctor);
            printf("\n");
            break;
        }
    }
    if (strcmp(p.First_Name, Name) != 0)
    {
        gotoxy(5, 10);
        printf("\n\n\n\n\t\t\tRecord not found :(");
        getch();
    }
    fclose(ek);

L:
    getch();
    printf("\n\n\n\n\t\t\tDo You want to search more Records [Y/N]....?  ");
    scanf("%c", &ans);
    ans = toupper(ans);
    if (ans == 'Y')
    {
        Search_rec();
    }
    if (ans == 'N')
    {
        MainMenu();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
        fflush(stdin);
        goto L;
    }
}

/************************************* EDIT RECORD ****************************************************************/
void Edit_rec()
{
    char Name[20];
    system("cls");
    FILE *ek, *ft;
    int i, b;
    ft = fopen("temp2.dat", "w+");
    ek = fopen("Record2.dat", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEDIT PATIENTS RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    if (ek == NULL)
    {
        printf("\n\t Can't Open the File!!");
        getch();
        // MainMenu;
    }

    printf("\n\nEnter the patients First Name of whose data is to be Edited: ");
    scanf("%s", Name);
    fflush(stdin);
    Name[0] = toupper(Name[0]);

    if (ft == NULL)
    {
        printf("\n\t Can't Open the File!!");
        getch();
        MainMenu;
    }

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", p.First_Name,
                  p.Last_Name,
                  &p.Gender,
                  &p.Age,
                  p.Contact_no,
                  p.Address,
                  p.Temperature,
                  p.SPO2,
                  p.Prescribed_Doctor) != EOF)
    {
        if (strcmp(p.First_Name, Name) == 0)
        {
            valid = 1;
            printf("\n\n\n\t\t\t\t\tExisting Data:");
            printf("\n\t\t----------------------------------------------------------------------");
            gotoxy(1, 17);
            printf("Full Name");
            gotoxy(20, 17);
            printf("Gender");
            gotoxy(30, 17);
            printf("Age");
            gotoxy(40, 17);
            printf("Address");
            gotoxy(60, 17);
            printf("Contact No.");
            gotoxy(78, 17);
            printf("Temperature");
            gotoxy(92, 17);
            printf("SPO2");
            gotoxy(99, 17);
            printf("Prescribed Doctor");
            printf("\n===========================================================================================================================\n");
            gotoxy(1, 20);
            printf("%s %s", p.First_Name, p.Last_Name);
            gotoxy(20, 20);
            printf("%c", p.Gender);
            gotoxy(30, 20);
            printf("%d", p.Age);
            gotoxy(40, 20);
            printf("%s", p.Address);
            gotoxy(60, 20);
            printf("%s", p.Contact_no);
            gotoxy(78, 20);
            printf("%s", p.Temperature);
            gotoxy(92, 20);
            printf("%s", p.SPO2);
            gotoxy(99, 20);
            printf("%s", p.Prescribed_Doctor);
            printf("\n");

            printf("\n\n\t\t\tSelect the Option to change the redcord is to be edited:");
            int option;
            printf("\n\n\t\t\t\t\t\t\t1. First Name");
            printf("\n\n\t\t\t\t\t\t\t2. Last Name");
            printf("\n\n\t\t\t\t\t\t\t3. Gender");
            printf("\n\n\t\t\t\t\t\t\t4. Age");
            printf("\n\n\t\t\t\t\t\t\t5. Address");
            printf("\n\n\t\t\t\t\t\t\t6. Contact No.");
            printf("\n\n\t\t\t\t\t\t\t7. Temperature");
            printf("\n\n\t\t\t\t\t\t\t8. SPO2");
            printf("\n\n\t\t\t\t\t\t\t9. Prescribed Doctor");
            printf("\n\n\n\t\t\t\t\t\t\t\t10.Edit Different Data");

            printf("\n\n\n\n\n\t\t\t\t\t\t\tChoose from 1 to 9...  ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
            J:
                printf("\n\n\n\n\t\t\tNew First Name: ");
                scanf("%s", p.First_Name);
                p.First_Name[0] = toupper(p.First_Name[0]);
                if (strlen(p.First_Name) > 20 || strlen(p.First_Name) < 2)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
                    printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
                    goto J;
                }
                else
                {
                    for (int i = 0; i < strlen(p.First_Name); i++)
                    {
                        if (isalpha(p.First_Name[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 0)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            goto J;
                        }
                    }
                }
                break;
            case 2:
            K:
                printf("\n\n\t\t\tNew Last Name: ");
                scanf("%s", p.Last_Name);
                p.Last_Name[0] = toupper(p.Last_Name[0]);
                if (strlen(p.Last_Name) > 20 || strlen(p.Last_Name) < 2)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
                    printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
                    goto K;
                }
                else
                {
                    for (int i = 0; i < strlen(p.Last_Name); i++)
                    {
                        if (isalpha(p.Last_Name[i]))
                        {
                            valid = 1;
                        }
                        else
                        {
                            valid = 0;
                            break;
                        }
                    }
                    if (valid == 0)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                        printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                        goto K;
                    }
                }
                break;
            case 3:
                do
                {
                    printf("\n\n\t\t\tGender[M/F]: ");
                    fflush(stdin);
                    scanf("%c", &p.Gender);
                    p.Gender = toupper(p.Gender);
                    fflush(stdin);
                    if (p.Gender == 'M' || p.Gender == 'F')
                    {
                        valid = 1;
                    }
                    else
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                        printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                        valid = 0;
                    }
                } while (valid == 0);
                break;
            case 4:
                printf("New Age: ");
                scanf("%d", &p.Age);
                break;
            case 6:
                do
                {
                    printf("\n\n\t\t\tContact NO.: ");
                    scanf("%s", p.Contact_no);
                    for (int i = 0; i < strlen(p.Contact_no); i++)
                    {
                        if (isalpha(p.Contact_no[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 1)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            break;
                        }
                    }

                } while (valid == 1);
                break;
            case 5:
                do
                {
                    printf("\n\n\t\t\tAddress: ");
                    scanf("%s", p.Address);
                    p.Address[0] = toupper(p.Address[0]);
                    if (strlen(p.Address) > 20 || strlen(p.Address) < 3)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
                        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
                        valid = 0;
                    }
                    else
                    {
                        valid = 1;
                    }
                } while (valid == 0);
                break;
            case 7:
                do
                {
                    printf("\n\n\t\t\tTemperatute(F): ");
                    scanf("%s", p.Temperature);
                    for (int i = 0; i < strlen(p.Temperature); i++)
                    {
                        if (isalpha(p.Temperature[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 1)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            break;
                        }
                    }

                } while (valid == 1);
                break;
            case 8:
                do
                {
                    printf("\n\n\t\t\tSPO2 Level: ");
                    scanf("%s", p.SPO2);
                    for (int i = 0; i < strlen(p.SPO2); i++)
                    {
                        if (isalpha(p.SPO2[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 1)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            break;
                        }
                    }

                } while (valid == 1);
                break;
            case 9:
            X:
                printf("\n\n\t\t\tPrescribed Doctor: ");
                scanf("%s", p.Prescribed_Doctor);
                p.Prescribed_Doctor[0] = toupper(p.Prescribed_Doctor[0]);
                if (strlen(p.Prescribed_Doctor) > 20 || strlen(p.Prescribed_Doctor) < 2)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
                    printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
                    goto X;
                }
                else
                {
                    for (int i = 0; i < strlen(p.Prescribed_Doctor); i++)
                    {
                        if (isalpha(p.Prescribed_Doctor[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 0)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            goto X;
                        }
                    }
                }
                break;
            case 10:
                Edit_rec();
                break;

            default:
                printf("\t\t\t Invalid Entry!!");
                printf("\n\n\t\t\t Please Enter Another Option :)");
                getch();
                fflush(stdin);
                Edit_rec();
                break;
            }
            fprintf(ft, "%s %s %c %d %s %s %s %s %s\n", p.First_Name,
                    p.Last_Name,
                    p.Gender,
                    p.Age,
                    p.Contact_no,
                    p.Address,
                    p.Temperature,
                    p.SPO2,
                    p.Prescribed_Doctor);
            printf("\n\n\t\t\t\t\t\t\tInformation Updated Sucessfully.....");
        }
        else
        {
            fprintf(ft, "%s %s %c %d %s %s %s %s %s\n", p.First_Name,
                    p.Last_Name,
                    p.Gender,
                    p.Age,
                    p.Contact_no,
                    p.Address,
                    p.Temperature,
                    p.SPO2,
                    p.Prescribed_Doctor);
        }
    }
    // if (valid != 1)
    // {
    //     printf("\n\n\n\n\t\t\tRecord not found :(");
    //     getch();
    // Z:
    //     printf("\n\n\n\n\t\t\tDo You want to edit more Records [Y/N]....?  ");
    //     scanf("%c", &ans);
    //     ans = toupper(ans);
    //     if (ans == 'Y')
    //     {
    //         Edit_rec();
    //     }
    //     if (ans == 'N')
    //     {
    //         // MainMenu();
    //         exit(0); /************************deleate me****************/
    //     }
    //     else
    //     {
    //         printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
    //         printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
    //         fflush(stdin);
    //         goto Z;
    //     }
    // }

    fclose(ek);
    fclose(ft);
    remove("Record2.dat");
    rename("temp2.dat", "Record2.dat");
    getch();
    MainMenu();
}

/***************************** DELETE RECORD************************************/
void Del_rec()
{
    system("cls");
    char Name[20];
    FILE *ek, *ft;
    ft = fopen("temp_Del.dat", "w+");
    ek = fopen("Record2.dat", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tDELETE PATIENTS RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    if (ek == NULL)
    {
        printf("\n\t Can't Open the File!!");
        getch();
        MainMenu();
    }

    printf("\n\n\nEnter the patients First Name of whose data is to be Deleted: ");
    scanf("%s", Name);
    Name[0] = toupper(Name[0]);

    if (ft == NULL)
    {
        printf("\n\t Can't Open the File!!");
        getch();
        MainMenu();
    }

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", p.First_Name,
                  p.Last_Name,
                  &p.Gender,
                  &p.Age,
                  p.Contact_no,
                  p.Address,
                  p.Temperature,
                  p.SPO2,
                  p.Prescribed_Doctor) != EOF)
    {
        if (strcmp(p.First_Name, Name) != 0)
        {
            fprintf(ft, "%s %s %c %d %s %s %s %s %s\n", p.First_Name,
                    p.Last_Name,
                    p.Gender,
                    p.Age,
                    p.Contact_no,
                    p.Address,
                    p.Temperature,
                    p.SPO2,
                    p.Prescribed_Doctor);
        }

        else
        {
            valid = 1;
            printf("\n\n\n\t\t\t\t\tExisting Data:");
            printf("\n\t\t----------------------------------------------------------------------");
            gotoxy(1, 17);
            printf("Full Name");
            gotoxy(20, 17);
            printf("Gender");
            gotoxy(30, 17);
            printf("Age");
            gotoxy(40, 17);
            printf("Address");
            gotoxy(60, 17);
            printf("Contact No.");
            gotoxy(78, 17);
            printf("Temperature");
            gotoxy(92, 17);
            printf("SPO2");
            gotoxy(99, 17);
            printf("Prescribed Doctor");
            printf("\n===========================================================================================================================\n");
            gotoxy(1, 20);
            printf("%s %s", p.First_Name, p.Last_Name);
            gotoxy(20, 20);
            printf("%c", p.Gender);
            gotoxy(30, 20);
            printf("%d", p.Age);
            gotoxy(40, 20);
            printf("%s", p.Address);
            gotoxy(60, 20);
            printf("%s", p.Contact_no);
            gotoxy(78, 20);
            printf("%s", p.Temperature);
            gotoxy(92, 20);
            printf("%s", p.SPO2);
            gotoxy(99, 20);
            printf("%s", p.Prescribed_Doctor);
            printf("\n");
            printf("\n\n\t\t\t\tRecord Deleted Sucessfully......");
        }
    }

    if (valid != 1)
    {
        printf("\n\n\n\n\t\t\tRecord not found :(");
        getch();
    }
    // while (1)
    // {
    //     fflush(stdin);
    //     printf("\n\n\n\n\t\t\tDo You want to edit more Records [Y/N]....?  ");
    //     scanf("%c", &ans);
    //     ans = toupper(ans);
    //     if (ans == 'Y')
    //     {
    //         Edit_rec();
    //     }
    //     if (ans == 'N')
    //     {
    //         MainMenu();
    //     }
    //     else
    //     {
    //         printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
    //         printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
    //         fflush(stdin);
    //     }
    // }

    fclose(ek);
    fclose(ft);
    remove("Record2.dat");
    rename("temp_Del.dat", "Record2.dat");
    getch();
    MainMenu();
}

/************************* EMPLOYEE ***********************************/

void Employee()
{
    MainMenuE();
}

/******************************************* MAIN MENU *************************************/
void MainMenuE()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3  MAIN MENU  \xB3\xB2=\xB2=\xB2-\xB3\n\n");

    int option;
    printf("\n\n\t\t\t\t\t\t\t1. Add employees Record");
    printf("\n\n\t\t\t\t\t\t\t2. List employees Record");
    printf("\n\n\t\t\t\t\t\t\t3. Search employees Record");
    printf("\n\n\t\t\t\t\t\t\t4. Edit employees Record");
    printf("\n\n\t\t\t\t\t\t\t5. Delete employees Record");
    printf("\n\n\t\t\t\t\t\t\t6. Exit");

    printf("\n\n\n\n\n\t\t\t\t\t\t\tChoose from 1 to 6...  ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        Add_recE();
        break;
    case 2:
        List_recE();
        break;
    case 3:
        search_recE();
        break;
    case 4:
        Edit_recE();
        break;
    case 5:
        Del_recE();
        break;
    case 6:
        first();
        break;
    default:
        printf("\t\t\t Invalid Entry!!");
        printf("\n\n\t\t\t Press Enter to choose Anathor Option :)");
        getch();
        MainMenuE();
    }
}
/********************************* ADD RECORD *************************************/
void Add_recE()
{
    system("cls");

    char ans;
    FILE *ek;
    ek = fopen("Record1.dat", "a");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tADD employees RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");

    /************************ FIRST NAME *********************************/

A: // We can also use do while loop instead of adding level(A:)

    printf("\n\n\n\n\t\t\tFirst Name: ");
    scanf("%s", e.First_Name);
    e.First_Name[0] = toupper(e.First_Name[0]);
    if (strlen(e.First_Name) > 20 || strlen(e.First_Name) < 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
        goto A;
    }
    else
    {
        for (int i = 0; i < strlen(e.First_Name); i++)
        {
            if (isalpha(e.First_Name[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 0)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                goto A;
            }
        }
    }
    /************************ Last NAME *********************************/

B:
    printf("\n\n\t\t\tLast Name: ");
    scanf("%s", e.Last_Name);
    e.Last_Name[0] = toupper(e.Last_Name[0]);
    if (strlen(e.Last_Name) > 20 || strlen(e.Last_Name) < 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
        goto B;
    }
    else
    {
        for (int i = 0; i < strlen(e.Last_Name); i++)
        {
            if (isalpha(e.Last_Name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (valid == 0)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
            goto B;
        }
    }

    /************************* GENDER ********************************/

    do
    {
        printf("\n\n\t\t\tGender[M/F]: ");
        fflush(stdin);
        scanf("%c", &e.Gender);
        e.Gender = toupper(e.Gender);
        fflush(stdin);
        if (e.Gender == 'M' || e.Gender == 'F')
        {
            valid = 1;
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
            valid = 0;
        }
    } while (valid == 0);

    /************************* AGE ********************************/

    printf("\n\n\t\t\tAge: ");
    scanf("%d", &e.Age);

    /************************ ADDRESS *********************************/

    do
    {
        printf("\n\n\t\t\tAddress: ");
        scanf("%s", e.Address);
        e.Address[0] = toupper(e.Address[0]);
        if (strlen(e.Address) > 20 || strlen(e.Address) < 3)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
            valid = 0;
        }
        else
        {
            valid = 1;
        }
    } while (valid == 0);

    /************************ CONTACT NUMBER ***************************/

    do
    {
        printf("\n\n\t\t\tContact NO.: ");
        scanf("%s", e.Contact_no);
        for (int i = 0; i < strlen(e.Contact_no); i++)
        {
            if (isalpha(e.Contact_no[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                break;
            }
        }

    } while (valid == 1);

    /****************************** Sallery **********************************/
    do
    {
        printf("\n\n\t\t\tSallery: ");
        scanf("%s", e.Sallery);
        for (int i = 0; i < strlen(e.Sallery); i++)
        {
            if (isalpha(e.Sallery[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                break;
            }
        }

    } while (valid == 1);

    /****************************** Adhar_No **********************************/

    printf("\n\n\t\t\tAdhar_No: ");
    scanf("%s", e.Adhar_No);

    /*************************************** Current Position *****************************/
D:

    printf("\n\n\t\t\tCurrent Position: ");
    scanf("%s", e.Current_Position);
    e.Current_Position[0] = toupper(e.Current_Position[0]);
    if (strlen(e.Current_Position) > 20 || strlen(e.Current_Position) < 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
        goto D;
    }
    else
    {
        for (int i = 0; i < strlen(e.Current_Position); i++)
        {
            if (isalpha(e.Current_Position[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 0)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                goto D;
            }
        }
    }

    /********** PRINTING INFORMAINION IN FILE ************/

    fprintf(ek, "%s %s %c %d %s %s %s %s %s\n", e.First_Name,
            e.Last_Name,
            e.Gender,
            e.Age,
            e.Contact_no,
            e.Address,
            e.Sallery,
            e.Adhar_No,
            e.Current_Position);
    printf("\nInformation Entered Sucessfully......");
    fclose(ek);

sd:
    getch();
    printf("\n\n\t\t\t\t\t\t\t\t\tDo You Want to Add more Records? [Y/N]...");
    fflush(stdin);
    scanf("%c", &ans);

    if (toupper(ans) == 'Y')
    {
        Add_recE();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\n\t\t\t\t\t\t\t\t\tThank You :) ");
        getch();
        MainMenuE();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Input :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Press [Y/N] :) ");
        goto sd;
    }
}
/****************************** LIST RECORD ********************/
void List_recE()
{
    int row;
    system("cls");
    FILE *ek;
    ek = fopen("Record1.dat", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tLIST employees RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    gotoxy(1, 15);
    printf("Full Name");
    gotoxy(20, 15);
    printf("Gender");
    gotoxy(30, 15);
    printf("Age");
    gotoxy(40, 15);
    printf("Address");
    gotoxy(60, 15);
    printf("Contact No.");
    gotoxy(78, 15);
    printf("Sallery");
    gotoxy(92, 15);
    printf("Adhar_No");
    gotoxy(110, 15);
    printf("Current Position");

    printf("\n============================================================================================================================================\n");

    row = 17;
    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", e.First_Name,
                  e.Last_Name,
                  &e.Gender,
                  &e.Age,
                  e.Contact_no,
                  e.Address,
                  e.Sallery,
                  e.Adhar_No,
                  e.Current_Position) != EOF)
    {
        gotoxy(1, row);
        printf("%s %s ", e.First_Name, e.Last_Name);
        gotoxy(20, row);
        printf("%c", e.Gender);
        gotoxy(30, row);
        printf("%d", e.Age);
        gotoxy(40, row);
        printf("%s", e.Address);
        gotoxy(60, row);
        printf("%s", e.Contact_no);
        gotoxy(78, row);
        printf("%s", e.Sallery);
        gotoxy(92, row);
        printf("%s", e.Adhar_No);
        gotoxy(110, row);
        printf("%s", e.Current_Position);
        row++;
    }
    fclose(ek);
    getch();
    MainMenuE();
}
/****************************** SEARCH RECORD ********************/
void search_recE()
{
    char Name[20];
    system("cls");
    FILE *ek;
    ek = fopen("Record1.dat", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tSearch employees RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    gotoxy(12, 8);
    printf("\nEnter the employees name of whose data is to be viewed: ");
    scanf("%s", Name);
    fflush(stdin);
    Name[0] = toupper(Name[0]);

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", e.First_Name,
                  e.Last_Name,
                  &e.Gender,
                  &e.Age,
                  e.Contact_no,
                  e.Address,
                  e.Sallery,
                  e.Adhar_No,
                  e.Current_Position) != EOF)
    {
        if (strcmp(e.First_Name, Name) == 0)
        {
            gotoxy(1, 15);
            printf("Full Name");
            gotoxy(20, 15);
            printf("Gender");
            gotoxy(30, 15);
            printf("Age");
            gotoxy(40, 15);
            printf("Address");
            gotoxy(60, 15);
            printf("Contact No.");
            gotoxy(78, 15);
            printf("Sallery");
            gotoxy(92, 15);
            printf("Adhar_No");
            gotoxy(110, 15);
            printf("Current Position");
            printf("\n===========================================================================================================================\n");
            gotoxy(1, 18);
            printf("%s %s", e.First_Name, e.Last_Name);
            gotoxy(20, 18);
            printf("%c", e.Gender);
            gotoxy(30, 18);
            printf("%d", e.Age);
            gotoxy(40, 18);
            printf("%s", e.Address);
            gotoxy(60, 18);
            printf("%s", e.Contact_no);
            gotoxy(78, 18);
            printf("%s", e.Sallery);
            gotoxy(92, 18);
            printf("%s", e.Adhar_No);
            gotoxy(110, 18);
            printf("%s", e.Current_Position);
            printf("\n");
            break;
        }
    }
    if (strcmp(e.First_Name, Name) != 0)
    {
        gotoxy(5, 10);
        printf("\n\n\n\n\t\t\tRecord not found :(");
        getch();
    }
    fclose(ek);

L:
    getch();
    printf("\n\n\n\n\t\t\tDo You want to search more Records [Y/N]....?  ");
    scanf("%c", &ans);
    ans = toupper(ans);
    if (ans == 'Y')
    {
        search_recE();
    }
    if (ans == 'N')
    {
        MainMenuE();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
        fflush(stdin);
        goto L;
    }
}

/************************************* EDIT RECORD ****************************************************************/
void Edit_recE()
{
    char Name[20];
    system("cls");
    FILE *ek, *ft;
    int i, b;
    ft = fopen("temp2.dat", "w+");
    ek = fopen("Record1.dat", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEDIT employees RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    if (ek == NULL)
    {
        printf("\n\t Can't Open the File!!");
        getch();
        // MainMenuE;
    }

    printf("\n\nEnter the employees First Name of whose data is to be Edited: ");
    scanf("%s", Name);
    fflush(stdin);
    Name[0] = toupper(Name[0]);

    if (ft == NULL)
    {
        printf("\n\t Can't Open the File!!");
        getch();
        MainMenuE;
    }

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", e.First_Name,
                  e.Last_Name,
                  &e.Gender,
                  &e.Age,
                  e.Contact_no,
                  e.Address,
                  e.Sallery,
                  e.Adhar_No,
                  e.Current_Position) != EOF)
    {
        if (strcmp(e.First_Name, Name) == 0)
        {
            valid = 1;
            printf("\n\n\n\t\t\t\t\tExisting Data:");
            printf("\n\t\t----------------------------------------------------------------------");
            gotoxy(1, 17);
            printf("Full Name");
            gotoxy(20, 17);
            printf("Gender");
            gotoxy(30, 17);
            printf("Age");
            gotoxy(40, 17);
            printf("Address");
            gotoxy(60, 17);
            printf("Contact No.");
            gotoxy(78, 17);
            printf("Sallery");
            gotoxy(92, 17);
            printf("Adhar_No");
            gotoxy(110, 17);
            printf("Current Position");
            printf("\n===========================================================================================================================\n");
            gotoxy(1, 20);
            printf("%s %s", e.First_Name, e.Last_Name);
            gotoxy(20, 20);
            printf("%c", e.Gender);
            gotoxy(30, 20);
            printf("%d", e.Age);
            gotoxy(40, 20);
            printf("%s", e.Address);
            gotoxy(60, 20);
            printf("%s", e.Contact_no);
            gotoxy(78, 20);
            printf("%s", e.Sallery);
            gotoxy(92, 20);
            printf("%s", e.Adhar_No);
            gotoxy(110, 20);
            printf("%s", e.Current_Position);
            printf("\n");

            printf("\n\n\t\t\tSelect the Option to change the redcord is to be edited:");
            int option;
            printf("\n\n\t\t\t\t\t\t\t1. First Name");
            printf("\n\n\t\t\t\t\t\t\t2. Last Name");
            printf("\n\n\t\t\t\t\t\t\t3. Gender");
            printf("\n\n\t\t\t\t\t\t\t4. Age");
            printf("\n\n\t\t\t\t\t\t\t5. Address");
            printf("\n\n\t\t\t\t\t\t\t6. Contact No.");
            printf("\n\n\t\t\t\t\t\t\t7. Sallery");
            printf("\n\n\t\t\t\t\t\t\t8. Adhar_No");
            printf("\n\n\t\t\t\t\t\t\t9. Current Position");
            printf("\n\n\n\t\t\t\t\t\t\t\t10.Edit Different Data");

            printf("\n\n\n\n\n\t\t\t\t\t\t\tChoose from 1 to 9...  ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
            J:
                printf("\n\n\n\n\t\t\tNew First Name: ");
                scanf("%s", e.First_Name);
                e.First_Name[0] = toupper(e.First_Name[0]);
                if (strlen(e.First_Name) > 20 || strlen(e.First_Name) < 2)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
                    printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
                    goto J;
                }
                else
                {
                    for (int i = 0; i < strlen(e.First_Name); i++)
                    {
                        if (isalpha(e.First_Name[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 0)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            goto J;
                        }
                    }
                }
                break;
            case 2:
            K:
                printf("\n\n\t\t\tNew Last Name: ");
                scanf("%s", e.Last_Name);
                e.Last_Name[0] = toupper(e.Last_Name[0]);
                if (strlen(e.Last_Name) > 20 || strlen(e.Last_Name) < 2)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
                    printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
                    goto K;
                }
                else
                {
                    for (int i = 0; i < strlen(e.Last_Name); i++)
                    {
                        if (isalpha(e.Last_Name[i]))
                        {
                            valid = 1;
                        }
                        else
                        {
                            valid = 0;
                            break;
                        }
                    }
                    if (valid == 0)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                        printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                        goto K;
                    }
                }
                break;
            case 3:
                do
                {
                    printf("\n\n\t\t\tGender[M/F]: ");
                    fflush(stdin);
                    scanf("%c", &e.Gender);
                    e.Gender = toupper(e.Gender);
                    fflush(stdin);
                    if (e.Gender == 'M' || e.Gender == 'F')
                    {
                        valid = 1;
                    }
                    else
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                        printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                        valid = 0;
                    }
                } while (valid == 0);
                break;
            case 4:
                printf("New Age: ");
                scanf("%d", &e.Age);
                break;
            case 6:
                do
                {
                    printf("\n\n\t\t\tContact NO.: ");
                    scanf("%s", e.Contact_no);
                    for (int i = 0; i < strlen(e.Contact_no); i++)
                    {
                        if (isalpha(e.Contact_no[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 1)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            break;
                        }
                    }

                } while (valid == 1);
                break;
            case 5:
                do
                {
                    printf("\n\n\t\t\tAddress: ");
                    scanf("%s", e.Address);
                    e.Address[0] = toupper(e.Address[0]);
                    if (strlen(e.Address) > 20 || strlen(e.Address) < 3)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
                        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
                        valid = 0;
                    }
                    else
                    {
                        valid = 1;
                    }
                } while (valid == 0);
                break;
            case 7:
                do
                {
                    printf("\n\n\t\t\tTemperatute(F): ");
                    scanf("%s", e.Sallery);
                    for (int i = 0; i < strlen(e.Sallery); i++)
                    {
                        if (isalpha(e.Sallery[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 1)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            break;
                        }
                    }

                } while (valid == 1);
                break;
            case 8:
                printf("\n\n\t\t\tNew Adhar_No: ");
                scanf("%s", e.Adhar_No);

                break;
            case 9:
            X:
                printf("\n\n\t\t\tCurrent Position: ");
                scanf("%s", e.Current_Position);
                e.Current_Position[0] = toupper(e.Current_Position[0]);
                if (strlen(e.Current_Position) > 20 || strlen(e.Current_Position) < 2)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
                    printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
                    goto X;
                }
                else
                {
                    for (int i = 0; i < strlen(e.Current_Position); i++)
                    {
                        if (isalpha(e.Current_Position[i]) == 0)
                        {
                            valid = 0;
                        }
                        else
                        {
                            valid = 1;
                        }
                        if (valid == 0)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                            goto X;
                        }
                    }
                }
                break;
            case 10:
                Edit_recE();
                break;

            default:
                printf("\t\t\t Invalid Entry!!");
                printf("\n\n\t\t\t Please Enter Another Option :)");
                getch();
                fflush(stdin);
                Edit_recE();
                break;
            }
            fprintf(ft, "%s %s %c %d %s %s %s %s %s\n", e.First_Name,
                    e.Last_Name,
                    e.Gender,
                    e.Age,
                    e.Contact_no,
                    e.Address,
                    e.Sallery,
                    e.Adhar_No,
                    e.Current_Position);
            printf("\n\n\t\t\t\t\t\t\tInformation Updated Sucessfully.....");
        }
        else
        {
            fprintf(ft, "%s %s %c %d %s %s %s %s %s\n", e.First_Name,
                    e.Last_Name,
                    e.Gender,
                    e.Age,
                    e.Contact_no,
                    e.Address,
                    e.Sallery,
                    e.Adhar_No,
                    e.Current_Position);
        }
    }
    // if (valid != 1)
    // {
    //     printf("\n\n\n\n\t\t\tRecord not found :(");
    //     getch();
    // Z:
    //     printf("\n\n\n\n\t\t\tDo You want to edit more Records [Y/N]....?  ");
    //     scanf("%c", &ans);
    //     ans = toupper(ans);
    //     if (ans == 'Y')
    //     {
    //         Edit_recE();
    //     }
    //     if (ans == 'N')
    //     {
    //         // MainMenuE();
    //         exit(0); /************************deleate me****************/
    //     }
    //     else
    //     {
    //         printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
    //         printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
    //         fflush(stdin);
    //         goto Z;
    //     }
    // }

    fclose(ek);
    fclose(ft);
    remove("Record1.dat");
    rename("temp2.dat", "Record1.dat");
    getch();
    MainMenuE();
}

/***************************** DELETE RECORD************************************/
void Del_recE()
{
    system("cls");
    char Name[20];
    FILE *ek, *ft;
    ft = fopen("temp_Del.dat", "w+");
    ek = fopen("Record1.dat", "r");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tDELETE employees RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    if (ek == NULL)
    {
        printf("\n\t Can't Open the File!!");
        getch();
        MainMenuE();
    }

    printf("\n\n\nEnter the employees First Name of whose data is to be Deleted: ");
    scanf("%s", Name);
    Name[0] = toupper(Name[0]);

    if (ft == NULL)
    {
        printf("\n\t Can't Open the File!!");
        getch();
        MainMenuE();
    }

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s\n", e.First_Name,
                  e.Last_Name,
                  &e.Gender,
                  &e.Age,
                  e.Contact_no,
                  e.Address,
                  e.Sallery,
                  e.Adhar_No,
                  e.Current_Position) != EOF)
    {
        if (strcmp(e.First_Name, Name) != 0)
        {
            fprintf(ft, "%s %s %c %d %s %s %s %s %s\n", e.First_Name,
                    e.Last_Name,
                    e.Gender,
                    e.Age,
                    e.Contact_no,
                    e.Address,
                    e.Sallery,
                    e.Adhar_No,
                    e.Current_Position);
        }

        else
        {
            valid = 1;
            printf("\n\n\n\t\t\t\t\tExisting Data:");
            printf("\n\t\t----------------------------------------------------------------------");
            gotoxy(1, 17);
            printf("Full Name");
            gotoxy(20, 17);
            printf("Gender");
            gotoxy(30, 17);
            printf("Age");
            gotoxy(40, 17);
            printf("Address");
            gotoxy(60, 17);
            printf("Contact No.");
            gotoxy(78, 17);
            printf("Sallery");
            gotoxy(92, 17);
            printf("Adhar_No");
            gotoxy(110, 17);
            printf("Current Position");
            printf("\n===========================================================================================================================\n");
            gotoxy(1, 20);
            printf("%s %s", e.First_Name, e.Last_Name);
            gotoxy(20, 20);
            printf("%c", e.Gender);
            gotoxy(30, 20);
            printf("%d", e.Age);
            gotoxy(40, 20);
            printf("%s", e.Address);
            gotoxy(60, 20);
            printf("%s", e.Contact_no);
            gotoxy(78, 20);
            printf("%s", e.Sallery);
            gotoxy(92, 20);
            printf("%s", e.Adhar_No);
            gotoxy(110, 20);
            printf("%s", e.Current_Position);
            printf("\n");
            printf("\n\n\t\t\t\tRecord Deleted Sucessfully......");
        }
    }

    if (valid != 1)
    {
        printf("\n\n\n\n\t\t\tRecord not found :(");
        getch();
    }
    // while (1)
    // {
    //     fflush(stdin);
    //     printf("\n\n\n\n\t\t\tDo You want to edit more Records [Y/N]....?  ");
    //     scanf("%c", &ans);
    //     ans = toupper(ans);
    //     if (ans == 'Y')
    //     {
    //         Edit_recE();
    //     }
    //     if (ans == 'N')
    //     {
    //         MainMenuE();
    //     }
    //     else
    //     {
    //         printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
    //         printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
    //         fflush(stdin);
    //     }
    // }

    fclose(ek);
    fclose(ft);
    remove("Record1.dat");
    rename("temp_Del.dat", "Record1.dat");
    getch();
    MainMenuE();
}

/************** VACCINATION SYSTEM *****************************/
void Vaccination_system()
{
    MainMenuV();
}

void MainMenuV()
{
    system("cls");
    // Title();
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3  MAIN MENU  \xB3\xB2=\xB2=\xB2-\xB3\n\n");

    int option;
    printf("\n\n\t\t\t\t\t\t\t1. Add Record");
    printf("\n\n\t\t\t\t\t\t\t2. List Record");
    printf("\n\n\t\t\t\t\t\t\t3. Vaccination Status");
    printf("\n\n\t\t\t\t\t\t\t4. Exit");

    printf("\n\n\n\n\n\t\t\t\t\t\t\tChoose from 1 to 6...  ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        Add_recV();
        break;
    case 2:
        List_recV();
        break;
    case 3:
        Vaccination_status();
        break;
    case 4:
        first();
        break;
    default:
        printf("\t\t\t Invalid Entry!!");
        printf("\n\n\t\t\t Press Enter to choose Anathor Option :)");
        getch();
        MainMenuV();
    }
}

/******************* ADD RECORD *************************************/
void Add_recV()
{
    system("cls");

    char ans;
    FILE *ek, *ft, *vc;
    ek = fopen("Record3.dat", "a");
    ft = fopen("temp2.dat", "w+");
    FILE *va;
    va = fopen("Vaccination_record.dat", "r+");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tADD PERSONS RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");

    /************************ FIRST NAME *********************************/

A: // We can also use do while loop instead of adding level(A:)

    printf("\n\n\n\n\t\t\tFirst Name: ");
    scanf("%s", v.First_Name);
    v.First_Name[0] = toupper(v.First_Name[0]);
    if (strlen(v.First_Name) > 20 || strlen(v.First_Name) < 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
        goto A;
    }
    else
    {
        for (int i = 0; i < strlen(v.First_Name); i++)
        {
            if (isalpha(v.First_Name[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 0)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                goto A;
            }
        }
    }
    /************************ Last NAME *********************************/

B:
    printf("\n\n\t\t\tLast Name: ");
    scanf("%s", v.Last_Name);
    v.Last_Name[0] = toupper(v.Last_Name[0]);
    if (strlen(v.Last_Name) > 20 || strlen(v.Last_Name) < 2)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
        goto B;
    }
    else
    {
        for (int i = 0; i < strlen(v.Last_Name); i++)
        {
            if (isalpha(v.Last_Name[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (valid == 0)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
            goto B;
        }
    }

    /************************* GENDER ********************************/

    do
    {
        printf("\n\n\t\t\tGender[M/F]: ");
        fflush(stdin);
        scanf("%c", &v.Gender);
        v.Gender = toupper(v.Gender);
        fflush(stdin);
        if (v.Gender == 'M' || v.Gender == 'F')
        {
            valid = 1;
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
            valid = 0;
        }
    } while (valid == 0);

    /************************* AGE ********************************/

    printf("\n\n\t\t\tAge: ");
    scanf("%d", &v.Age);

    /************************ ADDRESS *********************************/

    do
    {
        printf("\n\n\t\t\tAddress: ");
        scanf("%s", v.Address);
        v.Address[0] = toupper(v.Address[0]);
        if (strlen(v.Address) > 20 || strlen(v.Address) < 3)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Entry :( ");
            printf("\n\n\t\t\t\t\t\t\t\t\t Range must be between 1 to 20 :) ");
            valid = 0;
        }
        else
        {
            valid = 1;
        }
    } while (valid == 0);

    /************************ CONTACT NUMBER ***************************/

    do
    {
        printf("\n\n\t\t\tContact NO.: ");
        scanf("%s", v.Contact_no);
        for (int i = 0; i < strlen(v.Contact_no); i++)
        {
            if (isalpha(v.Contact_no[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                break;
            }
        }

    } while (valid == 1);

    /****************************** Adhar_No **********************************/
    do
    {
        printf("\n\n\t\t\tAdhar Number: ");
        scanf("%s", v.Adhar_No);
        for (int i = 0; i < strlen(v.Adhar_No); i++)
        {
            if (isalpha(v.Adhar_No[i]) == 0)
            {
                valid = 0;
            }
            else
            {
                valid = 1;
            }
            if (valid == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Invalid character :( ");
                printf("\n\n\t\t\t\t\t\t\t\t\t Try Again :) ");
                break;
            }
        }

    } while (valid == 1);

    fscanf(va, "%d", &a.Available_vaccine);
    a.Available_vaccine--;
    fprintf(ft, "%d", a.Available_vaccine);
    fclose(va);
    fclose(ft);
    remove("vaccination_record.dat");
    rename("temp2.dat", "vaccination_record.dat");

    /********** PRINTING INFORMAINION IN FILE ************/

    fprintf(ek, "%s %s %c %d %s %s %s\n", v.First_Name,
            v.Last_Name,
            v.Gender,
            v.Age,
            v.Contact_no,
            v.Address,
            v.Adhar_No);
    printf("\nInformation Entered Sucessfully......");
    fclose(ek);

sd:
    getch();
    printf("\n\n\t\t\t\t\t\t\t\t\tDo You Want to Add more Records? [Y/N]...");
    fflush(stdin);
    scanf("%c", &ans);

    if (toupper(ans) == 'Y')
    {
        Add_recV();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\n\t\t\t\t\t\t\t\t\tThank You :) ");
        getch();
        MainMenuV();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t Invalid Input :( ");
        printf("\n\n\t\t\t\t\t\t\t\t\t Press [Y/N] :) ");
        goto sd;
    }
}
/****************************** LIST RECORD ********************/
void List_recV()
{
    int row;
    system("cls");
    FILE *ek, *va;
    ek = fopen("Record3.dat", "r");
    va = fopen("vaccination_record.dat", "w+");
    printf("\n\n\n\t\t\t\t\t\t\t\t________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tLIST personS RECORD");
    printf("\n\t\t\t\t\t\t\t\t________________________________________________________________");
    gotoxy(1, 15);
    printf("Full Name");
    gotoxy(20, 15);
    printf("Gender");
    gotoxy(30, 15);
    printf("Age");
    gotoxy(40, 15);
    printf("Address");
    gotoxy(60, 15);
    printf("Contact No.");
    gotoxy(78, 15);
    printf("Adhar_No");

    printf("\n=============================================================================================================================\n");

    row = 17;
    while (fscanf(ek, "%s %s %c %d %s %s %s\n", v.First_Name,
                  v.Last_Name,
                  &v.Gender,
                  &v.Age,
                  v.Contact_no,
                  v.Address,
                  v.Adhar_No) != EOF)
    {
        gotoxy(1, row);
        printf("%s %s ", v.First_Name, v.Last_Name);
        gotoxy(20, row);
        printf("%c", v.Gender);
        gotoxy(30, row);
        printf("%d", v.Age);
        gotoxy(40, row);
        printf("%s", v.Address);
        gotoxy(60, row);
        printf("%s", v.Contact_no);
        gotoxy(78, row);
        printf("%s", v.Adhar_No);
        row++;
    }

    fclose(ek);
    getch();
    MainMenuV();
}

/********* VACCINATION STATUS ***********************/

void Vaccination_status()
{

    FILE *va;
    va = fopen("vaccination_record.dat", "r");
    fscanf(va, "%d", &a.Available_vaccine);
    printf("\n\n\t\t\tAvailable Vaccines: %d ", a.Available_vaccine);
    printf("\n\n\t\t\tNumber of people vaccinated: %d ", (200 - a.Available_vaccine));
    getch();
    MainMenuV();
}

/*********** BILLING SYSTEM *************************/

void Billing_System()
{
    system("cls");
    const double Hydrocodone_PRICE = 500.00;
    const double Aspirin_PRICE = 48.00;
    const double taxRate = 8.25;

    int AmoxicillinQTY;
    int LisinoprilQTY;
    int HydrocodoneQTY;
    int AspirinQTY;

    float total_Amoxicillin;
    float total_Lisinopril;
    float total_Hydrocodone;
    float total_Aspirin;
    float subTotal;
    float tax;
    float bill_Amount;
    char name[250];
    char cname[250];

    //	Statements

    printf("\n\n\t\t\t\t\t\t\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3  Pharmacy Bill  \xB3\xB2=\xB2=\xB2-\xB3\n\n");

    printf("\n\n\t\t\tCashier's Name: ");
    scanf("%s", name);
    printf("\n\n\t\t\tCustomer's Name: ");
    scanf("%s", cname);

    printf("\n\n\n\t Please Enter the Quantity of following Drugs \n\n");
    printf("\n\n\t\t\tAmoxicillins: ");
    scanf("%d", &AmoxicillinQTY);

    printf("\n\n\t\t\tLisinopril: ");
    scanf("%d", &LisinoprilQTY);

    printf("\n\n\t\t\tHydrocodones: ");
    scanf("%d", &HydrocodoneQTY);

    printf("\n\n\t\t\tAspirin: ");
    scanf("%d", &AspirinQTY);

    printf("\n\n\t Press Any Key To Generate Bill");
    getch();

    printf("\n\n\t\t\t\t\tBill Generated. \n\n");

    total_Amoxicillin = AmoxicillinQTY * Amoxicillin_PRICE;
    total_Lisinopril = LisinoprilQTY * Lisinopril_PRICE;
    total_Hydrocodone = HydrocodoneQTY * Hydrocodone_PRICE;
    total_Aspirin = AspirinQTY * Aspirin_PRICE;
    subTotal = total_Amoxicillin + total_Lisinopril + total_Hydrocodone + total_Aspirin;
    tax = (subTotal * taxRate) / 100;
    bill_Amount = subTotal + tax;

    //	Printing Bills
    printf("\n");
    printf("\t\t\t====================================================\n");
    printf("\t\t\t\t      Pharmacy Store Bill\n");
    printf("\t\t\t====================================================\n");
    printf("\t\t\tQTY \t Description \t  Unit Price$\t Total Price$\n");
    printf("\t\t\t--- \t ----------- \t  ---------- \t -----------\n\n");
    printf("\t\t\t%02d  \t Amoxicillin       %.2f      %10.2f  \n", AmoxicillinQTY, Amoxicillin_PRICE, total_Amoxicillin);
    printf("\t\t\t%02d   \t Lisinopril        %.2f      %10.2f   \n", LisinoprilQTY, Lisinopril_PRICE, total_Lisinopril);
    printf("\t\t\t%02d    \t Hydrocodone       %.2f    %10.2f    \n", HydrocodoneQTY, Hydrocodone_PRICE, total_Hydrocodone);
    printf("\t\t\t%02d     \t Aspirin           %.2f      %10.2f     \n\n", AspirinQTY, Aspirin_PRICE, total_Aspirin);
    printf("\t\t\t                                           ---------\n\n");
    printf("\t\t\t                           SUBTOTAL       %10.2f   \n", subTotal);
    printf("\t\t\t                           TAX            %10.2f    \n", tax);
    printf("\t\t\t                           Total$         %10.2f     \n", bill_Amount);
    printf("\t\t\t                           Customer         %s     \n", cname);
    printf("\t\t\t                           Cashier          %s     \n", name);
    printf("\t\t\t====================================================\n\n");
    printf("\t\t\t\t\t\tEnd of bill\n\n");
    getch();
    first();
}