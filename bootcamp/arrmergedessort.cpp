//9) Write a program in C to merge two arrays of same size sorted in decending order.

#include<iostream>
using namespace std;

int main()
{
 int x[5];
 cout<<"Enter elements of array X:"<<endl;
 for(int i=0;i<5;i++)
 {
  cin>>x[i];
 }

 cout<<"Elements in array X are:"<<endl;
 for(int i=0;i<5;i++)
 {
    cout<<x[i]<<" ";
 }



 int y[5];
 cout<<"Enter elements of array Y:"<<endl;
 for(int i=0;i<5;i++)
 {
  cin>>y[i];
 }

 cout<<"Elements in array Y are:"<<endl;
 for(int i=0;i<5;i++)
 {
    cout<<y[i]<<" ";
 }

 int z[10];
 int i = 0, j = 0, k = 0;
    while (i < 5 && j < 5) {
        if (x[i] > y[j]) {
            z[k++] = x[i++];
        } else {
            z[k++] = y[j++];
        }
    }
   
    while (i < 5) {
        z[k++] = x[i++];
    }
    while (j < 5) {
        z[k++] = y[j++];
    }
    
    cout<<"\nDescending order of elements is:"<<endl;
 for(int i=0;i<10;i++)
 {
    for(int j=0;j<9;j++)
    {
     if(z[j]<z[j+1])
     {
        int temp=z[j];
        z[j]=z[j+1];
        z[j+1]=temp;
     }
    }
 }

 for(int i=0;i<10;i++)
 {
    cout<<z[i]<<" ";
 }
} 