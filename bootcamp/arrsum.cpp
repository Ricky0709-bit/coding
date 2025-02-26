//2) WAP to enter the five elements in array and calculate the sum of all elements 
#include<iostream>
using namespace std;

int main()
{
 int x[5];

 cout<<"Enter  5 elements in array: "<<endl;
 for(int i=0;i<5;i++)
 {
    cin>>x[i];
 }

  cout<<"Elements in array are :"<<endl;
 for(int i=0;i<5;i++)
 {
    cout<<x[i]<<" ";
 }

 int sum = 0;
 cout<<"\nSum of elements is :"<<endl;
 for(int i=0;i<5;i++)
 {
   sum += x[i];
 }
 cout<<sum<<endl;
 return 0;
}
