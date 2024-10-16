#include<iostream>
using namespace std;

struct  Node  {
    int data;
    Node* next;
};

Node* head = nullptr;

void createList(int n)
{
 Node* last = nullptr;

 for(int i=0;i<n;i++)
 {
    int value;
    cout << "Enter data for node " << i+1 << ": ";
    cin >> value;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
        newNode->next=head;
    }
    else
    {
        last->next = newNode;
    }
    last = newNode;
 }
 cout << "Circular linked list created successfully." << endl;
}

void insertNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;

    if(head==nullptr)
    {
        head = newNode;
        newNode->next=head;
        cout << "Circular linked list is empty. Cannot insert." << endl;
        return;
    }
    else
    {
        Node* temp = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        cout << "Node inserted successfully at the beginning." << endl;
    }
}

void deleteNode(int value)
{
    if(head==nullptr)
    {
        cout << "Circular linked list is empty. Cannot delete." << endl;
        return;
    }
    else
    {
        Node* temp = head;
        Node* prev = nullptr;
        while(temp->next!=head && temp->data!=value)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp->data==value)
        {
            if(temp==head)
            {
                head = temp->next;
            }
            prev->next = temp->next;
            delete temp;
            cout << "Node deleted successfully." << endl;
        }
        else
        {
            cout << "Node not found in the circular linked list." << endl;
        }
    }
}

void traverseList()
{
    if(head==nullptr)
    {
        cout << "Circular linked list is empty." << endl;
        return;
    }
    else
    {
        Node* temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }while(temp!=head);
        cout << "NULL" << endl;
    }
}

int main()
{
    int ch,n;
    
    do
    {
         cout << "\nMenu:\n";
        cout << "1. Create List\n";
        cout << "2. Insert Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Traverse List\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                cout << "Enter number of nodes to create: ";
                cin >> n;
                createList(n);
                break;
            case 2: {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                insertNode(value);
                break;
            }
            case 3: {
                int value;
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;
            }
            case 4:
                traverseList();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch!= 5);

    return 0;
}