#include<iostream>
using namespace std;


//Non recursive
/*
int findelement(int arr[], int n, int key)
{
    int i;
    for(i=0;i<n;i++)
     if(arr[i]==key)
      return i;

    return -1;
}*/

//Recursive
int findelement(int arr[], int n, int key)
{
    if (n == 0) 
    {
        return -1;
    }
    else if (arr[n - 1] == key)
    {
        
        return n - 1;
    }
    return findelement(arr, n - 1, key);
}




int main()
{
 int arr[] ={5,7,3,9,4,2};
 int n = sizeof(arr)/ sizeof(arr[0]);

 int key = 3;


 int pos = findelement(arr, n, key);

 if(pos==-1)
    cout<<"Element Not Found";
 else                                                    
    cout<<"Element found at position : "<<pos + 1<<endl;

 
}
