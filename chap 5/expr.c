#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define NUMBER '0'
#define MAXVAL 100

void push(double);
double pop(void);
double stack[MAXVAL];

//rps calc
int main(){
    char token[100];
    double number;
    printf("---postfix calculator----\n");
    while(scanf("%s", token) ==1){
        if(sscanf(token, "%lf", &number)==1){
        push(number);
    }
    else{
        switch (token[0])
        {
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
            double op2 = pop();
            if (op2 != 0.0)
                push(pop()/op2);
            else
                printf("error: zero division\n");
            break;

            case '=':
            printf("result:\t%.8g\n", pop());
            break;

            // case '\n':
            //     printf("result:\t%.8g\n",pop());
            //     break;

            // % condition
            case '%':
                op2 = pop();
                if(op2!= 0.0)
                push(fmod(pop(),op2));
                else
                printf("error : zero divison\n");
                break;

            default:
                printf("error: unknown command %s\n", token);
                break;  

            }
        }
    }
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