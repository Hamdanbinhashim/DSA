#include <stdio.h>

void main()
{
  int n,temp,i,j;
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
  for(i=0;i<n-1;i++)
  {
     for(j=0;j<n-i-1;j++)
     {
        if(a[j]>a[j+1])
        {
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
        }
     }
   }     
   printf("Sorted array:");
   for (i=0;i<n;i++)
   {	
      printf("%d ",a[i]); 
   }
   printf("\n");
}   
   
   
   
   
   
