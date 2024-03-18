#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

void header();  //Function prototypes;
void Entry();
void menu();
void adminSignup();
void adminLogin();
void employeeSignup();
void employeeLogin();
void addEmployee(char*);
void list(char*);
void searchEmployee(char *);
void modifyEmployee(char *);
void deleteEmployee(char *);
void sortByName(char *);

void blackD()  {  printf("\033[1;30m");  }  //Functions to change colour of text.
void redD()    {  printf("\033[1;31m");  }
void greenD()  {  printf("\033[1;32m");  }
void yellowD() {  printf("\033[1;33m");  }
void blueD()   {  printf("\033[1;34m");  }
void purpleD() {  printf("\033[1;35m");  }
void cyanD()   {  printf("\033[1;36m");  }
void whiteD()  {  printf("\033[1;37m");  }
void resetD()  {  printf("\033[1m");     }

void blackL()  {  printf("\033[0;30m");  }
void redL()    {  printf("\033[0;31m");  }
void greenL()  {  printf("\033[0;32m");  }
void yellowL() {  printf("\033[0;33m");  }
void blueL()   {  printf("\033[0;34m");  }
void purpleL() {  printf("\033[0;35m");  }
void cyanL()   {  printf("\033[0;36m");  }
void whiteL()  {  printf("\033[0;37m");  }
void resetL()  {  printf("\033[0m");     }

typedef struct
{
    char fname[15], lname[15], ID[20], num[15];
    int age, noOfProjects, iniSalary, curSalary;
    struct date
    {
        int d, m, y;
    }date;
}employee;

void header()
{
    redD();
    printf("\n\t########################################################");
    printf("\n\t####\t");

    yellowD();
    printf("\"");

    purpleD();
    printf("Welcome to Employee Management Service");

    yellowD();
    printf("\"    ");
    
    redD();
    printf("####\n");
    printf("\t########################################################\n");
    resetL();
}

void Entry()
{
    int choice, sOrL;
    time_t t;
    time(&t);
    
    while(1)
    {
        greenD();
        printf("\n");

        yellowD();
        printf("\t\t\t                               %s\n", ctime(&t));

        whiteD();
        printf("\n\t---------------------");

        redD();
        printf("MAIN MENU");

        whiteD();
        printf("---------------------\n\n");
        
        greenD();
        printf("\tEmployee enter \" 1 \"\n");
        printf("\tAdmin enter    \" 2 \"\n");
        printf("\tTo exit enter  \" 0 \"\n\n");

        whiteD();
        printf("\t---------------------------------------------------\n\n");
        
        blueD();
        printf("\tYour choice: ");
        scanf("%d",&choice);
    
        if(choice == 1)  //Employee entry.
        {
            while(1)
            {
                purpleD();
                printf("\n\tWelcome for Employee Section:\n");

                greenD();
                printf("\t\tTo signup enter \" 1 \"\n");
                printf("\t\tTo login enter  \" 2 \"\n");
                printf("\t\tTo exit         \" 0 \"\n");
                printf("\t\tTo menu enter   \" 3 \"\n");

                redD();
                printf("\t\tYour choice: ");

                blueD();
                scanf("%d", &sOrL);
                resetL();

                if(sOrL == 1)
                {
                    employeeSignup();
                    break;
                }

                else if(sOrL == 2)
                {
                    employeeLogin();
                    break;
                }

                else if(sOrL == 0)
                {
                    system("cls");
                    yellowD();
                    printf("\n\t-------------------- ");

                    whiteD();
                    printf("Thank you  Have a nice day");

                    yellowD();
                    printf(" --------------------\n\n");
                    resetL();
                    exit(0);
                }

                else if(sOrL == 3)
                {
                    break;
                }

                else
                {
                    yellowD();
                    printf("\n\t\" ");

                    redD();
                    printf("Invalid entry......Try again....");

                    yellowD();
                    printf(" \"\n\n");
                    resetL();
                    sleep(3);
                }
            }
        }

        else if(choice == 2)  //Admin.
        {
            while(1)
            {
                purpleD();
                printf("\n\tWelcome for Admin Section:\n");
                
                greenD();
                printf("\t\tTo signup enter \" 1 \"\n");
                printf("\t\tTo login enter  \" 2 \"\n");
                printf("\t\tTo exit         \" 0 \"\n");
                printf("\t\tTo menu enter   \" 3 \"\n");

                redD();
                printf("\t\tYour choice: ");

                blueD();
                scanf("%d", &sOrL);
                resetL();

                if(sOrL == 1)  //Signing up.
                {
                    adminSignup();
                    break;
                }

                else if(sOrL == 2)  //Login.
                {
                    adminLogin();
                    break;
                }

                else if(sOrL == 0)  //Exit.
                {
                    system("cls");
                    yellowD();
                    printf("\n\t-------------------- ");

                    whiteD();
                    printf("Thank you  Have a nice day");

                    yellowD();
                    printf(" --------------------\n\n");
                    resetL();
                    exit(0);
                }

                else if(sOrL == 3)  //Menu.
                {
                    break;
                }

                else  //Invalid input.
                {
                    yellowD();
                    printf("\n\t\" ");

                    redD();
                    printf("Invalid entry......Try again....");

                    yellowD();
                    printf(" \"\n\n");
                    resetL();
                    sleep(3);
                }
            }
        }

        else if(choice == 0)  //Exit.
        {
            system("cls");
            yellowD();
            printf("\n\t-------------------- ");

            whiteD();
            printf("Thank you  Have a nice day");

            yellowD();
            printf(" --------------------\n\n");
            resetL();
            exit(0);
        }

        else  //Invalid input.
        {
            yellowD();
            printf("\n\t\" ");

            redD();
            printf("Invalid entry......Try again....");

            yellowD();
            printf(" \"\n\n");
            resetL();
            sleep(3);
        }
    }
}

