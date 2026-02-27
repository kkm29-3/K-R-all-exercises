#include<stdio.h>
#define lower 0
#define upper 300
#define step 20
//declare
float temp(float fahr){
    return (5.0/9.0)*(fahr-32);

}
//calling 
int main()
{

    float fahr,cel;

    printf("fahr \n");
    for (fahr = lower; fahr<=upper;fahr+=step){
        cel=temp(fahr);
        printf("%3.0f %3.3f\n", fahr,cel);

    }
    return 0;
}