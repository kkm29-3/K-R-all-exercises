#include<stdio.h>
unsigned setbits(unsigned x,int p,int n,unsigned y);
int main(){
   unsigned x= 0b11111111;
   unsigned y= 0b00000000;

   int p=5; 
   int n=3;

   unsigned result = setbits(x,p,n,y);
   printf("result: %u\n (binary : ", result);
    
}
unsigned setbits(unsigned x,int p,int n,unsigned y)
{
    unsigned mask = ~ (~ 0u << n); //rightmost bits =1  
    unsigned y_part = (y& mask)<< (p+1-n); //shifted
    unsigned field_mask = mask << (p+1-n); //n bits wide at field at position x
    return (x& ~field_mask | y_part );

}














// #include<stdio.h>
// int main(){
//     int x;
//     x=x& ~077;
//     printf("%x",x);
// }