#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
int getline_ (char *s, int lim);
int numcmp_(char *s1, char *s2);
int strcmp_ (char *, char *);

int main(int argc, char *argv[]);
void qsort_(void *v[], int left, int right, int (*comp)(const void *, const void *));

int numeric = 0;
int reverse= 0;

#define ALLOCSIZE 1000
static char allocbuf[ALLOCSIZE];
static char *allocp= allocbuf;

char *alloc(int n)
{
    if(allocbuf+ ALLOCSIZE - allocp >= n){
        allocp +=n;
        return allocp -n;
    }else 
    return 0;
}

int main(int argc, char *argv[]){
    int nlines,c;
    while(--argc>0 && (*++ argv)[0]== '-'){
        while((c= *++argv[0])){
            switch (c)
            {
            case 'r':
                reverse=1;
                break;
    
            case 'n':
                numeric=1;
                break;    
            
            default:
                printf("find: illegal option:%c\n",c);
                return 1;
            }
        }
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
   void qsort_(void *v[], int left, int right, int (*comp)(const void *, const void *));
    writelines(lineptr, nlines);
   }
   else{
    printf("input too big to sort\n");
    return 0;
   }
}

void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *))
{
    int i,last;
    void *tmp;
    if(left >= right)
    return;
    tmp= v[left];
    v[left]= v[(left + right) /2];
    v[(left + right) /2]= tmp;
    last= left;
    for(i= left+1; i<= right; i++)
    if((*comp) (v[i],v[left])<0){
        ++last;
        tmp=v[last];
        v[last]= v[i];
        v[i]=tmp;
    }
    tmp= v[left];
    v[left]= v[last];
    v[last]= tmp;
    qsort_(v,left, last-1,comp);
    qsort_(v,last+1, right, comp);
}

int numcmp_(char *s1, char *s2){
    double v1,v2;
    v1= atof(s1);
    v2= atof(s2);
    if(v1< v2)
    return -1;
    else if(v1> v2)
    return 1;
    else
    return 0;
}

int strcmp_ (char *s, char *t)
{
    int r= strcmp(s,t);
    return reverse? -r: r;
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

void writelines(char *lineptr[], int nlines){
    int i;
    for(i=0; i<nlines;i++)
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


