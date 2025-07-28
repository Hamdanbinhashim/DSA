#include <stdio.h>

void main()
{
  int n,temp,i,j,b;
  printf("Enter number of elements:");
  scanf("%d",&n);
  int a[n];
  printf("Enter elements:");
  for (i=0;i<n;i++)	
      scanf("%d",&a[i]); 
  printf("Array:");
  for (i=0;i<n;i++)	
      printf("%d ",a[i]); 
  printf("\n");
  for(i=1;i<n;i++)
  {
     b=a[i];
     j=i-1;
     while (j>=0 && a[j]>b)
     {
       a[j+1]=a[j];
       j--;
       a[j+1]=b;
     }
   }     
  printf("Sorted array:");
   for (i=0;i<n;i++)
   {	
      printf("%d ",a[i]); 
   }
   printf("\n");
}   
           
