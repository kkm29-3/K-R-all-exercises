#include<stdio.h>
#define MAXLEN 100
void reverse(char str[]);

int main(){
    char str [MAXLEN]=" this is a just a string";
    // printf("Enter a string:%s\n",str);
    // scanf("%s\n");
    reverse(str);
    printf("%s\n",str);
}

void reverse(char str[]){
    static int i=0;
    static int j=0;

    if (str[i]!= '\0'){
        char c= str[i++];
        reverse(str); //recursive
        str[j++]=c;
    } 

    if (str[j]=='\0'){
        i=j=0;               
    }
}