void menu()  //Opening menu.
{
    int choice, dept, flag = 0;
    greenD();
    printf("\n");

    while(1)
    {
        purpleD();
        printf("\n\t\tAdmin menu:\n");

        greenD();
        printf("\t\tTo see list of employees enter:     \"1\"\n");
        printf("\t\tTo add employee details enter:      \"2\"\n");
        printf("\t\tTo modify existing details enter:   \"3\"\n");
        printf("\t\tTo search for an employee enter:    \"4\"\n");
        printf("\t\tTo delete enter:                    \"5\"\n");
        printf("\t\tTo main menu enter:                 \"6\"\n");
        printf("\t\tTo exit enter:                      \"0\"\n\n");
        
        redD();
        printf("\t\tYour choice: ");

        blueD();
        scanf("%d", &choice);
        resetL();

        if(choice == 6)
        {
            break;
        }

        else if(choice == 0)  //Exit.
        {
            system("cls");
            yellowD();
            printf("\n\t-------------------- ");

            whiteD();
            printf("Thank you  Have a nice day");

            yellowD();
            printf(" --------------------\n\n");
            resetL();
            exit(0);
        }

        switch(choice)
        {
            case 1:  //Listing the data.
            {
                while(1)
                {
                    redD();
                    printf("\n\t\tEnter department:\n");

                    greenD();
                    printf("\t\t\t1. Sales\n");
                    printf("\t\t\t2. Marketing\n");
                    printf("\t\t\t3. Finance\n");
                    printf("\t\t\t4. Exit\n");
                    printf("\n");

                    redD();
                    printf("\t\t\tYour choice: ");

                    blueD();
                    scanf("%d", &dept);
                    resetL();

                    if(dept == 1)
                    {
                        flag = 1;
                        list("sales");
                    }

                    else if(dept == 2)
                    {
                        flag = 1;
                        list("marketing");
                    }

                    else if(dept == 3)
                    {
                        flag = 1;
                        list("finance");
                    }

                    else if(dept == 4)
                    {
                        yellowD();
                        printf("\n\t--------------------");

                        whiteD();
                        printf("Thank you  Have a nice day");

                        yellowD();
                        printf("\n\t--------------------");
                        resetL();
                        exit(0);
                    }

                    else
                    {
                        yellowD();
                        printf("\n\t\" ");

                        redD();
                        printf("Invalid entry for department......Try again....");

                        yellowD();
                        printf(" \"\n\n");
                        resetL();
                        sleep(3);
                    }

                    if(flag == 1)
                    {
                        break;
                    }
                }
                break;
            }

            case 2:  //Add the data.
            {
                while(1)
                {
                    redD();
                    printf("\n\t\tEnter department:\n\n");

                    greenD();
                    printf("\t\t\t1. Sales\n");
                    printf("\t\t\t2. Marketing\n");
                    printf("\t\t\t3. Finance\n");
                    printf("\t\t\t4. Exit\n");
                    printf("\n");

                    redD();
                    printf("\t\t\tYour choice: ");

                    blueD();
                    scanf("%d", &dept);
                    resetL();

                    if(dept == 1)
                    {
                        flag = 1;
                        addEmployee("sales");
                    }

                    else if(dept == 2)
                    {
                        flag = 1;
                        addEmployee("marketing");
                    }

                    else if(dept == 3)
                    {
                        flag = 1;
                        addEmployee("finance");
                    }

                    else if(dept == 4)
                    {
                        yellowD();
                        printf("\n\t--------------------");

                        whiteD();
                        printf("Thank you  Have a nice day");

                        yellowD();
                        printf("\n\t--------------------");
                        resetL();
                        exit(0);
                    }

                    else
                    {
                        yellowD();
                        printf("\n\t\" ");

                        redD();
                        printf("Invalid entry for department......Try again....");

                        yellowD();
                        printf(" \"\n\n");
                        resetL();
                        sleep(3);
                    }

                    if(flag == 1)
                    {
                        break;
                    }
                }
                break;
            }

            case 3:  //Modify the data.
            {
                while(1)
                {
                    redD();
                    printf("\n\t\tEnter department:\n");

                    greenD();
                    printf("\t\t\t1. Sales\n");
                    printf("\t\t\t2. Marketing\n");
                    printf("\t\t\t3. Finance\n");
                    printf("\t\t\t4. Exit\n");
                    printf("\n");

                    redD();
                    printf("\t\t\tYour choice: ");

                    blueD();
                    scanf("%d", &dept);
                    resetL();

                    if(dept == 1)
                    {
                        flag = 1;
                        modifyEmployee("sales");
                    }

                    else if(dept == 2)
                    {
                        flag = 1;
                        modifyEmployee("marketing");
                    }

                    else if(dept == 3)
                    {
                        flag = 1;
                        modifyEmployee("finance");
                    }

                    else if(dept == 4)
                    {
                        yellowD();
                        printf("\n\t--------------------");

                        whiteD();
                        printf("Thank you  Have a nice day");

                        yellowD();
                        printf("\n\t--------------------");
                        resetL();
                        exit(0);
                    }

                    else
                    {
                        yellowD();
                        printf("\n\t\" ");

                        redD();
                        printf("Invalid entry for department......Try again....");

                        yellowD();
                        printf(" \"\n\n");
                        resetL();
                        sleep(3);
                    }

                    if(flag == 1)
                    {
                        break;
                    }
                }
                break;
            }

            case 4:  //Search the data.
            {
                while(1)
                {
                    redD();
                    printf("\n\t\tEnter department:\n");

                    greenD();
                    printf("\t\t\t1. Sales\n");
                    printf("\t\t\t2. Marketing\n");
                    printf("\t\t\t3. Finance\n");
                    printf("\t\t\t4. Exit\n");
                    printf("\n");

                    redD();
                    printf("\t\t\tYour choice: ");

                    blueD();
                    scanf("%d", &dept);
                    resetL();

                    if(dept == 1)
                    {
                        flag = 1;
                        searchEmployee("sales");
                    }

                    else if(dept == 2)
                    {
                        flag = 1;
                        searchEmployee("marketing");
                    }

                    else if(dept == 3)
                    {
                        flag = 1;
                        searchEmployee("finance");
                    }

                    else if(dept == 4)
                    {
                        yellowD();
                        printf("\n\t--------------------");

                        whiteD();
                        printf("Thank you  Have a nice day");

                        yellowD();
                        printf("\n\t--------------------");
                        resetL();
                        exit(0);
                    }

                    else
                    {
                        yellowD();
                        printf("\n\t\" ");

                        redD();
                        printf("Invalid entry for department......Try again....");

                        yellowD();
                        printf(" \"\n\n");
                        resetL();
                        sleep(3);
                    }

                    if(flag == 1)
                    {
                        break;
                    }
                }
                break;
            }

            case 5:  //Delete the data.
            {
                while(1)
                {
                    redD();
                    printf("\n\t\tEnter department:\n");

                    greenD();
                    printf("\t\t\t1. Sales\n");
                    printf("\t\t\t2. Marketing\n");
                    printf("\t\t\t3. Finance\n");
                    printf("\t\t\t4. Exit\n");
                    printf("\n");

                    redD();
                    printf("\t\t\tYour choice: ");

                    blueD();
                    scanf("%d", &dept);
                    resetL();

                    if(dept == 1)
                    {
                        flag = 1;
                        deleteEmployee("sales");
                    }

                    else if(dept == 2)
                    {
                        flag = 1;
                        deleteEmployee("marketing");
                    }

                    else if(dept == 3)
                    {
                        flag = 1;
                        deleteEmployee("finance");
                    }

                    else if(dept == 4)
                    {
                        yellowD();
                        printf("\n\t--------------------");

                        whiteD();
                        printf("Thank you  Have a nice day");

                        yellowD();
                        printf("\n\t--------------------");
                        resetL();
                        exit(0);
                    }

                    else
                    {
                        yellowD();
                        printf("\n\t\" ");

                        redD();
                        printf("Invalid entry for department......Try again....");

                        yellowD();
                        printf(" \"\n\n");
                        resetL();
                        sleep(3);
                    }

                    if(flag == 1)
                    {
                        break;
                    }
                }
                break;
            }

            default :  //If user enters wrong input.
            {
                yellowD();
                printf("\n\n\t\" ");

                redD();
                printf("Invalid entry for menu options....Try again!");

                yellowD();
                printf(" \"\n");
                resetL();
            }
        }
    }
}

