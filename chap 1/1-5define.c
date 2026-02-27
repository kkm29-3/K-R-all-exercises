#include<stdio.h>
#define fahr 300// define constants
int main()

{
    int n;
    for (n= fahr; n>=0; n= n-20)
    printf("%3d %6.1f\n", n, (5.0/9.0)*(n-32));
}
