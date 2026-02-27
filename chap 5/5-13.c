#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINES 1000
#define MAXLEN 1000
#define ALLOCSIZE 1000
#define MAXLINE 1000
char *lineptr[MAXLINE];
static char allocbuf[ALLOCSIZE];
static char *allocp= allocbuf;
int readlines(char *lineptr[], int maxlines);

void writelines(char *lineptr[], int nlines, int n);
char *alloc(int n);
int getline_ (char *s, int lim);

int main(int argc, char *argv[]){
    int n=0;
    int nlines;

    if(argc== 2 && argv[1][0]== '-'){
        n= atoi(argv[1] +1);
        if(n<0)
        n=0;
    }
     if((nlines = readlines(lineptr, MAXLINES)) >= 0){
    writelines(lineptr, nlines,n);
   }
   else{
    fprintf(stderr, "tail: input too large\n");
    return 1;
   }
}

int readlines(char *lineptr[], int maxlines)
{
    int len,nlines;
    char *p;
    char line[MAXLEN];

    nlines=0;
    while((len = getline_(line, MAXLEN))>0)
    if(nlines >= maxlines || (p= alloc(len)) == NULL)
    return -1;

    else{
        line[len-1] = '\0';
        strcpy(p,line);
        lineptr[nlines++]=p;

    }
    return nlines;
}


void writelines(char *lineptr[], int nlines, int n){
    int start;
    if(n> nlines)
    start=0;
    else
    start= nlines-n;
    for(int i=start; i<nlines; i++)
    printf("%s\n", lineptr[i]);
}

int getline_ (char *s, int lim){
    int c,i;
    for(i=0; i< lim-1 && (c=getchar()) != EOF && c!= '\n'; i++)
    s[i]=c;

    if(c== '\n')
    s[i++]=c;
    s[i]='\0';
    return i;
}

char *alloc(int n)
{
    if(allocbuf+ ALLOCSIZE - allocp >= n){
        allocp +=n;
        return allocp -n;
    }else 
    return NULL;
}