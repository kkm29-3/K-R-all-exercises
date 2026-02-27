// getop
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define NUMBER 0

int getop(char *s);
int main(){
    char s[100]= "this ";
    int type= getop(s);
    printf("%d", type);
    puts(s);
}

int getop(char *s){
    char c;
    while((*s = c= getchar())== ' '|| c== '\t')
    ;
    *(s+1)='\0';
    if(!isdigit(c) && c != '.')
    while (isdigit(*(++s)=c=getchar ()))
    ;

    if(c=='.'){
        while (isdigit(*(++s)=c=getchar()))
       ;  
    }

    if(c!= EOF)
    ungetc(c,stdin);
    *s== '\0';
    return NUMBER;
}