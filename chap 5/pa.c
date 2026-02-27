#include<stdio.h>
#include<string.h>
// int strlen(char *s)
// {
//     int n;

//     for(n=0; *s !='\0';s++)
//     n++;
//     return n;
// }
// int main(){
//     int n= 12345;
//     char *s=p;
//     strlen(p);
//     printf("value of n:%d",n);
// }

//copy t to s: 
// void strcpy(char *s,char *t){
//     int i;
//     i=0;
//     while((s[i]=t[i]!= '\0'))
//     i++;
// }

//strcopy: copy t to s; pointer version 1
// void strcpy(char *s, char *t){
//     while ((*s=*t)!= '\0'){
//         s++;
//         t++;

//     }
// }

//OR //strcopy: copy t to s; pointer version 2
// void strcpy(char *s, char *t){
//     while ((*s++ = *t++)!='\0')
//     ;

// }

//strcopy: copy t to s; pointer version 3
// void strcpy(char *s, char *t){
//     while (*s++ = *t++)
//     ;

// }

//strcat pointer 
int strcat(char *s, char *t);
int strcat(char *s, char *t){
    while (*s++ = *t++)
    ;
}

int main(){
    char s[10]="this";
    char t[10]= "is";
    char p= strcat(s,t);

    printf("%s",p);
}


// void strcat(char s[], char t[]){
//     int i,j;

//     i=j=0;
//     while (s[i]!= '\0')
//     i++;
//     while ((s[i++] = t[j++]!='\0'))
//     ;
// }