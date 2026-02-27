#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINES 300
#define MAXSTORE 1000

char *lineptr[MAXLINES];

int readlines (char *lineptr[],int maxlines, char storelines);
int writelines (char *lineptr[],int nlines);
void qsort (char *lineptr[], int left, int right);


int main(){
    int nlines;
    char storelines;
    if((nlines = readlines(lineptr, MAXLINES, storelines))>=0){
        qsort(lineptr,0, nlines-1);
        writelines(lineptr,nlines);
        return 0;
    } else{
        printf("ERROR: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 //max length of any input line

int getline(char *,int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines, char *storelines){
    int len,nlines;
    char *p= storelines+ strlen(storelines);
    char line[MAXLEN];

    nlines=0;
    while((len = getline(line,MAXLEN))>0)
    if(nlines >= maxlines || storelines + MAXSTORE-p< len)
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

// void writelines(char *lineptr[],int nlines){
//     while (nlines -- >0)
//     printf("%s\n", *lineptr++);
// }
size_t getline(char line[], size_t (max_line_len)){
    int c;
    size_t i;

    for(i=0; i<max_line_len -1 && (c= getc(stdin))!=EOF && c!= '\n';++i )
    {
        line[i]=c;
    }
    if (c=='\n'){
        line[i]=c;
        ++i;
    }
    line[i]='\0';
    return i;

}

void qsort (char *v[],int left, int right)
{
    int i,last;
    void swap(char *v[], int i,int j);

    if(left >=right)
    return;

    swap(v,left,(left + right)/2);
    last=left;
    for(i=left+1; i<= right; i++)
    if(strcmp (v[i],v[left])<0)
    swap (v,left,last);
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}

void swap(char *v[],int i,int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// void main(void){
//     int nlines= 10;
//     char lineptr[MAXLINES]="soleman";
//     int len=10;
//     readlines(char *lineptr, nlines);

//     int i=10;
//     writelines(char *lineptr, nlines);
    
//     // int last= 10;
//     // qsort(*v[],left,right);
//     // swap(*v[],i,j);


// }