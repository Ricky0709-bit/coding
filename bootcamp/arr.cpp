//1) WAP to enter the five elements in array and show it
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
 return 0;
}