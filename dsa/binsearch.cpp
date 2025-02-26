#include<iostream>
using namespace std;

//Non recursive
/*int binsearch(int arr[], int low, int high, int key)
{
 if(high < low)
    return -1;
 int mid = (high + low)/2;
 if(key==arr[mid])
   return mid;
 if(key>arr[mid])
   return binsearch(arr, (mid +1), high, key);
 return binsearch(arr, low, (mid - 1), key);
}*/

//Recursive
int binsearch(int arr[], int low, int high, int key)
{
    if (high >= low) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binsearch(arr, low, mid - 1, key);

        return binsearch(arr, mid + 1, high, key);
    }
  return -1;
}

int main()
{
 int arr[] ={5,7,3,9,4,2};
 int n = sizeof(arr)/ sizeof(arr[0]);

 int key = 3;
 cout<<"Index:"<<binsearch(arr, 0, n-1, key)<<endl;
 return 0;
}