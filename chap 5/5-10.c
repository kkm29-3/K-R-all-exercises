#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAXSTACK 10

double stack[MAXSTACK];
int sp=0;
void push (double f){
    if(sp< MAXSTACK)
    stack[sp++]=f;
    else{
        printf("error: stack full\n");
    }
}

double pop(void)
{
    if(sp>0)
    return stack[--sp];
    else{
        printf("error: stack empty\n");
    }
}

int main(int argc, char *argv[])
{
    int i;
    double op2;
    for(i=1; i< argc; i++){
        switch (argv[i][0])
        {
        case '+':   
            push (pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;

        case '-':
            push(pop()- pop());
            break;

        case '/':
        op2=pop();
            if(op2 != 0.0)
            push(pop()/op2);
            else{
                printf("error: zero division\n");
                exit(1);
            }    
            break;

        default:
        push(atof(argv[i]));
            break;
        }
    }
    if(sp==1)
    printf("result: %.8g\n", pop());
    else{
    printf("error: invalid expression");
    exit(1);
    }
    
    return 0;
}
