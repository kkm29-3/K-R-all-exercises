#include<stdio.h>
// int escape (char s, char t)
void escape(char s[],char t[]){

    int i,j;
    for (i=0,j=0; t[i]!='\0'; i++){
        switch(t[i]){
            case '\n':
            s[j++]='\\';
            s[j++]='n';
            break;

             case '\b':
            s[j++]='\\';
            s[j++]='b';
            break;

             case '\t':
            s[j++]='\\';
            s[j++]='t';
            break;

             case '\\':
            s[j++]='\\';
            s[j++]='\\';
            break;

            default:
            s[j++]=t[i];
            break;
        }
    }
    s[j]='\0';
}

int main(){
    char s[100];
    char t[]="hello\tWorld\n";

    escape(s,t);
    printf("original: %s\n",t);
    printf("escape: %s",s);
}

// int main()
// {
//     char s[1000];
//     char t[1000];
//     int i=0;
//     int c;
//     printf("enter text: ");
//     while((c=getchar())!='\n'&& i<9){
//         t[i++] = c;
//     }

//     t[i]='\0';
//     escape(s,t);
//     printf("escaped: ");

//     for (int j=0;s[j]!='\0'; j++){
//         putchar(s[j]);
//     }

//     putchar('\n'); 
// }
