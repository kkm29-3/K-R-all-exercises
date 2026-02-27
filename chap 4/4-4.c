// add command to print top element of stack without pop to duplicate to swap

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFZSIZE 100

int getop(char[]);
void push(double);
double pop(void);
int getch();
int unget(int);

void viewhead();
void duplicate();
void swap();
void clear();

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

            case 'h':
            viewhead ();
            break;

            case 'd':
            duplicate();
            break;

            case 's':
            swap();
            break;
            
            case 'c':
            clear();
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
double stack [MAXVAL];

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

char buf [BUFZSIZE];
int bufp = 0;

int getch()
{
    return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp>= BUFZSIZE){

        printf("ungetch: too many characters\n");
    }
    else
        buf[bufp++]=c;
}

void viewhead(){
    // int sp,stack;
    if(sp){
        printf("stack-head: %g\n", stack [sp-1]);
    }
    else{
        printf("Error: stack empty\n");
    }
}

void duplicate(){
    double temp=pop();
    push(temp);
    push(temp);
}

void swap(){
    double temp1 = pop();
     double temp2 = pop();
    push(temp1);
    push(temp2);

}

void clear(){
    // int sp,stack;
    do{
        stack[sp]=0.0;
    }
    while(sp--);
}

int getop(char s[])
{
    int c;
    int i=0;
    while((s[0]=c=getch()) == ' ' || c== '\t')
    ;
    s[1] = '\0';

    if(!isdigit(c)&& c!='.'&& c!='-'){
        return c;
        
            if(c=='-'){
                
            }
            int next=getch();
            if (next == '\n'|| next== ' ' || next == '\t'){
                ungetch(next);
                return c;
            }
            else if(!isdigit(next)&& next !='.'){
                return next;
            }
            else{
                s[i++]=c=next;
    }
    }
    if(isdigit(c)){
        while(isdigit (s[++i] = c= getch()))
        ;
    }
    if (c == '.'){
        while(isdigit(s[++i]=c = getch()))
        ;
    }
    s[i]= '\0';
    if(c!=EOF){
        ungetch(c);
    }

    return NUMBER;
}




