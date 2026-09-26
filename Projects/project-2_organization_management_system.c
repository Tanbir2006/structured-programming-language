
#include <stdio.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    char department[30];
    float salary;
};

struct Organisation
{
    char name[50];
    char location[50];

    int employeeCount;

    struct Employee employees[100];
};


// Function prototypes
void inputOrganisation(struct Organisation *org);
void addEmployee(struct Organisation *org);
void showOrganisation(struct Organisation org);
void showEmployees(struct Organisation org);
void searchEmployee(struct Organisation org);


int main()
{
    struct Organisation org;

    int choice;

    // Input basic organisation information
    inputOrganisation(&org);

    do
    {
        printf("\n=================================\n");
        printf("   ORGANISATION MANAGEMENT SYSTEM\n");
        printf("=================================\n");

        printf("1. Show Organisation Information\n");
        printf("2. Add Employee\n");
        printf("3. Show All Employees\n");
        printf("4. Search Employee\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                showOrganisation(org);
                break;

            case 2:
                addEmployee(&org);
                break;

            case 3:
                showEmployees(org);
                break;

            case 4:
                searchEmployee(org);
                break;

            case 5:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}


// Input organisation information
void inputOrganisation(struct Organisation *org)
{
    printf("Enter organisation name: ");
    scanf(" %[^\n]", org->name);

    printf("Enter location: ");
    scanf(" %[^\n]", org->location);

    org->employeeCount = 0;

    printf("\nOrganisation created successfully!\n");
}


// Add employee
void addEmployee(struct Organisation *org)
{
    int i = org->employeeCount;

    if(i >= 100)
    {
        printf("Employee limit reached!\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

    printf("Enter employee ID: ");
    scanf("%d", &org->employees[i].id);

    printf("Enter employee name: ");
    scanf(" %[^\n]", org->employees[i].name);

    printf("Enter department: ");
    scanf(" %[^\n]", org->employees[i].department);

    printf("Enter salary: ");
    scanf("%f", &org->employees[i].salary);

    org->employeeCount++;

    printf("\nEmployee added successfully!\n");
}


// Show organisation information
void showOrganisation(struct Organisation org)
{
    printf("\n--- Organisation Information ---\n");

    printf("Name     : %s\n", org.name);
    printf("Location : %s\n", org.location);
    printf("Employees: %d\n", org.employeeCount);
}


// Show all employees
void showEmployees(struct Organisation org)
{
    int i;

    if(org.employeeCount == 0)
    {
        printf("\nNo employees found.\n");
        return;
    }

    printf("\n--- Employee List ---\n");

    for(i = 0; i < org.employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);

        printf("ID         : %d\n", org.employees[i].id);
        printf("Name       : %s\n", org.employees[i].name);
        printf("Department : %s\n", org.employees[i].department);
        printf("Salary     : %.2f\n", org.employees[i].salary);
    }
}


// Search employee by ID
void searchEmployee(struct Organisation org)
{
    int id;
    int i;

    printf("\nEnter employee ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < org.employeeCount; i++)
    {
        if(org.employees[i].id == id)
        {
            printf("\n--- Employee Found ---\n");

            printf("ID         : %d\n", org.employees[i].id);
            printf("Name       : %s\n", org.employees[i].name);
            printf("Department : %s\n", org.employees[i].department);
            printf("Salary     : %.2f\n", org.employees[i].salary);

            return;
        }
    }

    printf("\nEmployee not found!\n");
}
