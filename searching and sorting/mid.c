#include <stdio.h>
// #include <conio.h>
#define MAX 20
int interpolation_search(int a[], int low, int high, int val)
{
  int mid;
  while(low <= high)
  {
    mid = low + (high - low)*((val - a[low]) / (a[high] - a[low])); //interpolation search expression
    if(val == a[mid])
      return mid;
    if(val < a[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int main(int argc, char *argv[]) 
{
    int arr[20], num, i, n, found = 0, pos = -1;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
}