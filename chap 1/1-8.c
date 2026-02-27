#include<stdio.h>
int main(){
    // count blanks,tab,new line
    int c,
    long blanks=tab=newline=0;
   

    while((c=getchar())!= EOF){

    if (c==' ')
        ++blanks;
    
    else if (c=='\t')
        ++tab;
     
    else if (c=='\n')
        ++newline;
    
}

printf("blanks:%ld\n, tabs:%ld\n, newline:%ld\n",blanks, tab, newline);
}

