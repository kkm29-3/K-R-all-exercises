#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// int main(){
//     char s[100];
//     char t[100];
//     size_t size_t;
//     printf("enter the first string:");
//     scanf("%99s", s);

//     printf("enter the second string:");
//     scanf("%99s", t);

//     printf("no of characters contaimed: ");
//     scanf("%zu", &size_t);

//     strncat(s,t, size_t);
//     printf("resulting string:%s\n", s);
// }


// void strncat_ptr(char *s,char *t,size_t n){
//     size_t s_length= strlen(s);
//     s+= s_length;

//     while((*s++ = *t++)!='\0' && n--)
//     ;
// }

// strncat_ptr
// void strncat_ptr (char *s, char *t, size_t n);

// int main(){
//     char s[100]=" this is the string";
//     char *t= ", this is second string";
//     size_t nr_chars= 5;
//     strncat_ptr(s,t,nr_chars);
//     puts(s);
// }
// void strncat_ptr (char *s, char *t, size_t n);



// // strncmp_ptr
// int strncmp_ptr(char *s, char *t, size_t n);

// int main(){
//      char s[100];
//     char t[100];
//     size_t size_t;
//     printf("enter the first string:");
//     scanf("%99s", s);

//     printf("enter the second string:");
//     scanf("%99s", t);

//     printf("no of characters compared: ");
//     scanf("%zu", &size_t);

//     int is_equal= strncmp(s,t,size_t);
//     if(is_equal==0){
//         puts("equal");
//     }
//     else if(is_equal<0){
//         puts("less");
//     }
//     else if(is_equal>0){
//         puts("more");
//     }
// }


// //strcmp
// int strncmp_ptr(char *s, char *t, size_t n){
//     while ((*s == *t) && --n)
//     {
//         if(*s =='\0')
//         ++s;
//         ++t;
//     }
// }

// int main(){
//     char s[100]= "this is the first string";
//     char *t= "this is the second string";
//     size_t nr_chars = 13;

//     int is_equal= strncmp_ptr(s,t,nr_chars);

//     if(is_equal==0){
//         puts("equal");
//     }
//     else if(is_equal<0){
//         puts("less");
//     }
//     else if(is_equal>0){
//         puts("more");
//     }
// }





// strncpy_ptr
void strncpy_ptr(char *s,char *t,size_t n);
int main(){
    char s[100];
    char t[100];
    size_t size_t;
    printf("enter the first string:");
    scanf("%99s", s);

    printf("enter the second string:");
    scanf("%99s", t);

    printf("no of characters copied from second and insert in first string: ");
    scanf("%u", &size_t);

    strncpy(s,t, size_t);
    printf("resulting string:%s\n", s);
}

void strncpy_ptr(char *s, char *t, size_t n ){
    while((*s++ = *t++) && --n)
        ;
}

// int main(){
//     char s[100]= "this is the first string";
//     char *t= "test is the second string, that is cool";
//     size_t nr_chars= 26;
//     strncpy_ptr(s,t,nr_chars);
//     puts(s);
// }
