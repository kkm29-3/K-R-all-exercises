#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#define MAX 100

//structure of employee
struct employee
{
    int ID;
    char name[50];
    int doj[15]; //year
    char department[15];
    int salary;
};

//employee
struct employee *emp[MAX];

int count=0;

//linked list
struct node
{
  int data;
  struct node *next;
  int ID;
    char name[50];
    int doj[15]; //year
    char department[15];
    int salary;
};

struct node *start = NULL;

//functions
struct node *addEmp(struct node *);
struct node *delete_ID(struct node *);
// struct node *delete_beg(struct node *);
struct node *update_salary(struct node *);
struct node *display(struct node *);
struct node *searchID(struct node *);
// struct node *sortEmp(struct node *);
// struct node *find(struct node *);

int main(int argc, char *argv[]) {
  int option;
  do
  {
    printf("\n\n *****company database *****");
    printf("\n 1: add employee:");
    printf("\n 2: delete employee by ID:");
    printf("\n 3: update_salary salary: ");
    printf("\n 4. display the employee");
    printf("\n 5. search by ID:");
    printf("\n 6. sort employee by joining: ");
    printf("\n 7. find for high paid and least paid ");
    printf("\n EXIT ");

    printf("\nenter your option:");
    scanf("%d", &option);
    switch(option)
    {
        case 1: start=addEmp(start); break;
        case 2: start= delete_ID(start); break; 
        case 3: start=update_salary(start); break; 
        case 4: start=display(start); break; 
        case 5: start=searchID(start); break; 
        // case 6: start=sortEmp(start); break;
        // case 7: start=find(start); break; 
    }
  }
  while(option !=7);
    getch();
    return 0;
}

struct node *addEmp(struct node *)
{
    if(count >=MAX)
    {
        printf("Employee is not in database\n");
        // return;
    }
    else
    {
        printf("enter Employee ID:");
        scanf("%d",&emp[count]->ID);
    
        printf("Enter Name: ");
        scanf("%s",&emp[count]->name);

        printf("Enter date of joining: ");
        scanf("%d", &emp[count]->doj);
    
        printf("Enter department:");
        scanf("%s", &emp[count]->department);
    
        printf("Enter salary: ");
        scanf("%f", &emp[count]->salary);
        count++;
    
        printf("Employee added succesfully");
    }
}

struct node *display(struct node *){
    if(count == 0){
        printf("No employee");
    }

    printf("\n\n--Employee list display\n");
    for(int i=0;i<count; i++)
    {   printf("enter data:%d",i+1 );
        printf("enter Employee ID:%d\n", emp[i]->ID);
        printf("Enter Name:%s\n", emp[i]->name);
        printf("Enter date of joining:%d\n ", emp[i]->doj);
        printf("Enter department: %s\n", emp[i]->department);
        printf("Enter salary: %f\n", emp[i]->salary);
    }
}

struct node *update_salary(struct node *start){
    int ID, found =0;

    printf("enter Employee ID:");
    scanf("%d",&ID);

    for(int i=0; i< count; i++)
    if(emp[i]->ID == ID)
    {

    printf("Enter New Name: ");
    scanf("%s",emp[i]->name);

    printf("Enter date of joining: ");
    scanf("%d", emp[i]->doj);

    printf("Enter department:");
    scanf("%s", emp[i]->department);

    printf("Enter salary: ");
    scanf("%d",emp[i]->salary);
   
    found =1;
    break;
}
}

struct node *delete_ID(struct node *start)
{
    int ID, found =0;

    printf("enter Employee ID:");
    scanf("%d",&ID);

    for(int i=0; i< count; i++){
        if(emp[i]->ID== ID){
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

struct node *searchID(struct node *)
{
    int ID, found =0;

    printf("enter Employee ID:");
    scanf("%d",&ID);

    for(int i=0; i< count; i++){
        if(emp[i]->ID== ID){
            for(int j=i; j<count-1; j++){
                emp[j]= emp[j+1];
            }
            count-- ;
            found =1;
            break;
        }
    }
    if(!found)
    printf("no data available");
}