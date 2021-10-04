#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct emp
{
    char name[80];
    int emp_id;
    char join_date[10];
    int sal;
    char password[32];
    char des[10];

    struct personalinfo //personal information
    {
        char dob[10];
        int age;
        char blood_grp[10];
        char address[150];  //address of employee
        char emailid[20];   //Email id of employee
        char ph_no[10];     //employee phone number
        char emerph_no[10]; //employee's emergency phone number

    } pi; //Nested structure personal info variable creation

} emp;

int checkentry(int id, char password[32], FILE *fp)
{
    struct emp e;
    int recsize = sizeof(e);

    while (fread(&e, recsize, 1, fp)) // fetch all record from file
    {
        if ((e.emp_id == id) && strcmp(e.password, password) == 0) //if id and password matches
        {
            return 1;
        }
    }
    return 0;
}

int age(char a[10])
{
    int i;
    char c[10] = "";
    for (i = 0; i < 4; i++)
    {
        c[i] = a[i + 6];
    }
    int age = atoi(c);
    age = 2021 - age;
    return age;
}

int check_id(int no)
{
    FILE *fp;
    emp e;
    int c = 0;
    fp = fopen("emp.txt", "r");
    while (!feof(fp))
    {
        fread(&e, sizeof(e), 1, fp);

        if (no == e.emp_id)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void add()
{
    emp *e;
    FILE *fptr;
    int n = 1, i;
    e = (emp *)calloc(n, sizeof(emp));

    fptr = fopen("emp.txt", "a");

    for (i = 0; i < n; i++)
    {
        printf("\n Enter Employee Name :- ");
        scanf("%s", (e + i)->name);

        printf("\n Enter Employee id :- ");
        scanf("%d", &(e + i)->emp_id);

        printf("\n Enter Employee Joining Date (dd/mm/yyyy):- ");
        scanf("%s", (e + i)->join_date);

        printf("\n Enter Employee Date of birth (dd/mm/yyyy):- ");
        scanf("%s", (e + i)->pi.dob);

        printf("\n Enter Employee Salary :- ");
        scanf("%d", &(e + i)->sal);
        fflush(stdin);

        printf("\n Enter Password :- ");
        scanf("%s", (e + i)->password);
        char password[32];
        while (1)
        {
            printf("\n Confirm Password :- ");
            scanf("%s", password);

            if (strcmp((e + i)->password, password) == 0)
                break;
            else
            {
                printf("\n Enter Password :- ");
                scanf("%s", (e + i)->password);
            }
        }

        printf("\n Enter Employee Address :- ");
        scanf("%s", (e + i)->pi.address);

        printf("\n Enter Employee Email id :- ");
        scanf("%s", (e + i)->pi.emailid);

        printf("\n Enter Employee Phone number :- ");
        scanf("%s", (e + i)->pi.ph_no);

        printf("\n Enter Employee Emergency Phone number :- ");
        scanf("%s", (e + i)->pi.emerph_no);

        printf("\n Enter Employee blood group:- ");
        scanf("%s", (e + i)->pi.blood_grp);

        printf("\n Enter Designation:- ");
        scanf("%s", (e + i)->des);

        (e + i)->pi.age = age((e + i)->pi.dob);

        fwrite(&e[i], sizeof(emp), 1, fptr);
    }
    fclose(fptr);
}

void view()
{
    emp e1;
    FILE *fptr;

    fptr = fopen("emp.txt", "r");
    while (fread(&e1, sizeof(emp), 1, fptr))
    {

        printf("\n Employee name : %s ", e1.name);
        printf("\n Employee ID : %d ", e1.emp_id);
        printf("\n Employee Joining Date (dd/mm/yyyy) : %s ", e1.join_date);
        printf("\n Employee Salary : %d ", e1.sal);
        printf("\n Employee Designation: %s ", e1.des);
        printf("\n Employee Address : %s ", e1.pi.address);
        printf("\n Employee Email ID : %s ", e1.pi.emailid);
        printf("\n Employee Phone Number : %s ", e1.pi.ph_no);
        printf("\n Employee Emergency Phone Number : %s ", e1.pi.emerph_no);
        printf("\n Employee Date of birth (dd/mm/yyyy) : %s ", e1.pi.dob);
        printf("\n Employee Age: %d ", e1.pi.age);
        printf("\n Employee blood group : %s ", e1.pi.blood_grp);
        printf("\n Employee PASSWORD : %s\n\n", e1.password);
    }

    fclose(fptr);
}

void namesort()
{
    emp e1;
    FILE *fptr;

    char a[100][10], i;
    for (i = 0; i < 10; i++)
    {
        strcpy(a[i], " ");
    }

    i = 0;
    fptr = fopen("emp.txt", "r");
    while (fread(&e1, sizeof(emp), 1, fptr))
    {

        strcpy(a[i], e1.name);

        i = i + 1;
    }

    fclose(fptr);

    int j, count = 10;

    char temp[20];
    for (i = 0; i <= count; i++)
        for (j = i + 1; j <= count; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }

    for (i = 0; i < 10; i++)
    {

        printf("%d", strcmp("harish", a[i]));
    }
    printf("\n-----------------------");
    printf("\n|| ID\t|\tNAME\t\t\t", e1.emp_id, e1.name);
    printf("\n------------------------");
   
    for (i = 0; i < 11; i++)
    {
        fptr = fopen("emp.txt", "r");
        while (fread(&e1, sizeof(emp), 1, fptr))
        {
            int c = strcmp(e1.name,a[i]);
            if (c == 0)
            {

                printf("\n|| %d\t|\t%s\t||", e1.emp_id, e1.name);
            }
        }
        fclose(fptr);
    }
    printf("\n\n");
    
}

void idsort()
{
    emp e1;
    FILE *fptr;

    int a[100], i;
    for (i = 0; i < 100; i++)
    {
        a[i] = 0;
    }
    i = 0;
    fptr = fopen("emp.txt", "r");
    while (fread(&e1, sizeof(emp), 1, fptr))
    {

        a[i] = e1.emp_id;

        i = i + 1;
    }

    fclose(fptr);
    int j, n = 10;
    int temp;
    for (i = 0; i < n; ++i)
    {

        for (j = i + 1; j < n; ++j)
        {

            if (a[i] > a[j])
            {

                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\n-----------------------");
    printf("\n|| ID\t|\tNAME\t\t\t", e1.emp_id, e1.name);
    printf("\n------------------------");
    for (i = 0; i < 10; i++)
    {

        fptr = fopen("emp.txt", "r");
        while (fread(&e1, sizeof(emp), 1, fptr))
        {

            if (a[i] == e1.emp_id)
            {

                printf("\n|| %d\t|\t%s\t||", e1.emp_id, e1.name);
            }
        }
        fclose(fptr);
    }
    printf("\n\n");
}
void delete ()
{
    FILE *fp;
    FILE *fpt;
    emp e;
    int id, s;
    printf("Enter the Employee ID. you want to delete :");
    scanf("%d", &id);
    if (check_id(id) == 0)
        printf("Employee ID- %d is not available in the file\n", id);
    else
    {
        fp = fopen("emp.txt", "r");
        fpt = fopen("temp.txt", "w");
        while (fread(&e, sizeof(e), 1, fp))
        {
            s = e.emp_id;
            if (s != id)
                fwrite(&e, sizeof(e), 1, fpt);
        }
        fclose(fp);
        fclose(fpt);
        fp = fopen("emp.txt", "w");
        fpt = fopen("temp.txt", "r");
        while (fread(&e, sizeof(e), 1, fpt))
            fwrite(&e, sizeof(e), 1, fp);
        printf("\nRECORD DELETED\n");
        fclose(fp);
        fclose(fpt);
    }
}

void count()
{

    emp e;
    FILE *fp;
    fp = fopen("emp.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(emp);
    printf("Number of employees currently working are: %d\n", n);
    fclose(fp);
}

int main()
{
    while (1)
    {
        int choice;
        printf("\n\n\t\t\t************************************************");
        printf("\n\t  \t\t**                                            **");
        printf("\n\t  \t\t**      EMPLOYEE MANAGEMENT SOFTWARE          **");
        printf("\n\t  \t\t**                                            **");
        printf("\n\t\t\t************************************************\n");
        printf("\n\n 1. Add Record");
        printf("\n 2. List Records");
        printf("\n 3. Delete Records");
        printf("\n 4. Count Records");
        printf("\n 5. Search Records");
        printf("\n 6. Modify Records");
        printf("\n 7. Sort Records");
        printf("\n 8. Change password");
        printf("\n 9. Exit");
        printf("\n Your Choice: ");
        scanf("%d", &choice);
        if (choice == 1)
            add();
        if (choice == 2)
            view();
        if (choice == 3)
            delete ();
        if (choice == 4)
            count();
        if (choice == 7)
            idsort();
        if (choice == 9)
            namesort();

        system("pause");
    }
}
