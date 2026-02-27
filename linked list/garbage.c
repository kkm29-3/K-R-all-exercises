#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>


#define MAX 100
struct employee
{
    int ID;
    char name[50];
    char dob[15];
    char doj[15];
    char department[15];
    float salary;
};


struct employee emp[MAX];
int count=0;

//linked list
struct node
{
  int data;
  struct node *next;
};


struct node *start = NULL;
struct node *addEmp(struct node *);
// struct node *delete_ID(struct node *);
// struct node *delete_beg(struct node *start);

// struct node *update_salary(struct node *);
// struct node *display(struct node *);
// struct node *searchID(struct node *);
// struct node *sortEmp(struct node *);
// struct node *find(struct node *);

int main(int argc, char *argv[]) {
  int option;
  do
  {
    printf("\n\n *****company database *****");
    printf("\n 1:  add employee");
    printf("\n 2:  delete employee by ID:");
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
        case 1: 
        addEmp; 
        break;
        // case 2: start = delete_ID; break; 
        // case 3: start = update_salary; break; 
        // case 4: start = display; break; 
        // case 5: start = searchID; break; 
        // case 6: start = find; break; 
    }
  }
  while(option !=1);
    getch();
    return 0;
}

struct node *addEmp(struct node *)
{
    struct node *new_node, *ptr;
    int num; //enter the data
    printf("\n enter -1 to end");
    printf("enter the data:");
    scanf("%d", &num);

    while(num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node)); //memory allocation
        new_node -> data=num;
        if(start==NULL)
        {
          new_node -> next = NULL;
          start = new_node;
        }

        else
        {
            // ptr = start;
            // while (ptr -> next !=NULL)
           
            printf("enter Employee ID:");
            scanf("%d",&emp[count].ID);
    
            printf("Enter Name: ");
            scanf("%s",&emp[count].name);
    
            printf("Enter date of birth");
            scanf("%s", &emp[count].dob);
    
            printf("Enter date of joining: ");
            scanf("%s", &emp[count].doj);
    
            printf("Enter designation:");
            scanf("%s", &emp[count].department);
    
            printf("Enter salary: ");
            scanf("%s", &emp[count].salary);
            count++;
    
            printf("Employee added succesfully");
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

// struct node *delete_ID(struct node *start)
// {
//     int ID, found =0;

//     printf("enter Employee ID:");
//     scanf("%d",&ID);

//     for(int i=0; i< count; i++){
//         if(emp[i].ID== ID){
//             for(int j=i; j<count-1; j++){
//                 emp[j]= emp[j+1];
//             }
//             count-- ;
//             printf("enter delete employee");
//             found =1;
//             break;
//         }
//     }
//     if(!found)
//     printf("no data available");
// }
    
// struct node *update_salary(struct node *){
//     float salary, found=0;

//     printf("enter the employee salary:");
//     scanf("%d", salary);

//     for(int i=0; i< count; i++)
//     if(emp[i].salary == salary)
//     {
//         printf("Enter salary: ");
//         scanf("%s",emp[i].salary);

//         found =1;
//         break;
//     }
// }


// struct node *display(struct node *)
// {
//     if(start == 0)
//     {
//         printf("no employee");
//     }
//     else
//     {
//         printf("\n--Employee list display");
//         ptr = start;
//         while (ptr -> next !=NULL)
//         ptr= ptr->next;
//         ptr -> next = new_emp;
//         new_emp-> next = NULL;
//         printf("enter Employee ID:%d\n", emp[i].ID);
//         printf("Enter Name:%s\n", emp[i].name);
//         printf("Enter date of birth: %d", emp[i].dob);
//         printf("Enter date of joining:%d ", emp[i].doj);
//         printf("Enter designation: %s", emp[i].designation);
//         printf("Enter salary: %d", emp[i].salary);
//     }
// }

// struct node *searchID(struct node *){
//     int ID, num, n, found =0, emp = -1;
//     printf("enter the employee ID:");
//     scanf("%d", &num);

//     for(i=0; i<n; i++){
//         if(ID == num)
//         {
//             found = 1;
//             emp= i;
//             printf("\n %d found in company = %d", num, emp);
//             break;
//         }
//         else
//             printf("not found");
//     }
// }

// // struct node *sortEmp(struct node *){

// // }