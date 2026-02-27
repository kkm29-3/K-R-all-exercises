// Write a program to reverse a given string.
#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
    char str[100], reverse_str[100], temp;
    int i=0, j=0;
    // clrscr();
    printf("\n Enter the string : ");
    // gets(str);
    scanf("%s", str);
    j = strlen(str)-1;
    while(i < j)
    {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i++;
        j--;
    }
    printf("\n The reversed string is : ");
    puts(str);
    getch();
    return 0;
}