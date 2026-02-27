#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLEN 1000
#define MAXLINES 1000

#define MAXSTORE 4000
char *alloc(int);
#define isdir(c) (isalnum(c) || (c) == ' ' || (c) == '\t')
#define ALLOCSIZE 1000

char *lineptr[MAXLINES];
int numeric=0;
int fold= 0;
int directory= 0;
int reverse=0;
void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

int getline_(char *s, int lim);
int getline_ (char *s, int lim){
    int c,i;
    for(i=0; i< lim-1 && (c=getchar()) != EOF && c!= '\n'; i++)
    s[i]=c;

    if(c== '\n')
    s[i++]=c;
    s[i]='\0';
    return i;
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

int numcmp_(char *s1, char *s2);
int numcmp_(char *s1, char *s2)
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
int dircmp_(const char *s1, const char *s2, int dummy);
int dircmp_(const char *s1, const char *s2, int dummy){
    char c1,c2;
    while(1){
        while(*s1 && !isdir (*s1))
        s1++;
        while(*s2 && !isdir (*s2))
        s2++;

        c1= *s1;
        c2= *s2;
        if(fold){
            c1= tolower(c1);
            c2= tolower(c2);

        }
        if(c1!=c2)
        return c1-c2;
        if(c1=='\0')
        return 0;
        s1++;
        s2++;
    }
}

int foldcmp_(const char*s1, const char *s2);
int foldcmp_(const char*s1, const char *s2){
    for(; tolower(*s1)== tolower (*s2); s1++, s2++)
    if (*s1 == '\0')
    return 0;
    return tolower (*s1) - tolower(*s2);
}
int strcmp_(char *s,char *t)
{
    int r= strcmp(s,t);
    return reverse ? -r: r;
}

// sort input lines
int main(int argc, char *argv[])
{
   int nlines,reverse ;
   while(-- argc>0 && (*++argv)[0]== '-'){
    char *p= *argv +1;
    while(*p){
        switch (*p++){
            case 'n':
            numeric=1;
            break;

            case 'f':
            fold=1;
            break;

            case 'd':
            directory=1;
            break;

            default:
            printf("illegal option %c", *argv[0]);
            return 1;
        }
    }
   }
   if((nlines = readlines(lineptr, MAXLINES)) >= 0)
   {
    //    printf("input is too big to sort\n");
    //    return 1;
        if(numcmp_){
            // qsort((void**) lineptr,0, nlines-1);
            // (int(*) (void*, void*))numcmp_;
            void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
        }
        else if(foldcmp_){
            // qsort((void**) lineptr, 0 , nlines-1);
            // (int(*)(void*, void*))foldcmp_;
            void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
        }
        else
        // qsort((void**) lineptr,0, nlines -1);
        // (int(*) (void*, void*))strcmp_;
        // void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
    
        writelines(lineptr, nlines);
    }

//    int (*cmp)(const void*, const void *);
//    if(numeric)
//    cmp= (int(*)( void *,  void *))numcmp_;
//    else if(fold)
//    cmp= (int(*)( void *,  void *))foldcmp_;
//    else if(directory)
//    cmp= (int(*)( void *, void *))dircmp_;
//    else
//    cmp= (int(*)( void *,  void *))strcmp_;

//   void qsort_(void *v[], int left,int right, int (*comp)(void*, void*));
    else
        printf("input too big to sort\n");
        return 1;
    
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
    }

    tmp= v[left];
    v[left]= v[last];
    v[last]= tmp;
    qsort_(v,left, last-1,comp);
    qsort_(v,last+1, right, comp);
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
