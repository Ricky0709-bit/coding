// 13)  Write a program in C to find if a given integer x appears more than n/2 times in a sorted array of n integers ?

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

 bool isMore = false;
 int count = 0;
 for(int i=0;i<n;i++)
 {
    if(arr[i] == x)
    {
     count++;
    }
    if(count > n/2)
    {
      isMore = true;
      break;
    }
 }

 if(isMore)
 {
    cout<<x<<" appears more than "<<n/2<<" times in the array.";
 }
 else
 {
    cout<<x<<" does not appear more than "<<n/2<<" times in the array.";
 }
 return 0;
}