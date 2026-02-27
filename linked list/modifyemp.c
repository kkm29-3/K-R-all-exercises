#include <stdio.h>
#include <conio.h>
#include <string.h>
struct employee
{
    int ID;
    char name[80];
    int doj;
    char department[80];
    int salary;
};

int	main()
{
    struct employee emp[50];
    int n, i, num, new_salary;
    
    printf("\n	Enter the number of	employees:	");
    scanf("%d",	&n);
    for(i=0;i<n;i++)
    {
        printf("\n	Enter ID:");
        scanf("%d",	&emp[i].ID);
        printf("\n	Enter the name : ");
        scanf("%s", &emp[i].name);
        printf("\n	Enter the doj : ");
        scanf("%d",&emp[i].doj);
        printf("\n	Enter the department: ");
        scanf("%s", &emp[i].department);
        printf("\n enter the salary:");
        scanf("%d", &emp[i].salary);
    }

    for(i=0;i<n;i++)
    {
        printf("\n	********DETAILS	OF	employee %d*******", i+1);
        printf("\n	ID =	%d", emp[i].ID);
        printf("\n	NAME =	%s", emp[i].name);
        printf("\n	date of joining =	%d", emp[i].doj);
        printf("\n	department	= %s",	emp[i].department);
    }

    printf("\n	Enter the employee number whose salary has to be edited: ");
    scanf("%d",	&num);

    num= num-1; 
    printf("\n	Enter the new salary: ");
    scanf("%d",	&new_salary);
    
    emp[num].salary	= new_salary;
    for(i=0;i<n;i++)
    {
        printf("\n	********DETAILS	OF	employee %d*******",	i+1);
        printf("\n	employee ID	=	%d",	emp[i].ID);
        printf("\n	NAME	=	%s",	emp[i].name);
        printf("\n	date of joing =	%d",	emp[i].doj);
        printf("\n	department	=	%s",	emp[i].department);
        printf("\n new salary:", emp[i].salary);
        getch();
    }
    return	0;
}