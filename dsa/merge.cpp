#include<iostream>
using namespace std;

void mergesort(int *l,int *r,int *a,int nl,int nr)
{
    int i=0,j=0,k=0;
    while (i<nl && j<nr)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        a[k]=r[j];
        j++;
        k++;
    }
}

void merge(int *a,int n)
{
    if(n<2)
    {
        return;
    }
    int mid=n/2;
    int left[mid];
    int right[n-mid];
    
    for(int i=0;i<mid;i++)
    {
        left[i]=a[i];
    }
    for(int i=mid;i<n;i++)
    {
        right[i-mid]=a[i];
    }
    
    merge(left,mid);
    merge(right,n-mid);
    mergesort(left,right,a,mid,n-mid);
}
int main()
{
    int n;
    cout<<"Enter the no. of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The sorted array is:";
    merge(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}