void adminSignup()
{
    FILE *admSign;
    char username[20], password[10];
    admSign = fopen("adminSignup.txt", "a+");
    if(admSign == NULL)  //Checking for proper opening of file.
    {
        yellowD();
        printf("\n\t\" ");

        redD();
        printf("Admin Signup file open unsuccessful!.....");

        yellowD();
        printf(" \"\n\n");

        resetL();
        exit(0);
    }

    redD();
    printf("\n\n\t\tEnter username: ");

    blueD();
    scanf("%s", username);

    redD();
    printf("\t\tEnter password: ");

    blueD();
    scanf("%s", password);

    fprintf(admSign, "%s %s\n", username, password);

    yellowD();
    printf("\n\t----------------------- ");

    blueD();
    printf("Admin signup successfull");

    yellowD();
    printf(" ------------------------\n\n");
    resetL();
    fclose(admSign);
    sleep(2);
}

void adminLogin()
{
    FILE *admLogin;
    int flag = 0;
    char username[20], password[10], usernamefile[20], passwordfile[10];
    admLogin = fopen("adminSignup.txt", "a+");

    redD();
    printf("\n\t\tEnter username: ");

    blueD();
    scanf("%s", username);

    redD();
    printf("\t\tEnter password: ");
    
    blueD();
    scanf("%s", password);

    while(!feof(admLogin))
    {
        fscanf(admLogin, "%s %s", usernamefile, passwordfile);
        if(feof(admLogin))
        {
            break;
        }

        if(strcmp(usernamefile, usernamefile) == 0 && strcmp(password, passwordfile) == 0)
        {
            yellowD();
            printf("\n\t-----------------------------------");

            whiteD();
            printf("Admin login successfull");

            yellowD();
            printf("---------------------------------------\n\n");
            resetL();
            sleep(1);
            fclose(admLogin);
            flag = 1;
            menu();
            break;
        }
    }

    if(flag == 0)  //Wrong input for admin login.
    {
        yellowD();
        printf("\n\t\t\t\" ");

        redD();
        printf("No such admin ID");

        yellowD();
        printf(" \"\n\n");
        resetL();
        sleep(2);
        fclose(admLogin);
    }
}

