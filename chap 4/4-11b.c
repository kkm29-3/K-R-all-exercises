#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFZSIZE 100

int getop(char[]);
void push(double);
double pop(void);
int getch();

//reverse polish calculator
int main(){
    int type;
    double op2;
    char s[MAXOP];

    while ((type= getop(s))!=EOF){
        switch (type){
            case NUMBER:
            push(atof(s));
            break;

            case '+':
            push(pop()+ pop());
            break;
        
            case '*':
            push(pop()* pop());
            break;

            case '-':
            push(pop()- pop());
            break;

             case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop()/op2);
            else
                printf("error: zero division\n");
            break;

            case '\n':
                printf("result:\t%.8g\n",pop());
                break;

            // % condition
            case '%':
                op2 = pop();
                if(op2!= 0.0)
                push(fmod(pop(),op2));
                else
                printf("error : zero divison\n");
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;    
        }
    }
    return 0;
}

int sp = 0;
double val[MAXVAL];
void push (double f){

    if (sp< MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full,can't push %g\n",f);
}

double pop(void){
    // int sp;
    // double val;
    if (sp>0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i=0;
    int c;

    static int buf = EOF; // static variable

    while((s[0]=c=getchar()) == ' ' || c== '\t')
    ;
    s[1] = '\0';

    if(!isdigit(c)&& c!='.'&& c!='-'){
        return c;
    }

    if(c=='-')
    {
        int next=getchar();
        if (!isdigit (next)&& next !='.'){

                }
        return next;
        s[i]=c;
        c=next=buf; //static variable
    }

    else
    {
        c= getchar();
    }
        
    if(isdigit(c))
    {
        while(isdigit(s[++i]=c=getchar()))
            ;
    }

    if (c == '.')
    {
        while (isdigit(s[++i]=c=getchar()))
        ;
        // s[i]= '\0';
    }
    if(c!= EOF)
            {
                buf=c;
            } 
            
    return NUMBER;

}

