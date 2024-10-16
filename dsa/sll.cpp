#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void createList(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int value;
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertNode(int value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        head = newNode;
    } 
    else 
    {
        Node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(int value) 
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == value) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) 
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) 
    {
        cout << "Value not found in the list." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
}

void traverseList() 
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    int choice, n;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Create List\n";
        cout << "2. Insert Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Traverse List\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) 
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
    } while (choice != 5);

    return 0;
}
