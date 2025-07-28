#include <stdio.h>

void main()
{
  int n,flag=0,i,j,key;
  printf("Enter number of elements:");
  scanf("%d",&n);
  int a[n];
  printf("Enter elements:");
  for (i=0;i<n;i++)	
      scanf("%d",&a[i]); 
  printf("Array:");
  for (i=0;i<n;i++)	
      printf("%d ",a[i]); 
  printf("\nEnter key:");
  scanf("%d",&key);
  for(i=0;i<n;i++)
    if (a[i]==key)
    {
       printf("key found at position:%d\n",i+1);
       flag=1;
       break;   
    }
  if (flag==0)
     printf("Key not found\n");
}          
