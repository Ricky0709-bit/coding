#include<iostream>
using namespace std;

int main()
{
  int n;
  cout<<"Enter the no.of elements:"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the elements:"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }

  cout<<"\nArray is:"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<< a[i];
  }

  cout<<"\nReverse of array is :"<<endl;
  for(int i=n-1;i>=0;i--)
  {
    cout<< a[i];
  }
  return 0;
}