#include<iostream>
using namespace std;

int delmulelement(int a[], int n, int key)
{
  int i=0;
  for(int j=0;j<n;j++)
  {
    if(a[j] != key)
    {
     a[i] = a[j];
     i++;
    }
  }
  return i;
}

int main()
{
 int a[]={2,5,3,9,2,2,3};
 int n=sizeof(a)/sizeof(a[0]);
 
 int key=2;
 cout<<"Array before deletion\n";
    for(int i=0;i<n;i++)
     cout<<a[i]<<"  ";

    n = delmulelement(a, n, key);

    cout<<"\n Array after deletion\n";
    for(int i=0;i<n;i++)
     cout<<a[i]<<"  ";

    return 0;
}