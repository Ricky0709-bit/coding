#include<iostream>
using namespace std;
int size=10;
int stack[10];
int top=-1;

int isfull()
{
 if(top==size)
    return 1;
 else
    return 0;
}

int push(int x)
{
 if(!isfull())
 {
  stack[++top]=x;
  return 1;
 }
 else
 {
  cout<<"Stack Overflow\n";
  return 0;
 }
 return x;
}

int main()
{
 push(13);
 push(35);
 push(45);
 push(55);
 push(65);

 cout<<"Stack Elements:\n";
 for(int i=top;i>=0;i--)
 {
  cout<<stack[i]<<"\n";
 }
 return 0;
}
