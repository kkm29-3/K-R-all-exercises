//not more than one character push back
#include<stdio.h>
int getch(void);
void ungetch(int c);

int main(){
    char c= getch();
    printf("%c\n",c);
    ungetch(c);
    printf("%c\n",c=getch());
}

int buf = -1;
int getch(){
    char temp;
    if (buf!= -1){
        temp=buf;
        buf= -1;
        return temp;
    }
    return getchar();
}

void ungetch(int c){
    if (buf!= -1){
        printf("ungetch : buffer full\n ");
    }
    else {
        buf=c;
    }
}