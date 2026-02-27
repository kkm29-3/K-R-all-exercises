//reverse
#include<stdio.h>
#include<string.h>
void reverse(char *s);
int main(){
    char s[100] = "test";
    reverse(s);
    puts(s);
}

void reverse (char *s){
    char *t= s + strlen(s)-1;
    char aux= 0;
    if(*s == '\0')
    return;

    while (s<t)     
    {
        aux = *t;
        *t -- = *s;
        *s++ = aux;
    }
}