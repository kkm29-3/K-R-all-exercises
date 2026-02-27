//strend_ptr(s,t)
#include<stdio.h>
#include<string.h>

int strend_ptr(char *s, char *t);

int main()
{
    char *s= "this is string";
    char *t1= "string";
    char *t2= "random string";

    if(strend_ptr(s,t1))
    puts("t1 in s occurs");
    // return 1;
    else
    // puts("t2 in s not occurs");
    puts("0");
    // return 0;
    
    if(strend_ptr(s,t2))
    puts("t2 in s occurs");
    // return 1;
    else
    puts("t2 in s not occurs");
    // puts("0");
    // return 0;

}

int strend_ptr(char *s,char *t){
    size_t s_length=strlen (s);
    size_t t_length=strlen (t);
    s+=s_length-1;
    t+=t_length-1;
    while(*s-- == *t--)
    --t_length;
    return 1;
    return ! t_length;
    return 0;
}
























// #include<stdio.h>
// #include<string.h>
// int strend_ptr(char *s,char *t);
// int strend_ptr(char *s,char *t){
//     if(*s++ = *t++){
//         ;
//         printf("0\n");
//     }
//     else
//     printf("1\n");
    
// }

// //user input
// int main(){
//     char s[10]= "hello";
//     char t[10]="orld";

//     char p=strend_ptr(s,t);
//     printf("result:%s\n",p);

// }