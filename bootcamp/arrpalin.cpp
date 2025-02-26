//Q 12)  WAP To Check A given Array is Palindrome or Not :

#include<iostream>
using namespace std;

int main()
{
 int n;
 cout<<"Enter the size of array:";
 cin>>n;

 int arr[n];
 cout<<"Enter the elements of array:";
 for(int i=0;i<n;i++)
 {
  cin>>arr[i];
 }
 
 cout<<"Enter the elements of array:";
 for(int i=0;i<n;i++)
 {
    cout<<arr[i]<<" ";
 }

 bool isPalin = false;
 for(int i=0;i<n;i++)
 {
    if(arr[i]!= arr[n-i-1])
    {
     isPalin = false;
     cout<<"Not a palindrome."<<endl;
    }
    else
    {
        isPalin = true;
        cout<<"Palindrome."<<endl;
    }
 }
 return 0;

}
