#include <stdio.h>
void main()
{

  int n,temp,flag=0,i,j,key;
  printf("Enter number of elements:");
  scanf("%d",&n);
  int a[n];
  printf("Enter elements:");
  for (i=0;i<n;i++)	
      scanf("%d",&a[i]);
  for(i=0;i<n-1;i++)
     for(j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])
        {
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
        }    
   printf("Sorted array:");
   for (i=0;i<n;i++)	
      printf("%d ",a[i]); 
   printf("\nEnter Key:");
   scanf("%d",&key);
   int low=0,high=n-1;
   while (low<=high)
   {
      int mid=(low+high)/2;
      if (a[mid]==key)
      {
         printf("Key found at index:%d\n",mid);
         flag=1;
         break;
      }  
      else if(a[mid]>key)
         high=mid-1;
      else
         low=mid+1;
   }
   if (flag==0)
       printf("Key not found\n");             
}      
      
      
      
      
      
         
    
    
    
    
    
    
    
   
       
