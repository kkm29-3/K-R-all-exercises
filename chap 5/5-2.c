#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAXLEN 1000
#define BUFSIZE 100
int getch();
void ungetch(int c);
int getfloat(float *pn);

int main(){
    float number = 0.0;
    getfloat(&number);
    printf("number = %f\n",number);
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
//getfloat func
int getfloat(float *pn){
    int c,sign;

    while(isspace(c=getch()))
    ;
    if(!isdigit(c) && c!= EOF && c!='=' && c!='-'){
        ungetch(c);
    }
    sign = (c=='-')?-1:1;
    if (c=='+' || c== '-'){
        if(!isdigit(c=getch())){
            ungetch(c);
        }
    }
    for (*pn = 0;isdigit(c); c=getch()){
        *pn = 10* *pn +(c-'0');
    }
    //decimal cond
    if (c=='.'){
        int i;
        for(i=1;(c=getch()) && isdigit(c); ++i){
            *pn+=(c-'0')/pow(10,i);
        }
    }
    *pn= *pn *sign;
    if(c!=EOF)
    ungetch(c);
    return(c);
}