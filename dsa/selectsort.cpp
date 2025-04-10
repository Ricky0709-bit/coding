#include<iostream>
using namespace std;

void select(int x[], int n)
{
 for(int i=0;i<=n-1;i++)
 {
  int imin=i;
  for(int j=i+1;j<=n-1;j++)
  {
   if(x[j]<x[imin])
   {
    imin=j;
   }
  }
  int temp=x[i];
  x[i]=x[imin];
  x[imin]=temp;
 }   

 for(int i=0;i<n;i++)
 {
    cout<<x[i]<<" ";
 }
}

int main()
{
 int n;
 cout<<"Enter the no. of elements in array: ";
 cin>>n;
 
 int x[n];
 cout<<"Enter the elements of array: ";
 for(int i=0;i<n;i++)
 {
    cin>>x[i];
 }
 cout<<"Sorted array is: ";
 select(x,n);
 return 0;
}