void employeeSignup()
{
    FILE *Es;
    char username[20], password[10];
    Es = fopen("employeeSignup.txt", "a+");
    if(Es == NULL)  //Checking for proper opening of file.
    {
        yellowD();
        printf("\n\t\" ");

        redD();
        printf("Signup file open unsuccessful!.....");

        yellowD();
        printf(" \"\n\n");

        resetL();
        exit(0);
    }

    redD();
    printf("\n\n\t\tEnter username: ");

    blueD();
    scanf("%s", username);

    redD();
    printf("\t\tEnter password(8 characters of your choice): ");

    blueD();
    scanf("%s", password);

    fprintf(Es, "%s %s\n", username, password);

    yellowD();
    printf("\n\t\t\t-------------------------------------");

    blueD();
    printf("Employee signup successfull");

    yellowD();
    printf(" ---------------------------------------------\n\n");

    resetL();
    fclose(Es);
    sleep(2);
}

void employeeLogin()
{
    FILE *L, *sales, *mark, *finance;
    employee empL;
    char username[20], password[20], usernameFile[20], passwordfile[10];
    int loginCheck = 0, dept, fileCheck = 0, IDCheck = 0;
    L = fopen("employeeSignup.txt", "r");
    if(L == NULL)  //Checking for proper opening of file.
    {
        yellowD();
        printf("\n\t\" ");

        redD();
        printf("Signup file open unsuccessful! while opening for login.....");

        yellowD();
        printf(" \"\n\n");
        resetL();
        exit(0);
    }

    redD();
    printf("\n\n\t\tEnter username: ");

    blueD();
    scanf("%s", username);
    
    redD();
    printf("\t\tEnter password: ");

    blueD();
    scanf("%s", password);
    resetL();

    while(!(feof(L)))
    {
        fscanf(L, "%s %s", usernameFile, passwordfile);
        if(feof(L))
        {
            break;
        }

        if(strcmp(username, usernameFile) == 0 && strcmp(password, passwordfile) == 0)
        {
            yellowD();
            printf("\n\t------------------- ");

            greenD();
            printf("Login successfull");

            yellowD();
            printf(" ----------------------\n\n");
            resetL();
            fclose(L);
            sleep(2);

            while(1)
            {
                redD();
                printf("\tEnter your department:\n");

                greenD();
                printf("\t\t1. Sales\n");
                printf("\t\t2. Marketing\n");
                printf("\t\t3. Finance\n\n");
                
                redD();
                printf("\tYour choice: ");

                blueD();
                scanf("%d", &dept);
                resetL();

                if(dept == 1)
                {
                    sales = fopen("sales", "r");
                    if(sales == NULL)
                    {
                        yellowD();
                        printf("\n\t\" ");

                        redD();
                        printf("Sales department file open unsuccessful!.....");

                        yellowD();
                        printf(" \"\n\n");
                        resetL();
                        exit(0);
                    }

                    while(!feof(sales))
                    {
                        fileCheck = 1;
                        fscanf(sales, "%s %s %s %d %s %d %d %d %d %d %d", empL.ID, empL.fname, empL.lname, &empL.age, empL.num, &empL.date.d, &empL.date.m, &empL.date.y, &empL.iniSalary, &empL.curSalary, &empL.noOfProjects);
                        if(feof(sales))
                        {
                            break;
                        }
                        if(strcmp(username, empL.ID) == 0)
                        {
                            IDCheck = 1;
                            purpleL();
                            printf("\nWelcome:\n");

                            purpleD();
                            printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
                            
                            redD();
                            printf("%-10s%-15s%-15s%-5s%-13s%-15s%-13s%-17s%-10s\n\n","ID","First name","Last name","Age","Number","Joining date","initial pay","Current salary","Projects");
                            
                            cyanD();
                            printf("%-10s%-15s%-15s%-5d%-13s%-.2d/%-.2d/%-9d%-13d%-17d%-10d\n", empL.ID, empL.fname, empL.lname, empL.age, empL.num, empL.date.d, empL.date.m, empL.date.y, empL.iniSalary, empL.curSalary, empL.noOfProjects);
                            
                            purpleD();
                            printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
                            resetL();
                            sleep(2);
                            break;
                        }
                    }
                    fclose(sales);
                    if(IDCheck == 0)
                    {
                        yellowD();
                        printf("\n\t<<<<<<<<<  ");
                        
                        redD();
                        printf("No such username found");

                        yellowD();
                        printf("  >>>>>>>>>>>>\n\n");
                        resetL();
                        sleep(1);
                    }
                    break;
                }

                else if(dept == 2)
                {
                    mark = fopen("marketing", "r");
                    if(mark == NULL)
                    {
                        yellowD();
                        printf("\n\t\" ");

                        redD();
                        printf("Marketing department file open unsuccessful!.....");

                        yellowD();
                        printf(" \"\n\n");
                        resetL();
                        exit(0);
                    }

                    while(!feof(mark))
                    {
                        fileCheck = 1;
                        fscanf(mark, "%s %s %s %d %s %d %d %d %d %d %d", empL.ID, empL.fname, empL.lname, &empL.age, empL.num, &empL.date.d, &empL.date.m, &empL.date.y, &empL.iniSalary, &empL.curSalary, &empL.noOfProjects);
                        if(feof(mark))
                        {
                            break;
                        }
                        if(strcmp(username, empL.ID) == 0)
                        {
                            IDCheck = 1;
                            purpleL();
                            printf("\nWelcome:\n");

                            purpleD();
                            printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
                            
                            redD();
                            printf("%-10s%-15s%-15s%-5s%-13s%-15s%-13s%-17s%-10s\n\n","ID","First name","Last name","Age","Number","Joining date","initial pay","Current salary","Projects");
                            
                            cyanD();
                            printf("%-10s%-15s%-15s%-5d%-13s%-.2d/%-.2d/%-9d%-13d%-17d%-10d\n", empL.ID, empL.fname, empL.lname, empL.age, empL.num, empL.date.d, empL.date.m, empL.date.y, empL.iniSalary, empL.curSalary, empL.noOfProjects);
                            
                            purpleD();
                            printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
                            resetL();
                            sleep(2);
                            break;
                        }
                    }
                    fclose(mark);
                    if(IDCheck == 0)
                    {
                        yellowD();
                        printf("\n\t<<<<<<<<<  ");
                        
                        redD();
                        printf("No such username found");

                        yellowD();
                        printf("  >>>>>>>>>>>>\n\n");
                        resetL();
                        sleep(1);
                    }
                    break;
                }

                else if(dept == 3)
                {
                    finance = fopen("finance", "r");
                    if(finance == NULL)
                    {
                        yellowD();
                        printf("\n\t\" ");

                        redD();
                        printf("Finance department file open unsuccessful!.....");

                        yellowD();
                        printf(" \"\n\n");
                        resetL();
                        exit(0);
                    }

                    while(!feof(finance))
                    {
                        fileCheck = 1;
                        fscanf(finance, "%s %s %s %d %s %d %d %d %d %d %d", empL.ID, empL.fname, empL.lname, &empL.age, empL.num, &empL.date.d, &empL.date.m, &empL.date.y, &empL.iniSalary, &empL.curSalary, &empL.noOfProjects);
                        if(feof(finance))
                        {
                            break;
                        }
                        if(strcmp(username, empL.ID) == 0)
                        {
                            IDCheck = 1;
                            purpleL();
                            printf("\nWelcome:\n");

                            purpleD();
                            printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
                            
                            redD();
                            printf("%-10s%-15s%-15s%-5s%-13s%-15s%-13s%-17s%-10s\n\n","ID","First name","Last name","Age","Number","Joining date","initial pay","Current salary","Projects");
                            
                            cyanD();
                            printf("%-10s%-15s%-15s%-5d%-13s%-.2d/%-.2d/%-9d%-13d%-17d%-10d\n", empL.ID, empL.fname, empL.lname, empL.age, empL.num, empL.date.d, empL.date.m, empL.date.y, empL.iniSalary, empL.curSalary, empL.noOfProjects);
                            
                            purpleD();
                            printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
                            resetL();
                            sleep(2);
                            break;
                        }
                    }
                    fclose(finance);
                    if(IDCheck == 0)
                    {
                        yellowD();
                        printf("\n\t<<<<<<<<<  ");
                        
                        redD();
                        printf("No such username found");

                        yellowD();
                        printf("  >>>>>>>>>>>>\n\n");
                        resetL();
                        sleep(1);
                    }
                    /*if(empL.ID == "")
                    {
                        redD();
                        printf("\n\tNo content is available in this file.\n\n");
                    }*/
                    break;
                }

                else
                {
                    yellowD();
                    printf("\n\t\t\" ");

                    redD();
                    printf("No such department, check your input");

                    yellowD();
                    printf(" \"\n\n");
                    resetL();
                    sleep(3);
                }
            }

            loginCheck = 1;
            break;
        }
    }

    if(loginCheck == 0)  //Login failed.
    {
        fclose(L);
        yellowD();
        printf("\n\t\" ");

        redD();
        printf("Username and password doesn't match......");

        yellowD();
        printf(" \"\n\n");
        resetL();
        exit(0);
    }
}

