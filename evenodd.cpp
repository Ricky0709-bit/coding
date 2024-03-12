#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the no."<<endl;
    cin>>n;

    if(n % 2 == 0)
    {
        cout<< n <<"\neven"<<endl;
    }
    else
    {
        cout<<n<<"\nodd"<<endl;
    }
    return 0;
}

