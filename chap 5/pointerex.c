#include<stdio.h>
#include<string.h>

// int strncmp(char *s,char *t, size_t n)
// {
//     int i;
//     for(i=0;s[i]==t[i]; i++)
//     if(s[i] == '\0')
//     return 0;
//     return s[i]-t[i];
// }

// pointer __VERSION__
int strcmp (char *s, char *t){
    for(;*s == *t; s++,t++)
    if(*s == '\0')
    return 0;
    return *s - *t;
}

int main()
{
    char s[100]= "hey hello world";
    char *t= "hey hi";

    int is_equal = strcmp(s,t);

    if(is_equal ==0){
        puts("equal");
    }else if(is_equal<0){
        puts("less");
    }else if(is_equal>0){
        puts("more");
    }

}