void addEmployee(char *dept)
{
    FILE *add;
    employee empadd;

    add = fopen(dept, "a+");
    if(add == NULL)  //Checking whether file opened successfully or not.
    {
        yellowD();
        printf("\n\t\" ");

        redD();
        printf("%s department file open unsuccessful!.....",dept);

        yellowD();
        printf(" \"\n\n");

        resetL();
        exit(0);
    }

    yellowD();
    printf("\n\t\"");

    greenD();
    printf(" Adding a new member ");

    yellowD();
    printf("\"\n\n");

    redD();
    printf("Enter username(no space involved, should be same as in signup): ");

    blueD();
    scanf("%s",empadd.ID);
    fprintf(add, "%s ", empadd.ID);

    redD();
    printf("Enter first name: ");

    blueD();
    scanf("%s", empadd.fname);
    fprintf(add, "%s ", empadd.fname);

    redD();
    printf("Enter last name: ");

    blueD();
    scanf("%s", empadd.lname);
    fprintf(add, "%s ", empadd.lname);
            
    redD();
    printf("Enter age: ");

    blueD();
    scanf("%d", &empadd.age);
    fprintf(add, "%d ", empadd.age);

    redD();
    printf("Enter phone number: ");

    blueD();
    scanf("%s", empadd.num);
    fprintf(add, "%s ", empadd.num);

    redD();
    printf("Enter date of joining (d m yy): ");

    blueD();
    scanf("%d %d %d", &empadd.date.d, &empadd.date.m, &empadd.date.y);
    fprintf(add, "%d %d %d ", empadd.date.d, empadd.date.m, empadd.date.y);
            
    redD();
    printf("Enter initial pay: ");

    blueD();
    scanf("%d", &empadd.iniSalary);
    fprintf(add, "%d ", empadd.iniSalary);

    redD();
    printf("Enter current salary: ");

    blueD();
    scanf("%d", &empadd.curSalary);
    fprintf(add, "%d ", empadd.curSalary);

    redD();
    printf("Enter number of projects he/she worked: ");

    blueD();
    scanf("%d",&empadd.noOfProjects);
    fprintf(add, "%d\n", empadd.noOfProjects);
    resetL();
    fclose(add);
    sortByName(dept);
    sleep(1);
}

