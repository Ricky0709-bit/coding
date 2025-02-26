// 14) Write a program in C to find the majority element of an array ?
//A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).

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

 int count = 0;
 int major = arr[0];
 for(int i=0;i<n;i++)
 {
  if(arr[i] == major)
  {
    count++;
  }
  if(count == 0)
  {
    major = arr[i];
    count = 1;
  }
 }
  if(count>n/2)
  {
    cout<<"Majority element is: "<<major<<endl;
  }
  else
  {
    cout<<"No Majority element found."<<endl;
  }
 return 0;
}