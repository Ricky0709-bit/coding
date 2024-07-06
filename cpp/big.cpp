#include<iostream>
using namespace std;
int main()
{
     int a,b,c;
     cout<<"enter the three nos."<<endl;
     cin>>a>>b>>c;

     if(a>b && a>c)
     {
        cout<<a<<"\n a is big"<<endl;
     }
     else if(b>a && b>c)
     {
        cout<<b<<"\n b is big"<<endl;
     }
     else
     {
        cout<<c<<"\n c is big"<<endl; 
     }
     return 0;
}