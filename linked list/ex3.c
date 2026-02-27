#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
#include <malloc.h>

typedef struct employee
{
    int EmpID;
    char Name[50];
    int YearOfJoining; //year
    char department[15];
    float Salary;
    struct employee *next; //next is pointer
}employee;

employee *start = NULL;

employee *createEmployee(int id, char name[],char dept[], float salary, int year);
void addEmployee(int id, char name[],char dept[], float salary, int year);
void deleteEmployee(int id);
void updateSalary(int id, float salary);
void displayEmployee();
void searchEmplyee(int id);
void sortEmployee();
void findHighLow();

int main() {
  int option, id,year;
  char name[50], dept[50];
  float salary;
  while(1)
  {
    printf("\n\n *****company database *****");
    printf("\n 1: add employee:");
    printf("\n 2: delete employee by ID:");
    printf("\n 3: update_salary salary: ");
    printf("\n 4. display the employee");
    printf("\n 5. search by ID:");
    printf("\n 6. sort employee by joining year: ");
    printf("\n 7. find for high paid and least paid ");
    printf("\n 8. EXIT ");

    printf("\nenter your option:");
    scanf("%d", &option);

    switch(option)
    {
        case 1: 
        printf("enter employeeID , name, department,salary, joining year  ");
        scanf("%d %s %s %f %d", &id, name, dept, &salary, &year );
        addEmployee(id, name, dept, salary, year);
        break;

        case 2:
        printf("enter the ID to delete:");
        scanf("%d", &id);
        deleteEmployee(id);
        break;

        case 3:
        printf("enter ID & new salary:");
        scanf("%d %f", &id, &salary);
        updateSalary(id, salary);
        break;

        case 4:
        displayEmployee();
        break;

        case 5:
        printf("enter ID to search:");
        scanf("%d", &id);
        searchEmplyee(id);
        break;

        case 6:
        sortEmployee();
        displayEmployee();
        // printf("year: %f", &YearOfJoining);
        break;

        case 7:
        findHighLow();
        break;

        case 8:
        exit;

        default:
        printf("invalid option");
        break;
    }
  }
 return 0;
}

employee *createEmployee(int id, char name[],char dept[], float salary, int year)
{
    employee *newEmp = (employee *) malloc (sizeof(employee));
    newEmp -> EmpID = id;
    strcpy(newEmp -> Name, name);
    strcpy(newEmp -> department, dept);
    newEmp-> Salary = salary;
    newEmp-> YearOfJoining= year;
    newEmp -> next =NULL;
    return newEmp;
}

void addEmployee(int id, char name[],char dept[], float salary, int year){
    // employee *temp = start , *prev = NULL;
    // while(temp != NULL && temp -> EmpID != id)
    // {
    //     prev = temp;
    //     temp = temp -> next;
    // }
    // if(temp ==NULL)
    // {
    //     printf("Employee not found!\n");
    //     return;
    // }
    // if(prev ==NULL)
    //     start = temp-> next;
    // else
    //     prev -> next = temp -> next;
    //     free (temp);
    // printf("employee delete successfully");
    employee *newEmp= createEmployee(id,name,dept,salary,year);
    newEmp->next =start;
    start= newEmp;
    printf("employee added successfully\n");
}

void deleteEmployee(int id)
{
    employee *temp= start, *prev= NULL;
    while(temp != NULL && temp-> EmpID != id)
    {
        prev= temp;
        temp= temp->next;
    }
    if(temp == NULL)
    {
        printf("employee not found\n");
        return;
    }
    if(prev == NULL){
        start = temp-> next;
    }
    else
        prev->next= temp->next;
        free(temp);
        printf("employee delete successfully\n");
}

// void updateSalary(int id)
// {
//     employee *emp = searchEmplyee(id);
//     if(!emp) return;
//     printf("enter new salary:");
//     scanf("%f", &emp-> Salary);
//     printf("salary updated");
// }

void updateSalary(int id, float newSalary){
    employee *temp = start;
   
    while(temp != NULL)
    {
        if(temp -> EmpID == id)
        {
            temp->Salary = newSalary;
            printf("salary updated successfully\n");
            return;
        }
        temp= temp-> next;
    }
    printf("employee not found");
}

