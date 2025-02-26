//Q 11) Write a program in C to separate odd and even integers in separate arrays ?

#include<iostream>
using namespace std;

int main()
{
 int n;
 cout<<"Enter no. of elements in array:"<<endl;
 cin>>n;

 int arr[n];
 cout<<"Elements of array are: "<<endl;
 for(int i=0;i<n;i++)
 {
  cin>>arr[i];
 }

 int even[n], odd[n];
 int ecount =0 ,ocount = 0;
 for(int i=0;i<n;i++)
 {
  if(arr[i]%2==0)
  {
    even[ecount] = arr[i];
    ecount++;
  }
  else
  {
    odd[ocount] = arr[i];
    ocount++;  
  }
 }
 
 cout<<"Even numbers array:"<<endl;
 for(int i=0;i<ecount;i++)
 {
    cout<<even[i]<<" ";
 }

 cout<<"\n Odd numbers array:"<<endl;
 for(int i=0;i<ocount;i++)
 {
    cout<<odd[i]<<" ";
 }
 return 0;
}