#include<stdio.h>
int main(){
    char char1;
    // char char2=EOF;

    while((char1 = getchar())!=EOF){
        if(char1 == ' '|| char1 == '\t' || char1 =='\n'){
            // if (char2 != ' ' && char2!='\t' && char2 != '\n'){
                // putchar(char1);
                // putchar(char1);
                putchar('\n');
                // c=getchar();
            }
            else{
                putchar(char1);
                // putchar(char2);

            }
        // }
    }
    // char2= char1;


    return 0;
}


//     // while(c!= EOF){
//     //     putchar(c);
//     //     putchar('\n');
//     //     c= getchar();

//     // }


