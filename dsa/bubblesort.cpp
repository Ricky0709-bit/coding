#include<iostream>
using namespace std;

void bubble(int x[], int n)
{
 for(int i=0;i<n-1;i++)
 {
  for(int j=0;j<n-i-1;j++)
  {
  if(x[j]>x[j+1])
  {
    int temp=x[j];
    x[j]=x[j+1];
    x[j+1]=temp;
  }
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
 cout<<"Enter the number of elements in the array: ";
 cin>>n;

 int x[n];
 cout<<"Enter unsorted elements in an array: ";
 for(int i=0;i<n;i++)
 {
    cin>>x[i];
 }
 cout<<"Sorted array is: "<<endl;
 bubble(x,n);
 return 0;
}