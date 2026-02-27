#include<stdio.h>
#include<ctype.h>
#include<string.h> 
#include<stdlib.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab/ sizeof keytab)
struct key{
    char *word;
    int count;
}keytab[]={
    "auto",0, "break", 0, "case",0, "char", 0, "const", 0, "continue", 0, "default",0, "unsigned", 0, "void", 0,"volatile",0, "while", 0
};

int getword(char *, int);
struct key *binsearch(char *, struct key*, int);

struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key * low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while(low < high){
        mid = low + (high - low)/2;
        if((cond = strcmp(word, mid -> word)) <0)
        high = mid;
        else if (cond >0)
        low = mid +1;
        else
        return mid;
    }
    return NULL;
}
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void){
    return (bufp>0) ? buf[--bufp]: getchar();
}

void ungetch(int c){
    if(bufp>= BUFSIZE)
    printf("ungetch: too many chacters \n");
    else
    buf[bufp++]=c;
}

int getword(char *word, int lim){
    int c,getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()))
    ;
    if(c!= EOF)
    *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
   
    for(; --lim>0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int getop(char s[])
{
    int i,c;
    while((s[0]= c= getch()) == ' '|| c=='\t')
    ;
    s[1]='\0';
    if(isdigit(c) && c!='.')
    return c;
    i=0;
    if(isdigit(c))
    while(isdigit(s[++i] = c= getch()))
    ;
    s[i]= '\0';
    if(c!= EOF)
    ungetch(c);
    return c;
}

//count c keywords pointer version
int main(){
    char word[MAXWORD];
    struct key *p;

    while(getword(word, MAXWORD) != EOF)
    if(isalpha (word[0]))
    if((p=binsearch (word, keytab, NKEYS)) != NULL)
    p->count++;
    for (p= keytab; p< keytab + NKEYS; p++)
    if(p-> count>0)
    printf("%4d %s\n", p->count, p->word);
    return 0;
}