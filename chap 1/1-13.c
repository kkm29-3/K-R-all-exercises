// // HISTOGRAM
#include<stdio.h>
#define IN 1
#define OUT 0
int main(){
    // count lines
    int c,nl,nw,nc,state;

    state=OUT;
    nl=nw=nc=0;
    while((c=getchar())!=EOF){
        ++nc;
        if(c=='\n')
        ++nl;
    if(c==' '|| c== '\n'|| c=='\t')
    state=OUT;
    else if(state== OUT){
    state= IN;
    ++nw;
}
    }
    // print pattern
    for(int i=0;i<nw;i++){
        for(int j=0;j<i;j++){
            printf(" * ");
        }
        printf("\n");
    }
    return 0;
}   


























// #include<stdio.h>
// main(){
//     int c,i,nwhite,nother;
//     int ndigit[10];

//     nwhite = nother = 0;
//     for(i=0;i<10;++i)
//     ndigit[i]=0;

//     while ((c=getchar())!=EOF)
//     if (c>='0' && c<='9')
//     ++ndigit[c-'0'];
// else if (c==' '|| c=='\n'||c=='\t')
// ++nwhite;
// else
// ++nother;

// printf("digits= ")      
// for(i=0;i<10;++i)   
// printf("%d",ndigit[i]);
// printf()

// }
