//access and search for array
#include <stdio.h>
// #include <stdlib.h>
// #include <conio.h>
#define size 20 // Added so the size of the array can be altered more easily

int main(int argc, char *argv[]) 
{
    int arr[size], num, i, n, found = 0, pos = -1;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n Enter the number that has to be searched : ");
    scanf("%d", &num);
}