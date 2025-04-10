#include<iostream>
using namespace std;
int main()
{
     int a,b,c,big;
     cout<<"enter the three nos."<<endl;
     cin>>a>>b>>c;

    big=(a>b)?a:b;
    big=(b>c)?b:c;
    big=(a>c)?a:c;

    cout<<"big="<<big<<endl;
    return 0;
}