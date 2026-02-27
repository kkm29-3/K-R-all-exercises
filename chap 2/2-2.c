#include<stdio.h>
// #include<string.h>
#define MAXLINE 100
int main(){
    int c;
    int i=0;
    int lim= MAXLINE;
    char s[MAXLINE] ;

    while(i<lim-1){
        c=getchar();
       if (c=='\n')
       break;
        if (c==EOF)
        break;
        s[i]=c;
        ++i;
       
       }
       s[i]='\0';
       printf("%s\n",s); 
    
}