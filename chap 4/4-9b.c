#include<stdio.h>
#define BUFSIZE 100

int getch();
void ungetch (int c);

int main(){
    int c;
    c=getch();
    if(c!=EOF)
    putchar(c);

    ungetch(EOF);
    c=getch();
    if(c!=EOF)
    putchar(c);
}

char buf[BUFSIZE];
int bufp=0;

int getch(){
    return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
    else
    buf[bufp++]=c;
}