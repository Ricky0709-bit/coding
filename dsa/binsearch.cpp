#include<iostream>
using namespace std;

//Non recursive
/*int binsearch(int arr[], int low, int high, int key)
{
  int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }

    return -1;
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