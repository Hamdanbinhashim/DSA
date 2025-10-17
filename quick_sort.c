#include <stdio.h>

void quickSort(int a[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = a[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    i++;
    int temp = a[i];
    a[i] = a[end];
    a[end] = temp;

    quickSort(a, start, i - 1);
    quickSort(a, i + 1, end);
}


void main()
{
    int n;
    printf("Enter size:");
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    printf("\nSorted array:");
    for (int i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
        
    }
    printf("\n");
}            
    
    

    
          
