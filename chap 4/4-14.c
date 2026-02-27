#include<stdio.h>
// void swap(int t,int x,int y);
#define swap(t,x,y) t temp;temp=x;x=y;y= temp;

int main(){
    int x,y;
    printf("Enter a value of x:");
    scanf("%d",&x);
    printf("Enter a value of y:");
    scanf("%d",&y);

    printf("before swap x: %d,  y: %d\n", x,y);
    swap(int, x, y);
    printf("after swap x: %d,  y: %d",x,y);

}





// int main(void)
// {
//     int x=2;
//     int y=3;
//     // int t;

//     printf("x: %d, y= %d\n",x,y);
//     swap(int,x ,y);
//     printf("x=%d, y=%d\n",x,y);
//     return 0;
// }

// #define swap(t,x,y)do{
//     t_temp= (x);
//     (x)= (y);
//     (y) = temp;

// }; while(0)

// int main(){
//     int a,b;
//     printf("Enter two number(a,b):");
//     scanf("%d %d\n", &a,&b);
//     printf("before swap: a=%d, b=%d\n", a,b);
//     swap(int,a,b);
//     printf("after swap: a= %d, b=%d",a,b);

// }



