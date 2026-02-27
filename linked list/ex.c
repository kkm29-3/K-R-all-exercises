#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#define MAX 100

// structure of employee
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
    printf("\n 1: add employee");
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

// struct node *addEmp(struct node *)
// {
//     struct node *new_node, *ptr;
//     int num;
//     // printf("\n Enter -1 to end");
//     // printf("\n Enter the data : ");
//     // scanf("%d", &num);
//     while (num!= -1)
//     {
//         new_node = (struct node*)malloc(sizeof(struct node)); //memory allocation
//         new_node->data = num;
//          if(start==NULL)
//         {
//           new_node -> next = NULL;
//           start = new_node;
//         }
//         else{
//         int i;
//          printf("\nEnter the data for employee %d",	i+1);

//         printf("\nEMployeeID : ");
//         scanf("%d",	&emp[i]->ID);

//         printf("\nNAME: ");
//         scanf("%s",emp[i]->name);
        
//         printf("\nDate of joining: ");
//          scanf("%d",&emp[i]->doj);
        
//          printf("\nDepartment: ");
//          scanf("%s",emp[i]->department);
       

//         printf("\nsalary:");
//         scanf("%d", emp[i]-> salary);

//         printf("\n ");
//         }
//         return start;
//     }
// }

struct node *addEmp(struct node *)
{
    int i, n;
    printf("\nEnter the number of employee:");
    scanf("%d",	&n);
    
    // for(i=0;i<n;i++)
    if(n >= MAX)
    {
         printf("Employee is not in database\n");
        // return;
    }else{
        emp[i]	=(struct employee *)malloc(sizeof(struct employee));
        printf("\nEnter the data for employee %d",	i+1);

        printf("\nEMployeeID : ");
        scanf("%d",	&emp[i]->ID);

        printf("\nNAME: ");
        scanf("%s",emp[i]->name);
        
        printf("\nDate of joining: ");
         scanf("%d",&emp[i]->doj);
        
         printf("\nDepartment: ");
         scanf("%s",emp[i]->department);
       

        printf("\nsalary:");
        scanf("%d", emp[i]-> salary);

        printf("\n ");
        //display the employee
        printf("\nDETAILS OF employee");
        i++;
    
        for(i=0;i<n;i++)
        {
            printf("\n	EmployeeeID=%d", emp[i]->ID);
            printf("\n	NAME=%s", emp[i]->name);
            printf("\n	DOJ=%d", emp[i]->doj);
            printf("\n	Department=%s", emp[i]->department);
            printf("\n  SALARY : %d ", emp[i]->salary);
        }
    }
}

// struct node *delete_beg(struct node *start)
// {
//     struct node *ptr;
//     ptr = start;
//     start = start -> next;
//     free(ptr);
//     return start;
// }

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
    
struct node *update_salary(struct node *start)
{
    int salary, found=0;
    int n, i, num, new_salary;
    struct employee emp[50];

    printf("\n	Enter the number of	employees:	");
    scanf("%d",	&n);

    printf("enter the employee salary:");
    scanf("%d", salary);

    // for(int i=0; i< count; i++)
    // if(emp[i]->salary == salary)
    // {
    //     printf("Enter salary: ");
    //     scanf("%s",emp[i]->salary);
    //     found =1;
    //     break;
    // }else
    printf("\nEnter the employee number whose salary has to be edited: ");
    scanf("%d",	&num);

    num= num-1; 
    printf("\n	Enter the new salary: ");
    scanf("%d",	&new_salary);
    
    emp[num].salary	= new_salary;
    for(i=0;i<n;i++)
    {
        printf("\n	********DETAILS	OF	that employee %d*******",	i+1);
        printf("\n	employee ID	=	%d", emp[i].ID);
        printf("\n	NAME	=	%s", emp[i].name);
        printf("\n	date of joing =	%d", emp[i].doj);
        printf("\n	department	=	%s", emp[i].department);
        printf("\n new salary:", emp[i].salary);
        getch();
    }
    return	0;
}

struct node *update_salary(struct node *start){
    struct node* new_node;
    struct node * employee;
    int ID, found =0,new_salary;

    printf("enter Employee ID:");
    scanf("%d",&ID);
    if(start->ID == ID)
    printf("\n enter the new salary:");
    scanf("%d",&new_salary);

    new_node= (struct node *) malloc (sizeof(struct node));
    new_node-> next =start;
    start = new_node;
    return start;
    
}


struct node *display(struct node *start)
{
    if(start == 0)
    {
        printf("no employee");
    }
    else
    {
        printf("\n--Employee list display");
        struct node *ptr;
        ptr = start;
        while (ptr -> next !=NULL)
            ptr= ptr->next;
            // ptr -> next = new_emp;
            // new_emp-> next = NULL;
        int i;
        printf("enter Employee ID:%d\n", emp[i]->ID);
        printf("Enter Name:%s\n", emp[i]->name);
        printf("Enter date of joining:%d ", emp[i]->doj);
        printf("Enter designation: %s", emp[i]->department);
        printf("Enter salary: %d", emp[i]->salary);
    }
}

struct node *searchID(struct node *start){
    int ID, num, n, found =0, emp = -1;
    printf("enter the employee ID:");
    scanf("%d", &num);

    for(int i=0; i<n; i++){
        if(ID == num)
        {
            found = 1;
            emp= i;
            printf("\n %d found in company = %d", num, emp);
            break;
        }
        else
            printf("not found");
    }
}

struct node *sortEmp(struct node *start){
    struct node*ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while(ptr1->next!= NULL)
    {
        ptr2= ptr1->next;
        while(ptr2 != NULL)
        {
            if(ptr1 -> doj > ptr2 -> doj)
            {
                temp = ptr1 -> doj;
                ptr1 -> doj = ptr2 -> doj;
                ptr2 -> doj = temp;
            }
            ptr2 =ptr2->next;
        }
        ptr1 = ptr1 -> next;
    }
    return start;
}

// find by high paid and low paid 
struct node *find(struct node *start)
{
  struct node *ptr= start;
  int salary,low,high,temp;
  while(ptr -> next != NULL)
  {
    

  }
}