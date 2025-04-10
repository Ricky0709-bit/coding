#include<iostream>
using namespace std;

int size = 10;
int queue[10];
int front = 0, rear = -1;

int isempty() {
 return front > rear; 
}

int isfull() {
 return rear == size - 1;
}

int enqueue(int value)
{
 if(!isfull())
{
  if(front != 0)
  {
    int j=0;
    for(int i=front;i<=rear;i++)
    {
     queue[j++] = queue[i];
    }
    rear = rear -front;
    front = 0;
  }
  queue[++rear] = value;
  return 1;
 }
 else {
  cout << "Queue Overflow." << endl;
  return 0;
 }
 return value;
}

int dequeue()
{
 if(!isempty())
 {
  return queue[front++];
  if(front>rear)
  {
    front = 0;
    rear = -1;
  }
 }
 else
 {
  cout<<"Queue is empty."<<endl;
  return -1;
 }
}

int peek()
{
 if(!isempty()) {
  return queue[front];
 }
 else {
  cout<<"Queue is empty."<<endl;
  return -1;
 }
}

void print()
{
 if(isempty()) {
   cout<<"Queue is Empty.\n";
 }
 else {
   cout<<"Queue Elements:\n";
   for(int i=front;i<=rear;i++)
   {
    cout<<queue[i]<<" ";
   }
   cout<<endl;
 }
}

int main()
{
 int ch,item;

 cout<<"Queue Operations:\n";
 cout<<" 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Display\n 5. Exit\n";

 do
 {
    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
     case 1:
      cout<<"Enter element to insert: ";
      cin>>item;
      if(enqueue(item))
       cout<<"Element inserted successfully\n";
       break;
     case 2:
      item=dequeue();
      if(item!=-1)
       cout<<"Deleted element is: "<<item<<"\n";
       break;
     case 3:
      item=peek();
      if(item!=-1)
       cout<<"First element is: "<<item<<"\n";
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

