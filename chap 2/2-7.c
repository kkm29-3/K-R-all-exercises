#include<stdio.h>
// definition
unsigned invert(unsigned x, int p, int n)
{
    unsigned mask= (~(~0u <<n) & (p+1-n));
    return x^mask;
}
//declare
int main(){
    unsigned x= 0b11111111;
    int p=2;
    int n=4;
    unsigned result= invert(x,p,n);
    printf("original x : %u\n (binary : ");
    for (int i=7; i>= 0; i--){
        printf("invert of x: %d\n", (x>>i)&1);
    }
    printf(")\n");

    printf("input bits of original: %d\n to invert bits %d%u\n(binary:", p,p-n+1,result);

    for(int i=7;i>=0;i--){
        printf("%d", (result >>i)&1);
    }
    printf(")\n");
}




// #include<stdio.h>
// int main()
// {
//     int n;
//     n= n& 0177;
//     printf("%d\n",n);

//     // x= x|SET_ON;
//     // printf("%d",x);

//     int x=2;
//     int y=3;

//     printf("%d\n",x&y);
//     printf("%d\n",x&&y);

//     printf("%d\n",x<<1);
//     printf("%d\n",y>>2);

// }

// return x with n bits that begin at position p
