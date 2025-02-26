#include<iostream>
using namespace std;

#define SIZE 10
struct Stack{
    int s[SIZE];
    int top;
}st;

int isempty(struct Stack* st )
{
 if(st->top==-1)
   return 1;
 else
   return 0;
}

int isfull(struct Stack* st)
{
 if(st->top==SIZE) 
   return 1;
 else 
   return 0;
}

int push(struct Stack* st, int value)
{
 if(!isfull(st))
 {
  st->top=st->top+1;
  st->s[st->top]=value;
  return 1;
 }
 else
 {
  cout<<"Stack Overflow.\n";
  return 0;
 }
}

int pop(struct Stack* st)
{
 int item;
 if(!isempty(st))
 {
  item = st->s[st->top];
  st->top=st->top - 1;
  return item;
 }
 else
 {
  cout<<"Stack Underflow\n";
  return -1;
 }
}

int peek(struct Stack* st)
{
 if(!isempty(st))
   return st->s[st->top];
 else
   cout<<"Stack is empty\n";
   return -1;
}

void print(struct Stack* st)
{
 if(isempty(st))
   cout<<"Stack is empty\n";
 else
 {
  cout<<"Stack Elements:\n";
  for(int i=st->top;i>=0;i--)
  {
    cout<<st->s[i]<<"\n";
  }
 }
}

int main()
{
 int ch, data;

 cout<<"Stack Operations:\n";
 cout<<" 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit\n";
 st.top = -1;

 do
 {
   cout<<"Enter Your Choice:";
   cin>>ch;

   switch(ch)
   {
    case 1:
      cout<<"Enter Data to Push:";
      cin>>data;
      if(push(&st, data))
        cout<<"Element pushed successfully\n";
        break;
    case 2:
     pop(&st);
     if(data!=-1)
       cout<<"Popped element is: "<<data<<"\n";
       break;
    case 3:
     data=peek(&st);
     if(data!=-1)
       cout<<"Top element is: "<<data<<"\n";
       break;
    case 4:
     print(&st);
     break;
    case 5:
     cout<<"Exiting...\n";
     break;
    default:
     cout<<"Invalid Choice\n";
   }
 }while(ch!=5);
 return 0;
}


