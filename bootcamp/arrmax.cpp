//3)  WAP to enter the five elements in array and find out the maximum value 
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

 int max = x[0];
 for(int i=0;i<5;i++)
 {
    if(x[i]>max)
    {
     max = x[i];
    }
 }
 cout<<"\nMaximum value in array is:"<<max<<endl;
}