void displayEmployee(){
    employee * temp = start;
    if(temp == NULL){
        printf("no employee \n");
        return;
    }
    printf("\n employee list: \n");

    while(temp!= NULL){
    printf("\nID= %d | name= %s | dept= %s | salary= %f | year= %d", temp-> EmpID, temp-> Name, temp->department, temp-> Salary, temp-> YearOfJoining);
    temp= temp->next;
    }
}

void searchEmplyee(int id){
    employee *temp= start;
    while(temp != NULL){
        if(temp-> EmpID == id)
        {
            printf("found ID: %d | name: %s| dept: %s | salary: %.2f | year: %d\n",  temp-> EmpID, temp-> Name, temp->department, temp-> Salary, temp-> YearOfJoining);
            return;
        }
        // temp= temp->next;
    }
    printf("employee not found\n");
}

// void sortEmployee()
// {
//     employee *i, *j;
//     int temp;
//     for(i= start; i&& i-> next; i= i->next){
//         for(j=i->next;j!=NULL;j=j->next){
//             if(i->Salary > j-> Salary)
//             {
//                 temp = i-> Salary;
//                 i->Salary = j-> Salary;
//                 j-> Salary = temp;
//             }
//             // temp= temp->next;
//         }
//     }
//     printf("employee not found\n");
// }

void sortEmployee(){
    // newEmp->next = start;
    // start = newEmp;
    if(start== NULL)
    return;
    employee *i, *j;
    int temp;
    for(i= start; i-> next != NULL; i= i->next){
        for(j=i->next; j!=NULL; j=j->next){
            // printf("year: %f", &YearOfJoining);
            if(i->YearOfJoining > j-> YearOfJoining)
            {
            //swap data
            int tempID = i->EmpID;
            char tempName[50];
            char tempDept[15];
            float tempSalary = i-> Salary;
            int tempYear = i-> YearOfJoining;

            strcpy(tempName, i->Name);
            strcpy(tempDept, i->department);
            
            i->EmpID= j-> EmpID;
            strcpy(i->Name, j->Name);
            strcpy(i->department, j->department);
            i->Salary= j->Salary;
            i->YearOfJoining = j-> YearOfJoining;

            j->EmpID= tempID;
            strcpy(j->Name, tempName);
            strcpy(j->department, tempDept);
            j->Salary= tempSalary;
            j->YearOfJoining= tempYear;
        }
        }
    }
    printf("enter sorted by joining year:\n");
}

void findHighLow(){
    if(start == NULL){
        printf("no employee \n");
        return;
    }
    employee *temp= start;
    employee *high= start, *low = start;
    while(temp != NULL)
    {
        if(temp->Salary > high-> Salary) high= temp;
        if (temp->Salary < low-> Salary) low=temp;
        temp= temp->next;
    }
    printf("highest paid employee %s (%.2f)\n", high->Name, high-> Salary);
    printf("lowest paid:employee %s (%.2f)\n", low->Name,low->Salary);
}

// void sortEmployee()
// {
//     if(start == NULL){
//         printf("no employee \n");
//         return;
//     employee *temp= start;
//     employee *high= start, *low = start;

//     while(temp != NULL)
//     {
//         if(temp->Salary > high-> Salary) high= temp;
//         if (temp->Salary < low-> Salary) low=temp;
//     }
//     temp= temp->next;
//     printf("\nID= %d | name= %s | dept= %s | salary= %f | year= %d", temp-> EmpID, temp-> Name, temp->department, temp-> Salary, temp-> YearOfJoining);

//     // for(i= start; i&& i-> next; i= i->next){
//     //     for(j=i->next;j!=NULL;j=j->next){
//     //         if(i->Salary > j-> Salary)
//     //         {
//     //             temp = i-> Salary;
//     //             i->Salary = j-> Salary;
//     //             j-> Salary = temp;
//     //         }
//     //         // temp= temp->next;
//     //     }
//     // }
//     // printf("employee not found\n");
// }
// printf("employee not found\n");
// }