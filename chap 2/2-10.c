#include<stdio.h>
//declare
int lower(int c){
    return ((c>='A' && c<='Z')? c+ 'a'-'A':c);
}
//call
int main(){
    char input[]= "heLLO WoRLD";
    printf("input :%s\n", input);

    for (int i=0;input[i]!= '\0';i++){
        input[i]= lower(input[i]);
    }
    printf("lower: %s\n", input);
}