void list(char *dept)  //Function to list all employees.
{
    int i = 1;
    employee emp;
    FILE *lE;  //File pointer to open a file and list all details.

    lE = fopen(dept, "r");
    if(lE == NULL)  //Checking whether file opened successfully or not.
    {
        yellowD();
        printf("\n\t\" ");

        redD();
        printf("%s department file open unsuccessful!.....",dept);

        yellowD();
        printf(" \"\n\n");

        resetL();
        exit(0);
    }

    purpleL();
    printf("\n%s department employee List:\n",dept);

    purpleD();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
        
    printf("%-6s%-10s%-15s%-15s%-5s%-13s%-15s%-13s%-17s%-10s\n\n","S.No","ID","First name","Last name","Age","Number","Joining date","initial pay","Current salary","Projects");
        
    cyanD();
    while(!feof(lE))
    {
        fscanf(lE, "%s %s %s %d %s %d %d %d %d %d %d", emp.ID, emp.fname, emp.lname, &emp.age, emp.num, &emp.date.d, &emp.date.m, &emp.date.y, &emp.iniSalary, &emp.curSalary, &emp.noOfProjects);
        if(feof(lE))
        {
            break;
        }
        printf("%-6d%-10s%-15s%-15s%-5d%-13s%-.2d/%-.2d/%-9d%-13d%-17d%-10d\n", i, emp.ID, emp.fname, emp.lname, emp.age, emp.num, emp.date.d, emp.date.m, emp.date.y, emp.iniSalary, emp.curSalary, emp.noOfProjects);
        i++;
    }
    printf("\n");

    purpleD();
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fclose(lE);
    resetL();
    sleep(1);
}

