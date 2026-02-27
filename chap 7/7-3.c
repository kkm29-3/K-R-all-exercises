#include<stdio.h>
#include<stdarg.h>
void minprintf(char *fmt, ...){
    va_list ap; // points to each unnamed arg in turn
    char *p, *sval;
    int ival;
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

            //char
            case 'c':
            ival= va_arg (ap,int);
            putchar(ival);
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

            default:
            putchar(*p);
            break;
        }
    }
va_end(ap);
}
int main(){
    int a=10;
    minprintf("int= %d\t, unsigned = %u\t, octal: %o\t, hex: %x\n", a,a,a,a);
}
// int main(){
//     int d;
//     double f;
//     unsigned o;
//     unsigned u;
//     char c;
//     char s;
//     minprintf("int: 111%d\n, double: 59.534 %f\n, octal: 0x76 %o\n, char: hi %c\n, unsigned decimal: 6.53 %u\n, string : "hello%s"", d,f,o,c,u,s);
// }