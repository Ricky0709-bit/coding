//5)WAP to find the all Even elements Form Array 
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
 
 cout<<"\nEven elements in array are:"<<endl;
 for(int i=0;i<5;i++)
 {
  if(x[i]%2 == 0)
  {
    cout<<x[i]<<" ";
  }
 }

}