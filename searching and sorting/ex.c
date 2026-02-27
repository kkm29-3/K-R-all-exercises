//searching + sorting
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 20 // Added so the size of the array can be altered more easily
//search
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
    for(i=0;i<n;i++)
    {
        if(arr[i] == num)
        {
            found =1;
            pos=i;
            printf("\n %d is found in the array at position= %d", num,i+1); 
            /* +1 added in line 23 so that it would display the number in
                        the first place in the array as in position 1 instead of 0 */
            
            break;
        }
    }
    if (found == 0)
        printf("\n %d does not exist in the array", num);
    return 0;
}

//sort
int sort()
{
    int i, n, temp, j, arr[10];
    // clrscr();
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr [i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\n The array sorted in ascending order is :\n");
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
        getch();
    return 0;
}