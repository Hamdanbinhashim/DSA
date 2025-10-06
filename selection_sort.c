#include <stdio.h>

void selectionSort(int a[],int n)
{   
   for (int i=0;i<n-1;i++)
   {
      int min=i;
      for (int j=i+1;j<n;j++)
      {
         if (a[min] > a[j])
            min=j;
      }
      int temp=a[min];
      a[min]=a[i];
      a[i]=temp;    
   }   
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
    selectionSort(a,n);
    printf("\nSorted array:");
    for (int i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
        
    }
    printf("\n");
}            
    
            
         
         
