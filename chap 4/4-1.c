#include<stdio.h>
#include<string.h>
int strindex(char s[],char t[]);
int strindex(char s[],char t[])
{
    int i,j,k;
    int pos= -1;

    for (i=0;s[i]!='\0';++i){
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; ++j,++k){

            ;
        }

        if(k>0 && t[k]=='\0'){

            pos=i;
        }
    }
    return pos;
}

int main(){
    char s[100];
    char t[100];
    printf("Enter string s:");
    scanf("%s",s);

    printf("Enter string t:");
    scanf("%s",t);

    int pos = strindex(s,t);
    printf("rightmost position of  %s in %s is %d", t,s,pos);
    return 0;

}










// #define MAXLINE 1000

// int getline(char line[], int max);
// int strindex(char source[],char searchfor[]);

// char pattern[] = "ould";

// int main()
// {
//     char line[MAXLINE];
//     int found = 0;

//     while(getline(line,MAXLINE)>0)
//     if (strindex(line,pattern)>= 0){
//         printf("%s",line);
//         found++;
//     }
//     return found;
// }

// int getline(char s[], int lim){
//     int c,i;
//     i=0;
//     while(--lim > 0 && (c=getchar())!=EOF && c!='\n')
//     s[i++]=c;
//     if(c=='\n')
//     s[i++]=c;
//     s[i]='\0';
//     return i;
// }

// int strindex(char s[],char t[])
// {
//     int i,j,k;
//     int pos = -1;

//     for (i=0; s[i]!='\0';i++){
//         for (j=i,k=0;t[k]!='\0' && s[j]==t[k]; j++, k++)
//         ;
//     if (k>0 && t[k]== '\0')
    
//     return pos= i;
//     }
//     return -1;
// }

// int main(void)
// // char pattern[] = "ould"
// {
//     char s[]= "hello";
//     char t[]="ihkjg";
//     int pos= strindex(s,t);
//     printf("%d %s %d",t,s,pos);
// }