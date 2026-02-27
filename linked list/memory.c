// Write a program to read and display values of an integer array. Allocate space dynamically for the array. 

//using malloc
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// int i, n;
// int *arr;
// printf("\n Enter the number of elements ");
// scanf("%d", &n); 
// arr = (int *)malloc(n  *  sizeof(int));

// if(arr == NULL)
// {
//     printf(" \n Memory Allocation Failed");
//     exit(0);
// }
// for(i = 0;i < n;i++)
// {
//     printf("\n Enter the value %d of the array: ", i);
//     scanf("%d", &arr[i]);
// }
// printf("\n The array contains \n");
// for(i = 0;i < n;i++)
// printf("%d", arr[i]); 
// return 0;
// }

//using calloc
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int i,n;
    int *arr;
    printf ("\n Enter the number of elements: ");
    scanf("%d",&n);
    arr = (int*) calloc(n,sizeof(int));
    if (arr==NULL) 
        exit (1);
    printf("\n Enter the %d values to be stored in the array: ", n);
    for (i = 0; i < n; i++)
        scanf ("%d",&arr[i]);
        printf ("\n You have entered: ");
    for(i = 0; i < n; i++) 
        printf ("%d",arr[i]);
        free(arr);
    return 0;
}