#include<iostream>
using namespace std;
int size = 10;
int stack[10];
int top = -1;

int isempty()
{
 if(top==-1)
   return 1;
 else
   return 0;
}

int isfull()
{
 if(top==size)
    return 1;
 else
    return 0;
}

int push(int value)
{
 if(!isfull())
 {
  stack[++top]=value;
  return 1;
 }
 else
 {
  cout<<"Stack Overflow\n";
  return 0;
 }
 return value;
}

int pop()
{
 if(!isempty())
 {
  return stack[top--];
 }
 else
 {
  cout<<"Stack Underflow\n";
  return -1;
 }
}

int peek()
{
 if(!isempty())
   return stack[top];
 else
  {
   cout<<"Stack is Empty\n";
   return -1;
  }
}

void print()
{
 if(isempty())
   cout<<"Stack is Empty\n";
 else
 {
   cout<<"Stack Elements:\n";
   for(int i=top;i>=0;i--)
   {
    cout<<stack[i]<<"\n";
   }
 }
}

int main()
{
 int ch,item;

 cout<<"Stack Operations:\n";
 cout<<" 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit\n";

 do
 {
    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
     case 1:
      cout<<"Enter element to push: ";
      cin>>item;
      if(push(item))
       cout<<"Element pushed successfully\n";
       break;
     case 2:
      item=pop();
      if(item!=-1)
       cout<<"Popped element is: "<<item<<"\n";
       break;
     case 3:
      item=peek();
      if(item!=-1)
       cout<<"Top element is: "<<item<<"\n";
       break;
     case 4:
      print();
      break;
     case 5:
      cout<<"Exiting...\n";
      break;
     default:
      cout<<"Invalid choice\n";
    }
 }while (ch!=5);
 return 0;
}
