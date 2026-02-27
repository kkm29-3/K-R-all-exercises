#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
// #include <alloc.h>

struct employee
{
    int ID;
    char name[20];
    char department[20];
    int doj;
    int salary;
};

//employee declaration
struct	employee *emp[10];

int	main()
{
    int i, n;
    printf("\nEnter the number of employee:");
    scanf("%d",	&n);
    
    for(i=0;i<n;i++)
    {
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
    }

    //display the employee
    printf("\nDETAILS OF employee");

    for(i=0;i<n;i++)
    {
        printf("\n	EmployeeeID=	%d", emp[i]->ID);
        printf("\n	NAME	=	%s", emp[i]->name);
        printf("\n	DOJ	=	%d", emp[i]->doj);
        printf("\n	Department	=	%s", emp[i]->department);
        printf("\n SALARY : %d ", emp[i]->salary);
    }
    return	0;
}