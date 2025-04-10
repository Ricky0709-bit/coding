#include<iostream>
using namespace std;

//1.inserting element at end sorted/unsorted
/*int insertsorted(int arr[], int n, int key, int cap)
{
 if(n>= cap)
  return n;

 arr[n] = key;

 return (n+1);
}*/

//2.inserting an element in a sorted array
/*int insertsorted(int arr[], int n, int key, int cap)
{
 if(n>= cap)
  return n;

 int i;
 for(i=n-1;(i>=0 && arr[i]>key);i--)
  arr[i+1] = arr[i];
  arr[i+1] = key;

  return(n+1);

}*/

//for 1&2
/*int main()
{
 int arr[20] = {7,9,13,15,17,19};

 int cap = sizeof(arr) / sizeof(arr[0]);
 int n=6;
 int i, key = 21;
 cout<<"\n Before Insertion: ";
 for(i=0;i<n;i++)
   cout<<arr[i]<<" ";

 n = insertsorted(arr, n , key , cap);

 cout<<"\n After Insertion:";
  for(i=0;i<n;i++)
   cout<<arr[i]<<" ";

   return 0;
}*/

//3.inserting element at any position
void insertelemnt(int arr[], int n, int x, int pos)
{
    for(int i=n-1;i>=pos;i--)
       arr[i+1]=arr[i];

       arr[pos] = x;
}

int main()
{
 int arr[15] = {1,3,5,7,9,10};
 int n=6;

 cout<<"\n Before Insertion: ";
 for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";
   cout<<endl;

 int x = 8, pos = 6;
 insertelemnt(arr, n , x , pos);
 n++;

 cout<<"\n After Insertion:";
  for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";

   return 0;
}