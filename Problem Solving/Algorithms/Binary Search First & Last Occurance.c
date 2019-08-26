#include <stdio.h>
#include <math.h>

int firstoccurance(int arr[],int data,int n)
{  
   
   int l=0,h=n-1,m;

   int result=-1;
   
   while(l<=h)
   {
   	m=(l+h)/2;
   	if(arr[m]==data)
   	{
     result=m;
     h=m-1;
   	}
   	else if(data>arr[m])
   	{
   	  l=m+1;
   	}
   	else
   	{
       h=m-1;
   	}
   }
     return result;
}
int lastoccurance(int arr[],int data,int n)
{  
  
   int l=0,h=n-1,m;
 
   int result=-1;
   
   while(l<=h)
   {
   	m=(l+h)/2;
   	if(arr[m]==data)
   	{
     result=m;
     l=m+1;
   	}
   	else if(data>arr[m])
   	{
   	  l=m+1;
   	}
   	else
   	{
       h=m-1;
   	}
   }
     return result;
}
int main()
{
   int arr[]={3,3,3,3,3,3,3,3,3};
   int n=sizeof(arr)/sizeof(arr[0]);
   printf("%d \n",lastoccurance(arr,3,n)-firstoccurance(arr,3,n)+1);
	return 0;
}