void searchEmployee(char *dept)  //Function to search an employee by giving his/her id.
{
    int flag = 0;
    char search_ID[20];
    employee emp;
    FILE *sE;
    sE = fopen(dept, "r");  //Opening file in read mode.
    if(sE == NULL)  //Checking whether file opened successfully or not.
    {
        yellowD();
        printf("\n\t\" ");

        redD();
        printf("%s department file open unsuccessful!.....",dept);

        yellowD();
        printf(" \"\n\n");
        resetL();
        exit(0);
    }

    redD();
    printf("Enter ID/username to search: ");

    blueD();
    scanf("%s", search_ID);

    while(!feof(sE))
    {
        fscanf(sE, "%s %s %s %d %s %d %d %d %d %d %d", emp.ID, emp.fname, emp.lname, &emp.age, emp.num, &emp.date.d, &emp.date.m, &emp.date.y, &emp.iniSalary, &emp.curSalary, &emp.noOfProjects);
        if(strcmp(emp.ID, search_ID) == 0)
        {
            flag += 1;
            break;
        }
    }

    if(flag != 0)  //Checking whether ID found or not.
    {
        redL();
        printf("\nSearch result:\n");

        redD();
        printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("%-10s%-15s%-15s%-5s%-13s%-15s%-13s%-17s%-10s\n\n","ID","First name","Last name","Age","Number","Joining date","initial pay","Current salary","Projects");
        
        cyanD();
        printf("%-10s%-15s%-15s%-5d%-13s%-.2d/%-.2d/%-9d%-13d%-17d%-10d\n\n", emp.ID, emp.fname, emp.lname, emp.age, emp.num, emp.date.d, emp.date.m, emp.date.y, emp.iniSalary, emp.curSalary, emp.noOfProjects);
        
        redD();
        printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
        resetL();
        sleep(1);
    }
    else
    {
        yellowD();
        printf("\n\t-------------------------------------- ");

        redD();
        printf("The requested ID was not found!......");

        yellowD();
        printf(" ---------------------------------------------\n");
        resetL();
        sleep(1);
    }
    fclose(sE);
}

void modifyEmployee(char *dept)
{
    char modify_ID[20];
    int rem, ren, ID_flag = 0;
    employee emp;
    FILE *modify, *new;

    redD();
    printf("\n\tEnter username of employee to modify the data: ");

    cyanD();
    scanf("%s", modify_ID);

    modify = fopen(dept, "r");  //Opening original file.
    if(modify == NULL)
    {
        yellowD();
        printf("\n\t----------------------------------- ");

        redD();
        printf("%s department file open unsuccessfull",dept);

        yellowD();
        printf(" ---------------------------------------\n\n");
        resetL();
    }

    new = fopen("temp_staff_details", "w");  //Opening new file.
    if(new == NULL)
    {
        yellowD();
        printf("\n\t------------------------------------------- ");

        redD();
        printf("New File open unsuccessfull");

        yellowD();
        printf(" --------------------------------------------\n\n");
        resetL();
    }

    while(!feof(modify))
    {
        fscanf(modify, "%s %s %s %d %s %d %d %d %d %d %d", emp.ID, emp.fname, emp.lname, &emp.age, emp.num, &emp.date.d, &emp.date.m, &emp.date.y, &emp.iniSalary, &emp.curSalary, &emp.noOfProjects);
        if(feof(modify))
        {
            break;
        }

        if(strcmp(modify_ID, emp.ID) == 0)
        {
            ID_flag = 1;
            redD();
            printf("\n\tInput new details\n");
            printf("\tEnter first name: ");

            blueD();
            scanf("%s", emp.fname);
            //gets(emp.name);

            redD();
            printf("\tEnter last name: ");

            blueD();
            scanf("%s", emp.lname);

            redD();
            printf("\tEnter ID(no space involved): ");

            blueD();
            scanf("%s",emp.ID);

            redD();
            printf("\tEnter age: ");

            blueD();
            scanf("%d",&emp.age);

            redD();
            printf("\tEnter phone number: ");

            blueD();
            scanf("%s", emp.num);

            redD();
            printf("\tEnter number of projects worked: ");

            blueD();
            scanf("%d",&emp.noOfProjects);

            redD();
            printf("\tEnter initial salary: ");

            blueD();
            scanf("%d",&emp.iniSalary);

            redD();
            printf("\tEnter yearly increment: ");

            blueD();
            scanf("%d",&emp.curSalary);

            redD();
            printf("\tEnter date of joining(date month year): ");

            blueD();
            scanf("%d %d %d", &emp.date.d, &emp.date.m, &emp.date.y);
            resetL();

            fprintf(new, "%s %s %s %d %s %d %d %d %d %d %d\n", emp.ID, emp.fname, emp.lname, emp.age, emp.num, emp.date.d, emp.date.m, emp.date.y, emp.iniSalary, emp.curSalary, emp.noOfProjects);
        }
        else
        {
            fprintf(new, "%s %s %s %d %s %d %d %d %d %d %d\n", emp.ID, emp.fname, emp.lname, emp.age, emp.num, emp.date.d, emp.date.m, emp.date.y, emp.iniSalary, emp.curSalary, emp.noOfProjects);
        }
    }

    if(ID_flag == 0)
    {
        yellowD();
        printf("\n\t----------------------- ");

        redD();
        printf("Entered ID not found");

        yellowD();
        printf(" ---------------------------\n\n");
        resetL();
    }

    fclose(modify);
    fclose(new);

    rem = remove(dept);  //Removing original file. " rem " returns 0 if successfull.
    ren = rename("temp_staff_details", dept);  //Renaming new file to original file name. " ren " returns 0 if successfull.
    resetL();
}

