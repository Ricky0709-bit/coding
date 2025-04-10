#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node* create(int n);
void print(Node *head);
void count(Node *head);
void search(Node *head);
Node* insert_at_Begin(Node *head);
Node* insert_at_Middle(Node *head);
Node* insert_at_End(Node *head);
Node* delete_at_Begin(Node *head);
Node* delete_at_Middle(Node *head);
Node* delete_at_End(Node *head);

int main() 
{
    Node *Head = NULL;
    int no, op;

    do 
    {
        cout << "\n************ DLL OPERATIONS *************";
        cout << "\n1. Create\n2. Print\n3. Count\n4. Search";
        cout << "\n5. Insert at Begin\n6. Insert at Middle\n7. Insert at End";
        cout << "\n8. Delete from Begin\n9. Delete from Middle\n10. Delete from End\n11. Exit";
        cout << "\nEnter your choice: ";
        cin >> op;

        switch(op) 
        {
            case 1:
                cout << "\nEnter size of linked list: ";
                cin >> no;
                Head = create(no);
                break;
            case 2:
                print(Head);
                break;
            case 3:
                count(Head);
                break;
            case 4:
                search(Head);
                break;
            case 5:
                Head = insert_at_Begin(Head);
                break;
            case 6:
                Head = insert_at_Middle(Head);
                break;
            case 7:
                Head = insert_at_End(Head);
                break;
            case 8:
                Head = delete_at_Begin(Head);
                break;
            case 9:
                Head = delete_at_Middle(Head);
                break;
            case 10:
                Head = delete_at_End(Head);
                break;
            case 11:
                cout << "\nGoodbye! Thanks for using our application!";
                break;
            default:
                cout << "\nPlease select a valid option!";
        }
    } while(op != 11);

    return 0;
}

Node* create(int n) 
{
    Node *head = NULL, *p;
    int x;

    cout << "\nEnter data: ";
    cin >> x;
    head = new Node;
    head->data = x;
    head->prev = NULL;
    head->next = NULL;
    p = head;

    for(int i = 2; i <= n; i++) 
    {
        cout << "\nEnter data: ";
        cin >> x;
        p->next = new Node;
        p->next->data = x;
        p->next->prev = p;
        p->next->next = NULL;
        p = p->next;
    }

    cout << "\nLinked list created successfully!";
    return head;
}

void print(Node *head) 
{
    if (head == NULL) 
    {
        cout << "\nList is empty!";
        return;
    }

    Node *p = head;
    cout << "\nDLL Nodes: ";
    while(p != NULL) 
    {
        cout << p->data << " <-> ";
        p = p->next;
    }
    cout << "NULL";
}

void count(Node *head) 
{
    if (head == NULL) 
    {
        cout << "\nNo nodes in the list!";
        return;
    }

    int count = 0;
    Node *p = head;
    while(p != NULL) 
    {
        count++;
        p = p->next;
    }

    cout << "\nNumber of nodes: " << count;
}

void search(Node *head) 
{
    if (head == NULL) 
    {
        cout << "\nList is empty!";
        return;
    }

    int key, flag = 0;
    cout << "\nEnter key element to search: ";
    cin >> key;

    Node *p = head;
    while(p != NULL) 
    {
        if(key == p->data) 
        {
            flag = 1;
            break;
        }
        p = p->next;
    }

    if(flag == 1) 
    {
        cout << "\nElement found!";
    } 
    else 
    {
        cout << "\nElement not found!";
    }
}

Node* insert_at_Begin(Node *head) 
{
    Node *q = new Node;
    cout << "\nEnter data: ";
    cin >> q->data;
    q->next = head;
    q->prev = NULL;

    if(head != NULL) 
    {
        head->prev = q;
    }
    head = q;

    cout << "\nNode inserted at Begin successfully!";
    return head;
}

Node* insert_at_End(Node *head) 
{
    Node *q = new Node;
    cout << "\nEnter data: ";
    cin >> q->data;
    q->next = NULL;

    if(head == NULL) 
    {
        q->prev = NULL;
        head = q;
    } 
    else 
    {
        Node *p = head;
        while(p->next != NULL) 
        {
            p = p->next;
        }
        p->next = q;
        q->prev = p;
    }

    cout << "\nNode inserted at End successfully!";
    return head;
}

Node* insert_at_Middle(Node *head) 
{
    Node *q = new Node;
    int loc, i;
    cout << "\nEnter data: ";
    cin >> q->data;

    if(head == NULL) 
    {
        head = q;
        q->next = NULL;
        q->prev = NULL;
        cout << "\nNode inserted as the first node because list was empty";
    } 
    else 
    {
        cout << "\nEnter location for insertion: ";
        cin >> loc;

        Node *p = head;
        for(i = 1; i < loc-1 && p != NULL; i++) 
        {
            p = p->next;
        }

        q->next = p->next;
        if (p->next != NULL)
            p->next->prev = q;
        
        p->next = q;
        q->prev = p;

        cout << "\nNode inserted at middle successfully!";
    }

    return head;
}

Node* delete_at_Begin(Node *head) 
{
    if(head == NULL) 
    {
        cout << "\nLinked list is already Empty! Cannot delete node!";
        return NULL;
    }

    Node *q = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    
    delete q;

    cout << "\nNode deleted from Begin successfully!";
    return head;
}

Node* delete_at_End(Node *head) 
{
    if(head == NULL) 
    {
        cout << "\nLinked list is already Empty! Cannot delete node!";
        return NULL;
    }

    Node *q = head;
    while(q->next != NULL) 
    {
        q = q->next;
    }

    if (q->prev != NULL)
        q->prev->next = NULL;
    else
        head = NULL;

    delete q;
    cout << "\nNode deleted from End successfully!";
    return head;
}

Node* delete_at_Middle(Node *head) 
{
    if(head == NULL) 
    {
        cout << "\nLinked list is already Empty! Cannot delete node!";
        return NULL;
    }

    int loc, i;
    cout << "\nEnter location of node for deletion: ";
    cin >> loc;

    Node *p = head;
    for(i = 1; i < loc && p != NULL; i++) 
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "\nLocation out of range!";
        return head;
    }

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    delete p;
    cout << "\nNode deleted from middle successfully!";
    return head;
}
