// 16) WAP to enter the 10 element array and print the occurrence of given element ?

#include<iostream>
using namespace std;

int main()
{
 int n;
 cout<<"Enter the size of array: ";
 cin>>n;

 int arr[n];
 cout<<"Enter the elements of array:";
 for(int i=0;i<n;i++)
 {
    cin>>arr[i];
 }

 cout<<"Enter the value of x: ";
 int x;
 cin>>x;

 int count = 0;
 for(int i=0;i<n;i++)
 {
  if(arr[i] == x)
  {
    count++;
  }
 }

 cout<<"The element "<<x<<" occurs "<<count<<" times in the array.";

 return 0;
}