void deleteEmployee(char *dept)
{
    char del_ID[20];
    int rem, ren, flag = 0;
    employee emp;
    FILE *delete, *new;
    redD();
    printf("Enter ID/username of employee to delete: ");

    cyanD();
    scanf("%s", del_ID);

    delete = fopen(dept, "r");  //Opening original file.
    if(delete == NULL)
    {
        yellowD();
        printf("\n\t-------------------- ");

        redD();
        printf("File open unsuccessfull");

        yellowD();
        printf(" -----------------------\n\n");
        resetL();
    }

    new = fopen("new_staff_details", "w");  //Opening new file.
    if(new == NULL)
    {
        yellowD();
        printf("\n\t----------------------------- ");

        redD();
        printf("File open unsuccessfull");

        yellowD();
        printf(" -------------------------------\n\n");
        resetL();
    }

    while(!feof(delete))
    {
        fscanf(delete, "%s %s %s %d %s %d %d %d %d %d %d", emp.ID, emp.fname, emp.lname, &emp.age, emp.num, &emp.date.d, &emp.date.m, &emp.date.y, &emp.iniSalary, &emp.curSalary, &emp.noOfProjects);
        if(feof(delete))
        {
            break;
        }

        if(strcmp(del_ID, emp.ID) != 0)
        {
            fprintf(new, "%s %s %s %d %s %d %d %d %d %d %d\n", emp.ID, emp.fname, emp.lname, emp.age, emp.num, emp.date.d, emp.date.m, emp.date.y, emp.iniSalary, emp.curSalary, emp.noOfProjects);
        }

        else
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        yellowD();
        printf("\n\t------------------------ ");

        redD();
        printf("No such ID/username");

        yellowD();
        printf(" --------------------------\n\n");
        resetL();
    }

    fclose(delete);
    fclose(new);

    rem = remove(dept);  //Removing original file. " rem " returns 0 if successfull.
    ren = rename("new_staff_details", dept);  //Renaming new file to original file name. " ren " returns 0 if successfull.
    resetL();
}

void sortByName(char *dept)
{
    FILE *sort;
    int count = 0, i,  j;
    employee emp, temp;
    sort = fopen(dept, "r");
    if(sort == NULL)
    {
        yellowD();
        printf("\n\t----------------------------- ");

        redD();
        printf("File open unsuccessfull");

        yellowD();
        printf(" -------------------------------\n\n");
        resetL();
    }

    while(!feof(sort))  //Finding number of lines in the file " dept ".
    {
        fscanf(sort, "%s %s %s %d %s %d %d %d %d %d %d", emp.ID, emp.fname, emp.lname, &emp.age, emp.num, &emp.date.d, &emp.date.m, &emp.date.y, &emp.iniSalary, &emp.curSalary, &emp.noOfProjects);
        if(feof(sort))
        {
            break;
        }
        count++;
    }

    employee emparr[count];
    rewind(sort);
    for(i = 0;i < count;i++)  //Storing input in " emparr " structure.
    {
        fscanf(sort, "%s %s %s %d %s %d %d %d %d %d %d", emp.ID, emp.fname, emp.lname, &emp.age, emp.num, &emp.date.d, &emp.date.m, &emp.date.y, &emp.iniSalary, &emp.curSalary, &emp.noOfProjects);
        emparr[i] = emp;
    }
    fclose(sort);

    for(i = 0;i < count - 1;i++)  //Sorting alphabetically.
    {
        for(j = i;j < count;j++)
        {
            if(strcmpi(emparr[i].fname, emparr[j].fname) > 0)
            {
                temp = emparr[i];
                emparr[i] = emparr[j];
                emparr[j] = temp;
            }
        }
    }

    sort = fopen(dept, "w");
    for(i = 0;i < count;i++)
    {
        fprintf(sort, "%s %s %s %d %s %d %d %d %d %d %d\n", emparr[i].ID, emparr[i].fname, emparr[i].lname, emparr[i].age, emparr[i].num, emparr[i].date.d, emparr[i].date.m, emparr[i].date.y, emparr[i].iniSalary, emparr[i].curSalary, emparr[i].noOfProjects);
    }

    fclose(sort);
}

int main()
{
    header();  //Welcome page.
    Entry();
    return 0;
}
