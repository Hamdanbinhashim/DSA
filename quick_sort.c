#include <stdio.h>

void quickSort(int a[], int s, int n)
{
    if (s >= n)
        return;

    int pivot = a[n];
    int i = s - 1;
    for (int j = s; j < n; j++)
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
    a[i] = a[n];
    a[n] = temp;

    quickSort(a, s, i - 1);
    quickSort(a, i + 1, n);
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
    
    

    
          
