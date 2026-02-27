#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define BUFSIZE 100

int getch();
void ungetch (int);

static char buf[BUFSIZE];
static int bufp = 0;
static const char *input_str;
static int input_index=0;

int getch(){
    int c;
    if(bufp>0){
        return buf[--bufp];
    }
    if (input_str && input_str[input_index] !='\0'){

        return input_str[input_index++];

    }
    return EOF;
}

void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch");

    }else{
        buf[bufp++]=c;

    }
}

int getint (int *pn)
{
    int c,sign;

    while (isspace(c=getch()))
    ;
    if(!isdigit(c) && c!=EOF && c!= '+' && c!='-'){
        ungetch(c);
        return 0;
    }

    sign = (c=='-') ? -1 :1;
    if(c== '+' || c== '-')
    c=getch();
    for (*pn=0; isdigit(c); c= getch())
    *pn=10* *pn + (c-'0');
    *pn *= sign;
    if(c!= EOF)
    ungetch(c);
    return c;
}

int main(){
    int n;
    printf("Enter value: ");
    scanf("%d", &n);
    printf("result:%d",n);
    // input_str= "0";
    // input_index=0;
    // bufp= 0;
    // if(getint(&n)!=0){
    //     printf("result: %d\n", n);
    // } else{
    //     printf("result: %d\n", n);
    // }
}