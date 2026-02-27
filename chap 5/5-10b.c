#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define STACK_SIZE 15
unsigned int stack_pointer =0;
float stack[STACK_SIZE];
float pop(void);
void push(float element);
int main(int argc, char * argv[]);

int main(int argc, char * argv[])
{
    char error= 0;
    for(int i=1;i<argc;++i)
    {  
        float number=atof(argv[i]);
        if(number || strcmp (argv[i], "0") ==0)
        {
            push (number);
        }
        else if(strlen(argv[i])==i)
        {
            if(stack_pointer >=2 && stack_pointer < STACK_SIZE)
            {
                float number2 = pop();
                float number1= pop();
                char op= *argv[i];
                switch (op)
                {
                    case '+':
                    push(pop()+ pop());
                    break;
                    
                    case '-':
                    push(pop()- pop());
                    break;

                    case '*':
                    push(pop() * pop());
                    break;


                    case '/':
                    if(number2 ==0){
                        error=4;
                    }
                    else{
                        push (number1/number2);
                        break;
                    }

                    default: 
                    error =3 ; 
                    break;

                }
            }
            else
            {
            error=2;
            }
            
        }
        else{
        error=1;
             }
        if(error)
        {
            switch (error)
            {
                case 1:
                printf("Error: arguments");
                break;

                case 2:
                printf("too many charactes");
                break;

                case 3:
                printf("invalid operator");
                break;

                case 4:
                printf("error: division by zero");
                break;

                default:
                break;
            }
            return EXIT_FAILURE;
        }
        printf("result: %3f", pop());
        return EXIT_SUCCESS;
        }
    }

float pop(void){
    if(stack_pointer >0){
        printf("element: %f\r\n", stack [stack_pointer --]);
        return stack [stack_pointer --];
    }
    printf("ERROR: the stack is empty");
    return 0;
}

void push(float element)
{
    if(stack_pointer < STACK_SIZE){
        stack[++stack_pointer]= element;
        printf("element: %f\r\n", element);
    }
    else
    {
        printf("ERROR: stack full");
    }
}

