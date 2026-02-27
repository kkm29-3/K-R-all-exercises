
// "Write manubase program to maintain employee database,where user can add,remove,modify each detalis of employee. 
// Employee detalis like Name,Date of Joinig,Birth date,Designation ,Salary."

#include<stdio.h>
#define MAX 100
struct employee
{
    int ID;
    char name[50];
    int doj[15];
    char department[15];
    float salary;
};

struct employee emp[MAX];
int count=0;

//functions
void addEmployee();
void displayEmployee();
void modifyEmployee();
void deleteEmployee();

int main(int argc, char *argv[])
{
    int choice;
    do{
        printf("\n---EmployeeDatabase-----\n");
        printf("1. add employee:\n ");
        printf("2. display employee:\n");
        printf("3. modify employee:\n");
        printf("4. delete employee:\n");
        printf("5. exit \n");

        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            displayEmployee();
            break;
        case 3:
            modifyEmployee();
            break;        
        case 4:
            deleteEmployee();
            break;
        case 5:
            printf("exiting employee\n");
            break;    
        
        default:
            printf("Invalid Employee\n");
            break;
        }
    } 
    // printf("Enter your choice: \n");
    // printf("%d", &choice);
    while(choice !=5);
    return 0;
    getchar();

}

// int newemp(){

//     struct employee emp[50];
//     int n, i, num, new_salary;
    
//     printf("\n	Enter the number of	employees:	");
//     scanf("%d",	&n);
//     for(i=0;i<n;i++)
//     {
//         printf("\n	Enter ID:");
//         scanf("%d",	&emp[i].ID);
//         printf("\n	Enter the name : ");
//         scanf("%s", &emp[i].name);
//         printf("\n	Enter the doj : ");
//         scanf("%d",&emp[i].doj);
//         printf("\n	Enter the department: ");
//         scanf("%s", &emp[i].department);
//         printf("\n enter the salary:");
//         scanf("%d", &emp[i].salary);
//     }

//     for(i=0;i<n;i++)
//     {
//         printf("\n	********DETAILS	OF	employee %d*******", i+1);
//         printf("\n	ID =	%d", emp[i].ID);
//         printf("\n	NAME =	%s", emp[i].name);
//         printf("\n	date of joining =	%d", emp[i].doj);
//         printf("\n	department	= %s",	emp[i].department);
//     }
// }

//addemployee
void addEmployee(){
    if(count >=MAX)
    {
        printf("Employee is not in database\n");
        return;
    }
    else{
        printf("enter Employee ID:");
        scanf("%d",&emp[count].ID);
    
        printf("Enter Name: ");
        scanf("%s",&emp[count].name);

        printf("Enter date of joining: ");
        scanf("%d", &emp[count].doj);
    
        printf("Enter department:");
        scanf("%s", &emp[count].department);
    
        printf("Enter salary: ");
        scanf("%f", &emp[count].salary);
        count++;
    
        printf("Employee added succesfully");
    }
}

//display
void displayEmployee(){
    if(count == 0){
        printf("No employee");
    }

    printf("\n\n--Employee list display\n");
    for(int i=0;i<count; i++)
    {   printf("enter data:%d",i+1 );
        printf("enter Employee ID:%d\n", emp[i].ID);
        printf("Enter Name:%s\n", emp[i].name);
        printf("Enter date of joining:%d\n ", emp[i].doj);
        printf("Enter department: %s\n", emp[i].department);
        printf("Enter salary: %f\n", emp[i].salary);
    }
}

//modify
void modifyEmployee(){
    int ID, found =0;

    printf("enter Employee ID:");
    scanf("%d",&ID);

    for(int i=0; i< count; i++)
    if(emp[i].ID == ID)
    {

    printf("Enter New Name: ");
    scanf("%s",emp[i].name);

    printf("Enter date of joining: ");
    scanf("%d", emp[i].doj);

    printf("Enter department:");
    scanf("%s", emp[i].department);

    printf("Enter salary: ");
    scanf("%d",emp[i].salary);
   
    found =1;
    break;
}
}

//delete employee
void deleteEmployee()
{
    int ID, found =0;

    printf("enter Employee ID:");
    scanf("%d",&ID);

    for(int i=0; i< count; i++){
        if(emp[i].ID== ID){
            for(int j=i; j<count-1; j++){
                emp[j]= emp[j+1];
            }
            count-- ;
            printf("enter delete employee");
            found =1;
            break;
        }
    }
    if(!found)
    printf("no data available");
}