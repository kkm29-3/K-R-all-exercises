#include<stdio.h>

//structure of company;
struct company{
    int addemp;
    int deletemp;
    int update;
    int display;
    int search;
};

//functions
int addemp(int );
int delete(int);
int update(int);
int display(int);
int search(int);

int main(){
    printf("1. add employee");
    printf("2. delete the  employee");
    printf("3. update salary:");
    printf("4. display all employee:");
    printf("5. search employee by ID:");
    printf("6. exit");

    int option;
    printf("choose option:");
    scanf("%d", &option);

    switch(option){
        case '1':
        option= addemp;
        break;

        case '2':
        option = delete;
        break;

        case '3':
        option = update;
        break;

        case '4':
        option = display;
        break;

        case '5':
        option = search;
        break;

        case '6':


        default :
        printf("error");
    }
}





#define MAX 100
struct employee
{
    int ID;
    char name[50];
    char dob[15];
    char doj[15];
    char designation[15];
    float salary;
};

// struct employee emp[MAX];
// int count=0;

// //functions
// void addEmployee();
// void displayEmployee();
// void modifyEmployee();
// void deleteEmployee();

// int main()
// {
//     int choice;
//     do{
//         printf("\n---EmployeeDatabase-----\n");
//         printf("1 .add employee:\n ");
//         printf("2. display employee:\n");
//         printf("3. modify employee:\n");
//         printf("4. delete employee:\n");
//         printf("5. exit \n");
//         printf("Enter your choice: \n");
//         printf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             addEmployee();
//             break;
//         case 2:
//             displayEmployee();
//             break;
//         case 3:
//             modifyEmployee();
//             break;        
//         case 4:
//             deleteEmployee();
//             break;
//         case 5:
//             printf("exiting employee\n");
//             break;    
        
//         default:
//             printf("Invalid Employee\n");
//             break;
//         }
//     } while(choice !=5);


// }

// void addEmployee(){
//     if(count >=MAX){
//         printf("Employee database\n");
//         return;
//     }
//     printf("enter Employee ID:");
//     scanf("%d",&emp[count].ID);

//     printf("Enter Name: ");
//     scanf("%s",&emp[count].name);

//     printf("Enter date of birth");
//     scanf("%s", &emp[count].dob);

//     printf("Enter date of joining: ");
//     scanf("%s", &emp[count].doj);

//     printf("Enter designation:");
//     scanf("%s", &emp[count].designation);

//     printf("Enter salary: ");
//     scanf("%s", &emp[count].salary);
//     count++;

//     printf("Employee added succesfully");
// }

// //display
// void displayEmployee(){
//     if(count == 0){
//         printf("No employee");
//     }

//     printf("\n--Employee list display");
//     for(int i=0;i<count; i++)
//     {
//     printf("enter Employee ID:%d\n", emp[i].ID);
//     printf("Enter Name:%s\n", emp[i].name);
//     printf("Enter date of birth: %d", emp[i].dob);
//     printf("Enter date of joining:%d ", emp[i].doj);
//     printf("Enter designation: %s", emp[i].designation);
//     printf("Enter salary: %d", emp[i].salary);
//     }
// }

// //modify
// void modifyEmployee(){
//     int ID, found =0;

//     printf("enter Employee ID:");
//     scanf("%d",&ID);

//     for(int i=0; i< count; i++)
//     if(emp[i].ID == ID)
//     {

//     printf("Enter New Name: ");
//     scanf("%s",emp[i].name);

//     printf("Enter date of birth");
//     scanf("%s", &emp[i].dob);

//     printf("Enter date of joining: ");
//     scanf("%s", emp[i].doj);

//     printf("Enter designation:");
//     scanf("%s", emp[i].designation);

//     printf("Enter salary: ");
//     scanf("%s",emp[i].salary);
   
//     found =1;
//     break;
// }
// }

// //delete employee
// void deleteEmployee()
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