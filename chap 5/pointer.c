// #include<stdio.h>
// int main(){
//     int x=1;
//     int y=2;
//     int z[10];

//     int *ip;

//     ip = &x;
//     y= *ip;
//     *ip = 0;
//     ip = &z[0];

//     printf("x:%d",&x);
//     printf("y:%d",y);
//     printf("z:%d",z);
// }


#include<stdio.h>
#include<ctype.h>

// int getch();
// void ungetch (int);

// int getint (int *pn)
// {
//     int c,sign;

//     while (isspace(c=getch()))
//     ;
//     if(!isdigit(c) && c!=EOF && c!= '+' && c!='-'){
//         ungetch(c);
//         return 0;
//     }

//     sign = (c=='-') ? -1 :1;
//     if(c== '+' || c== '-')
//     c=getch();
//     for (*pn=0; isdigit(c); c= getch())
//     *pn=10* *pn + (c-'0');

//     *pn *= sign;
//     if(c!= EOF)
//     ungetch(c);
//     return c;
// }

// intialization of pointer arrays
char *month_name (int n);
{

    static char *name[]={
        "illegal month", "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November","December"
    }

    return (n<1 || n> 12)? name[0] : name[n];

}
// int main()
// {
//     char *month_name (n);


// }