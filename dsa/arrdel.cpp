#include<iostream>
using namespace std;

//Sorted & Unsorted Array

int findelement(int arr[], int n, int key);

int deleteelement(int arr[], int n, int key)
{
 int pos =findelement(arr, n, key);
 if(pos == -1)
 {
    cout<<"Element not found";
    return n;
 }

 int i;
 for(i=pos;i<n-1;i++)
    arr[i] = arr[i+1];
    return n-1;
}

int findelement(int arr[], int n, int key)
{
 int i;
 for(i=0;i<n;i++)
    if(arr[i] == key)
    return i;
    return -1;
}

int main()
{
    int i;
    int arr[] = {1,3,5,7,9};

    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
     
    cout<<"Array before deletion\n";
    for(i=0;i<n;i++)
     cout<<arr[i]<<"  ";

    n = deleteelement(arr, n, key);

    cout<<"\n Array after deletion\n";
    for(i=0;i<n;i++)
     cout<<arr[i]<<"  ";

    return 0;
}