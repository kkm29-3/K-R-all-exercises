#include<stdio.h>
#include<ctype.h>
int main()
{
    int c;
    
    while ((c=getchar()) != EOF)
    {
    if(isupper(c))
    {
        putchar(tolower(c));
    }
    else if(islower(c))
    {
        putchar(toupper(c));
    }
    else
        putchar(c);
    }
}

// int main(int argc, char *argv[]){
//     int c;
//     while(c=getchar()!=EOF)
//     switch(c){
//         case 'l':
//         putchar(tolower(c));
//         break;

//         case 'h':
//         putchar(toupper(c));
//         break;

//         default:
//         printf("error the input");
//         break;

//     }

// }
// struct converter{
//     char mode;
// };

// int main(int argc, char *argv[]){
//     int c;
//     struct converter conv;
//     conv.mode = argv[0][0];
    
//     while((c=getchar())!= EOF){
//         if(conv.mode =='l'){
//         if(isupper(c))
//         c= tolower(c);
//         }
//         else{
//             if(islower(c))
//                 c= toupper(c);
//         }
//         putchar(c);
//         }
// }