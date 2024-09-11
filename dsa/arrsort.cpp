#include<iostream>
using namespace std;

int main()
{
 int a[10];
 cout<<"Enter 10 numbers:"<<endl;
 for(int i=0;i<10;i++)
 {
    cin>>a[i];
 }   

 for(int i=0;i<10;i++)
 {
  for(int j=0;j<9;j++)
  {
    if(a[j]>a[j+1])
    {
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
    }
  }
 }
 cout<<"Sorted array is:\n"<<endl;
 for(int i=0;i<10;i++)
 {
    cout<<" "<<a[i];
 }
 return 0;
}