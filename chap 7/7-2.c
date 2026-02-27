#include<stdio.h>
#include<ctype.h>
#define MAX 100
int main(){
    int c;
    int col = 0;
    while((c=getchar())!=EOF)
    if(isprint(c)){
        putchar(c);
        col++;
    }

    else if(c =='\n'){
        putchar('\n');
        col =0;
        continue;
    }

    else{
        printf("\\x%02X", c);
        col +=4;
    }
    if(col>=MAX){
        putchar('\n');
        col =0;
    }
}