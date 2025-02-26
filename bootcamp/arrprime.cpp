//10) WAP to find the all Prime Elements From Array .
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
 
 cout<<"\nPrime elements in array are:"<<endl;
 for(int i=0;i<5;i++)
 {
    if(x[i]>1)
    {
        bool isPrime = true;
        for(int j=2;j<=x[i]/2;j++)
        {
            if(x[i]%j==0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            cout<<x[i]<<" ";
        }
    }
 }

 return 0;
}