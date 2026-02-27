// printd example
#include<stdio.h>
void printd(int n);
int main(){
    int n;
    printf("Enter an integer:");
    scanf("%d",&n);

    printf("the digits are:");
    printd(n);
    printf("\n");
}

void printd(int n){
    static int first_call= 1;
    if (n){
        if (first_call && n<0){
            first_call=0;
            putchar('-');
            n*= -1;
        }
        int d= n%10;
        n/=10;
        printd(n);
        putchar(d+'0');
    }else{
        first_call = 1;
    }
}































// #include<stdio.h>
// //itoa function
// #define MAXLEN 100
// void itoa(int n,char str[]);

// int main(){
//     int n= -1234;
//     char str[MAXLEN];
//     itoa(n,str);
//     printf("%s\n",str);

//     //  int n=-7676;
//     // char str[MAXLEN];
//     // itoa(n,str);
//     // printf("%s\n",str);
// }

// void itoa(int n,char str[]){
//     static int i=0;
//     if(n){
//         if(n<0){
//             i=0;
//             str[i++]== '-';
//             n*= -1;
//         }

//         int d= n%10;
//         n/= 10;

//         itoa(n,str);
//         str[i++]= d+ '0';
//         str[i]= '\0';

//     }
// }