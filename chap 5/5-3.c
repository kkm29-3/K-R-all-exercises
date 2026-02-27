//strcat_ptr(s,t)
#include<stdio.h>
#include<string.h>
void strcat_ptr(char *s,char *t);
// strcat- append the string with blank spaces
int main(){
    char s[100]; //= "this is ";
    char t[100] ;//= ",the first string";
    printf("enter first string: ");
    scanf("%99s", s);
    
    printf("enter second string: ");
    scanf("%99s", t);
    strcat_ptr(s,t);
    puts(s);
}

void strcat_ptr (char *s, char *t){
    while( *s)
    ++s;
    while ((*s++ = *t++))
    ;
    
}