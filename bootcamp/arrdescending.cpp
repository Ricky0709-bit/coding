//7) WAP to enter the five element and display in decending order 

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

 cout<<"\nDescending order of elements is:"<<endl;
 for(int i=0;i<5;i++)
 {
    for(int j=0;j<4;j++)
    {
     if(x[j]<x[j+1])
     {
        int temp=x[j];
        x[j]=x[j+1];
        x[j+1]=temp;
     }
    }
 }

 for(int i=0;i<5;i++)
 {
    cout<<x[i]<<" ";
 }
 return 0;
}
