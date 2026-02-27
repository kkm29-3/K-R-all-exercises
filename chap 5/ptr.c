// consider the following program that prints a text.
#include <stdio.h>
int main()
{
    char str[] = "Hello";
    char *pstr;
    pstr = str;
    printf("\n The string is : ");
    while(*pstr != '\0')
    {
        printf("%c", *pstr);
        pstr++;
    }
 return 0;
}

