#include<stdio.h>
#include<stdarg.h>
void minprintf(char *fmt, ...){
    va_list ap; // points to each unnamed arg in turn
    char *p, *sval;
    int ival;
    long lval;
    double dval;
    unsigned uval;
    
    va_start(ap,fmt); // make ap point to 1st unnamed arg
    for(p = fmt; *p; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        switch (*++p){
              //int
            case 'd':
            ival= va_arg (ap,int);
            printf("%d", ival);
            break;

            //float
            case 'f':
            dval =va_arg(ap,double);
            printf("%f", dval);
            break;

            //octal
            case 'o':
            uval =va_arg(ap,unsigned);
            printf("%o", uval);
            break;

            //hex
            case 'x':
            uval =va_arg(ap,unsigned);
            printf("%x", uval);
            break;

            //unsigned decimal nunmber
            case 'u':
            uval =va_arg(ap,unsigned);
            printf("%u", uval);
            break;

            //string
            case 's':
            for(sval = va_arg(ap, char*); *sval; sval ++)
            putchar(*sval);
            break;

            //double
            case 'l':
            if(*(p+1) == 'd'){
                lval = va_arg(ap,long);
                printf("%ld", dval);
                p++ ;
            }else if(*(p+1) == 'f')
            {
                dval = va_arg(ap,double);
                printf("%lf", dval);
            }
            break;

            default:
            putchar(*p);
            break;
        }
    }
va_end(ap);
}

//using scanf

int main(){
    int i;
    unsigned u;
    long l;
    double d;
    char str[50];
    char ch;
    
    printf("enter an integer:");
    scanf("%d", &i);

    printf("enter a unsigned:");
    scanf("%u", &u);

    printf("enter a long:");
    scanf("%ld", &l);

    printf("enter a double:");
    scanf("%lf", &d);

    printf("enter an string:");
    scanf("%s", str);

    minprintf("int= %d\n", i);
    minprintf("unsigned: %u\n", u);
    minprintf("long: %ld\n",l);
    minprintf("double: %lf\n", d);
    minprintf("string: %s\n", str);
    

}