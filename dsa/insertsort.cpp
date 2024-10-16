#include<iostream>
using namespace std;

void insert(int x[],int n)
{
 for(int i=0;i<=n-1;i++)
 {
  int v=x[i];
  int h=i;
  while(h>0 && x[h-1]>v)
  {
    x[h]=x[h-1];
    h=h-1;
    x[h]=v;
  }
 }

 for(int i=0;i<n;i++)
 {
    cout<<x[i]<<" ";
 }
}

int main()
{
 int n;
 cout<<"Enter the number of elements: ";
 cin>>n;
 int x[n];
 cout<<"Enter the elements: ";
 for(int i=0;i<n;i++)
 {
  cin>>x[i];
 }

 cout<<"Sorted array is: ";
 insert(x,n);
 return 0;
}