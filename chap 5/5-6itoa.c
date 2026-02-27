#include<stdio.h>
#include<string.h>
// itoa
void reverse (char *s);
void itoa(char *s, int n);

int main(){
    int i= 12;
    char s[100]="str";
    itoa(s,i);
    printf("itoa: %s", s);
}

void reverse(char *s){
    char *t= s+ strlen(s)-1;
    char aux= 0;

    if (*s =='\0')
    return;

    while (s<t)
    {
        aux= *t;
        *t-- = *s;
        *s++ = aux;/* code */
    }
    
    void itoa(char *s, int n){
        char *t=s;
        while(n)
        {
            *(t++) = n%10 +'0';
            n/=10;
            /* code */
        }
        *t ='\0';
        reverse(s);
    } 

}




// // atoi
// int atoi(const char *s);
// int main(){
//     int i;
//     char *s = "123s3a";
//     i= atoi(s);
//     printf("atoi: %d", i);
// }

// int atoi(const char *s){
//     int i=0;
//     while(*s != '\0' && *s >'0' && *s< '9'){
//         i=i*10 + *s - '0';
//         ++s;
//     }
//     return i;
// }


// getline
// void getline(char *s);
// int main(){
//     char string[150]= "";
//     getline (string);
//     puts(string);
// }

// void getline(char *s){
//     while((*s = getchar())!= EOF && (*s!= '\n')){
//         ++s;
//     }

//     *s= '\0';

// }


//reverse
// void reverse(char *s);
// int main(){
//     char s[100] = "test";
//     reverse(s);
//     puts(s);
// }

// void reverse (char *s){
//     char *t= s + strlen(s)-1;
//     char aux= 0;
//     if(*s == '\0')
//     return;

//     while (s<t)     
//     {
//         aux = *t;
//         *t -- = *s;
//         *s++ = aux;
//     }
// }

// // strindex
// int strindex(char *s, char *t);
// int main(){
//     char s[]="this is first string";
//     char t[]= "this";
//     printf("%d", strindex(s,t));
// }

// int strindex(char *s, char *t){
//     char *first;
//     char *second;
//     int pos=0;

//     while (*s!= '\0')
//     {
//         if(*s == *t){
//             first = s;
//             second = t;

//             while (*first++ == *second ++){
//                 if(*second== '\0')
//                 return pos;
//             }

//         }
//         pos ++;
//         s++;
//     }
//     return -1;
// }

// getop
// #include<ctype.h>
// #define NUMBER 0

// int getop(char *s);
// int main(){
//     char s[100]= "this ";
//     int type= getop(s);
//     printf("%d", type);
//     puts(s);
// }

// int getop(char *s){
//     char c;
//     while((*s = c= getchar())== ' '|| c== '\t')
//     ;
//     *(s+1)= '\0';
//     if(!isdigit(c) && c != '.')
//     while (isdigit(*(++s)=c=getchar ()))
//     ;

//     if(c=='.'){
//         while (isdigit(*(++s)=c=getchar()))
//        ;  
//     }

//     if(c!= EOF)
//     ungetc(c,stdin);
//     *s= '\0';
//     return NUMBER;
// }