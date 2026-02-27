// getline
#include<stdio.h>
#include<string.h>
void getline(char *s);
int main(){
    char string[150]= "";
    getline (string);
    puts(string);
}

void getline(char *s){
    while((*s = getchar())!= EOF && (*s!= '\n')){
        ++s;
    }

    *s= '\0';

}