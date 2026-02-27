#include<stdio.h>
#include<string.h>
// atoi
int atoi(const char *s);
int main(){
    int i;
    char *s = "123s3a";
    i= atoi(s);
    printf("atoi: %d", i);
}

int atoi(const char *s){
    int i=0;
    while(*s != '\0' && *s >'0' && *s< '9'){
        i=i*10 + *s - '0';
        ++s;
    }
    return i;
}