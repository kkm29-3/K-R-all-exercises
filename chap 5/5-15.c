#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
// #include<math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXLINE 1000
#define MAXSTORE 1000
#define MAXLEN 1000
char *alloc(int n);
char *lineptr[MAXLINE];
#define ALLOCSIZE 1000

int numeric= 0;
int fold= 0;
int kri(void *v[], int left,int right, int (*comp)(void *, void *));
void swap(void *v[], int i,int j);

int numcmp(char *s1, char *s2);
int numcmp(char *s1, char *s2)
{
    double v1,v2;

    v1= atof(s1);
    v2= atof(s2);
    if(v1< v2)
    return -1;
    else if (v1>v2)
    return 1;
    else
    return 0;
}
int foldcmp(const char*s1, const char *s2);
int foldcmp(const char*s1, const char *s2){
    for(; tolower(*s1)== tolower (*s2); s1++, s2++)
    if (*s1 == '\0')
    return 0;
    return tolower (*s1) - tolower(*s2);
}

int readlines(char *lineptr[], int maxlines);
int readlines(char *lineptr[], int maxlines)
{
    int len,nlines;
    char *p;
    char line[MAXLEN];

    nlines=0;
    while(fgets(line, MAXLEN, stdin) != NULL){
        len = strlen(line);
        if(line[len-1]== '\n')
        line[len -1] = '\0';
        if((p= alloc(len +1)) == NULL)
        return -1;
        strcpy (p, line);
        lineptr[nlines++]=p;
        if(nlines >= maxlines)
        return -1;
    }
    return nlines;
}

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

void writelines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines)
{
    int i;
    for(i=0; i<nlines;i++)
    printf("%s\n", lineptr[i]);
}

int getline(char *s, int lim);
int getline(char *s, int lim)
{
    int c,i;
    for(i=0; i< lim-1 && (c= getchar())!= EOF && c!='\n'; i++)
    s[i]= c;

    if(c== '\n')
    s[i++]=c;
    s[i]='\0';
    return i;
}

// sort input lines
int main(int argc, char *argv[]);
int main(int argc, char *argv[]){

    int nlines=0;
    int numeric=0;
    int fold=0;

    while(--argc > 0 && (*++ argv)[0] == '-'){
        while (*++ argv[0])
        {
            switch(*argv[0]){
                case 'n':
                numeric=1;
                break;

                case 'f':
                fold=1;
                break;

                default:
                printf("illegal option %c", *argv[0]);
                return 1;
            }
        }
        
    }  

    if(nlines = readlines(lineptr, MAXLINE)>=0){
        if (numeric)
         kri((void **) lineptr, 0, nlines -1,(int (*)(void *, void *))numcmp);
    else if(fold)
         kri((void **) lineptr, 0, nlines -1,(int (*)(void *, void *))foldcmp);
    else 
         kri((void **) lineptr, 0, nlines -1,(int (*)(void *, void *))strcmp);    

        writelines(lineptr, nlines);
    }

    else
        printf("input too big to sort\n");
        return 1;
    
}


int kri(void *v[], int left,int right, int (*comp)(void *, void *))
{
    int i,last;

    if(left >= right)
    return 0;
    swap(v, left, (left + right)/2);
    last= left;
    for(i=left +1; i<=right; i++)
    if((*comp) (v[i], v[left]) <0)
        swap(v,++last,i);
    swap(v, left, last);
    kri(v,left, last-1, comp);
    kri(v,last+1,right,comp);
}
void swap(void *v[], int i,int j)
{
    void *temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}