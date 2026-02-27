// // #include<stdio.h>
// // #define MAXLINE 1000
// // char reverse(s){
// //     char s;
// //     printf("reversed char:%c",reverse(s));
// // }

// // int main()
// // {
// //    int len,i;
// //    int max;
// //    char c;
// //    char line[MAXLINE];
// //    char longest[MAXLINE];

// //    max=0;

// //    for(len=0;len>max;len++){
    
// //     len[i]=len[i]-1;
// //     // s[i]=c;
// //     printf("reversed char:%c", reverse());
   
// // }
// // }

// #include<stdio.h>
// #define MAXLINE 1000

// int getline(char s[], int lim);

// //read a line into s, return length 
// int main(){
//     int c,i;
//     for(i=0; i< lim-1 && (c=getchar())! EOF && c!= '\n'; ++i)
//     s[i]=c;

//     if (c=='\n'){
//         s[i]=c;
//         ++i;
//     }

//     s[i]='\0';
//     return i;

// }

// int reverse(char s[]);

// int main(){

//     int i,temp[];
//     int len;

//     for (i=0; strlen= len[i]-1;++i){
//         temp=i;
//         i= len[i]-1;

//     }
// }

#include<stdio.h>
#define MAXLINE 1000
int getline(char s[], int lim);
void reverse(char s[]);

int main(){
    int len;
    char line[MAXLINE];
    while ((len = getline(line,MAXLINE))>0){
       if (line[len-1]=='\n'){
        line[len-1]='\0';
        reverse(line);
        printf("%s\n",line);
       }
       
       else{
        reverse(line);
        printf("%s",line);
       }
    }
}
int getline(char s[],int lim){

    int c,i;
    for (i=0;i<lim-1 && (c=getchar())!=EOF && c!= '\n'; ++i){
        s[i]=c;
    }

    if(c=='\n'){
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    return i;
}

// void reverse(char s[]){
//     int i,j;
//     char temp;

//     for (j=0;s[j]!='\0';++j)
//     ;
//     {
//          for (i=0;j=j-1,i<j;++i,--j){
//             temp=s[i];
//             s[i]=s[j];
//             s[j]=temp;
//          }

//     }
// }

void reverse(char s[]){
    int i,j;
    char c;
    for (i=0,j=0; s[j]!='\0';++j)
    ;
    --j;
    while (i<j){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
        ++i;
        --j;
    }

}

