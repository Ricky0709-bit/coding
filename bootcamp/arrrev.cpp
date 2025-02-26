//8) WAP to Reverse a Given Array 
#include<iostream>
using namespace std;

int main() 
{
 int x[5];
 cout<<"Enter elements of array"<<endl;
 for(int i=0;i<5;i++)
 {
  cin>>x[i];
 }

 cout<<"Elements in array are:"<<endl;
 for(int i=0;i<5;i++)
 {
    cout<<x[i]<<" ";
 }

 cout<<"\nReverse of an array is:"<<endl;
 int z[5];
 for(int i=0;i<5;i++)
 {
  z[i] = x[5 - 1 - i];
 }

 for(int i=0;i<5;i++)
 {
  cout<<z[i]<<" ";
 }
 return 0;
}