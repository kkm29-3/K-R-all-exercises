#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define VARSET '_'
#define VARGET 'a'
#define VARNUM 26
#define MAXLEN 100

enum boolean{FALSE,TRUE}

int getline(char line[], unsigned int max_line_len);
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int is_empty();
void viewhead();
void duplicate();
void swap();
void clear();

char var='0';
char line[MAXLEN];
char line_i=0;

//reverse polish calculator
int main(){
    int type;
    double op2;
    char s[MAXOP];

    int varindex = 0;
    double var_buff[VARNUM];
    while(getline(line,MAXLEN)!=0){
        line_i=0;
    }

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
                printf("\t%.8g\n",pop());
                break;

            // % condition
            case '%':
                op2 = pop();
                if(op2!= 0.0)
                push(fmod(pop(),op2));
                else
                printf("error : zero divison\n");
                break;    
            //power
            case '^':
                op2= pop();
                push(pow(pop(),op2));
                break;
            //sine 
            case '~':
                push(sin(pop()));
                break;
            //exp    
            case 'e':
                push(exp(pop()));
                break;

            case 'h':
            viewhead();
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
            
            case VARSET:
            var_buff[varindex++]=pop();
            printf("variable %c : %3f\n",'a'+ varindex-1, var_buff[varindex-1]);
            break;

            case VARGET:
            push(var_buff[var-'a']);
            break;

            default:
                printf("error: unknown command %s\n", s);
                break;    
        }
    }
    return 0;
}
// getline for read entire line 
// int getline(char s[],int unsigned int max_line_len);
int getline(char line[],unsigned int max_line_len)
{
    int c;
    unsigned int i;
    for (i=0; i<max_line_len-1 && (c=getchar())!= EOF && c!='\n'; ++i)
    {
        line[i]=c;

    }
    if(c=='\n'){
        line[i]=c;
        ++i;
    }
    line[i]='\0';
    return i;
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

int is_empty(void){
    if(sp>0){

        return FALSE;
    }
    return TRUE;
}

void viewhead(){
    if(sp){
        printf("stack head: %g\n,stack[sp-1]");
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
    while(sp--)
    ;
}

int getop(char s[])
{
    int c;
    int i=0;
   
    while(s[0]=c=line[line_i++])
    ;

    s[i]='\0';

    if(isalpha(c)){
        var=c;
        return VARGET;
    }

    if(!isdigit(c) && c!='.' && c!='-'){
        return c;
    }

    if(c=='-'){
        int next= line[line_i++];
        if(next =='\n' || next == ' ' || next == '\t' || next =='\0'){
            --line_i;
            return '_';
        }
        else if(!isdigit(next) && next!='.'){
            return next;
        }else{
            s[++i]=c=next;
        }
    } else{
        c=line[line_i++];
    }
    if(isdigit(c)){
        while (isdigit(s[i++]=c= line[line_i++]))
        ;
        
    }

    if(c=='.'){
        while(isdigit(s[i++]=c=line[line_i++]))
        ;
    }
    --line_i;
    return NUMBER;
}
