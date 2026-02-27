//-df
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLEN 1000
#define MAXLINES 1000
#define MAXFIELDS 1000
// #define ALLOCSIZE 1000

char *lineptr[MAXLINES];
// char *alloc(int);
char *lineptr[MAXLINES];

typedef struct {int numeric, fold, directory;} FieldOpt;

FieldOpt fieldopt[MAXFIELDS];
int nfields=0;
// int getline_(char *s, int lim);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort_(void *v[], int left, int right, int (*comp)(const void *, const void *));
// void swap(void *v[], int i,int j);
void fieldcmp(const char *s1, const char *s2);

int foldcmp_(const char*s1, const char *s2);

int readlines(char *lineptr[], int maxlines)
{
    int len,nlines;
    char *p;
    char line[MAXLEN];

    nlines=0;
    while(fgets(line, MAXLEN, stdin) != NULL){
        len = strlen(line);
        if(nlines>= maxlines ||(p= malloc(len)) ==NULL)
        return -1;
        strcpy (p, line);
        lineptr[nlines++]=p;
        if(nlines >= maxlines)
        return -1;
    }
    return nlines;
    fieldopt[nfields++];
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

int foldcmp_(const char*s1, const char *s2){
    for(; tolower(*s1)== tolower (*s2); s1++, s2++)
    if (*s1 == '\0')
    return 0;
    return tolower (*s1) - tolower(*s2);
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

int fieldcmp_(const char *s1, const char *s2)
{
    char f1[MAXLEN];
    char f2[MAXLEN];
    int field=0;
    while(field< nfields){
        sscanf(s1,"%s",f1);
        sscanf(s2,"%s",f2);

        int result;

        if(fieldopt[field].numeric)
        result= atof(f1) - atof(f2);
        else{
            char *p1=f1, *p2=f2;
            while (*p1 && *p2)
            {
                char c1= *p1, c2= *p2;
                if(fieldopt [field].directory){
                    if (!isalnum(c1) && c1 != ' '){
                        p1++;
                        continue;
                    }
                     if (!isalnum(c2) && c2 != ' '){
                        p2++;
                        continue;
                    }
                    if(fieldopt[field].fold){
                        c1=tolower(c1);
                        c2=tolower(c2);
                    }
                    if(c1 !=c2)
                    return c1-c2;
                    p1++;
                    p2++;
                }
            }
            result = *p1 - *p2;
        }
            if(result != 0)
            return result;

            s1= strchr(s1,' ');
            s2= strchr(s2,' ');
            if(!s1 || !s2) 
            break;
            s1++;
            s2++;
            field++; 
    }
}

int main(int argc, char *argv[])
{
    int nlines;
    while(--argc > 0 && (*++argv)[0] == '-'){
        FieldOpt opt= {0,0,0};
        char *p= argv[0]+1;
        while(*p){
            if(*p == 'n')opt.numeric=1;
            else if(*p=='f')opt.fold=1;
            else if(*p=='d')opt.directory=1;
            p++ ;
        }
        fieldopt[nfields++]=opt;
    }
    if((nlines= readlines(lineptr,MAXLINES))>=0)
    // {
    //     if(fieldcmp){
    //         void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));}
    //     else{
    //      writelines(lineptr, nlines);

    //     }
    // //     qsort_(void**) lineptr, 0, nlines-1, (int(*)(void*, void*))fieldcmp;
    // //     writelines(lineptr, nlines);
    // }
    {
     if(numcmp_){
            void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
        }
         else if(foldcmp_){
            void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
        }
        else if(fieldcmp){
            void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));

        }
    }
    else{
        printf("error: input too bigto sort\n");
        return 1;
    }    
}








// int main(int argc, char *argv[]){
//     int nlines;
//     while(--argc>0 && (*++argv)[0] == '-'){
//         FieldOpt opt= {0,0,0};
//         char *p= argv[0]+1;
//         while(*p){
//             if(*p == 'n') opt.numeric=1;
//             else if(*p== 'f') opt.fold=1;
//             else if(*p == 'd') opt.directory=1;
//             p++;
//         }
//         if((nlines= readlines(lineptr, MAXLINES)) >= 0){
//         if(numcmp_){
//             void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
//         }
//         //  else if(foldcmp_){
//         //     void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
//         // }
//         else if(fieldcmp){
//             void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));

//         }
//         }
//         else{
//             printf("error: input too long\n");
//             return 1;
//         }
  
//     }
// }


// static char allocbuf[ALLOCSIZE];
// static char *allocp= allocbuf;

// char *alloc(int n)
// {
//     if(allocbuf+ ALLOCSIZE - allocp >= n){
//         allocp +=n;
//         return allocp -n;
//     }else 
//     return 0;
// }


// int getline_ (char *s, int lim){
//     int c,i;
//     for(i=0; i< lim-1 && (c=getchar()) != EOF && c!= '\n'; i++)
//     s[i]=c;

//     if(c== '\n')
//     s[i++]=c;
//     s[i]='\0';
//     return i;
// }


// int main(int argc, char *argv[]){
//     int nlines;
//     while(--argc > 0 &&(*argv)[0] == '-'){
//         FieldOpt opt={0,0,0};
//         char *p= argv[0] +1;
//         while(*p){
//             if(*p= 'n')opt.numeric =1;
//             else if(*p= 'f')opt.fold=1;
//             else if(*p='d')opt.directory=1;
//             p++;
//         }
//         fieldopt[nfields++] =opt;

//     }
//        if((nlines = readlines(lineptr, MAXLINES)) >= 0)
//    {
//     //    printf("input is too big to sort\n");
//     //    return 1;
//         if(numcmp_){
//             // qsort((void**) lineptr,0, nlines-1);
//             // (int(*) (void*, void*))numcmp_;
//             void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
//         }
//         else if(foldcmp_){
//             // qsort((void**) lineptr, 0 , nlines-1);
//             // (int(*)(void*, void*))foldcmp_;
//             void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
//         }
//         else
//         // qsort((void**) lineptr,0, nlines -1);
//         // (int(*) (void*, void*))strcmp_;
//         // void qsort_(void *v[], int left, int right, int(*comp)(const void *, const void *));
    
//         writelines(lineptr, nlines);
//     } else{
//         printf("input too big to sort\n");
//         return 1;
//     }
// }