#include<stdio.h>
int binsearch (int x,int v[],int n)
{
    int low = 0; 
    int high = n-1;
    int mid;
    
    while(low<= high){
        mid = (low+high)/2;
        if (x<= v[mid])
        high = mid-1;
        else 
        low = mid + 1;
            }

    if (low<n && v[low]==x)
    return low; //found 

    else
    return -1;

}

int main(){
    int v[]={1,5,6,3,8};
    int n= sizeof(v)/sizeof(v[0]);
    int x=6;  //for search
    // int x;
    // x=getchar();
    // while (x!=EOF){
    //   putchar();
    //     break;
    // }
    int result = binsearch(x,v,n);

    if (result!= -1){
        printf("found: %d at index %d\n",x,result);
    }

    else
     printf("not found: %d",x);
    
}