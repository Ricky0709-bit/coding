#include <iostream>
#define TABLE_SIZE 10
using namespace std;

class Node {
public:
    char name[50];
    Node* next;

    Node(const char* input) {
        int i = 0;
        while (input[i] != '\0' && i < 49) {
            name[i] = input[i];
            i++;
        }
        name[i] = '\0';
        next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

    int hashFunction(const char* name) {
        int hash = 0;
        int p = 31;
        int power = 1;

        for (int i = 0; name[i] != '\0'; i++) {
            hash = (hash + (name[i] - 'a' + 1) * power) % TABLE_SIZE;
            power = (power * p) % TABLE_SIZE;
        }

        return hash;
    }

    bool compareNames(const char* a, const char* b) {
        int i = 0;
        while (a[i] != '\0' && b[i] != '\0') {
            if (a[i] != b[i]) return false;
            i++;
        }
        return a[i] == b[i];
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(const char* name) {
        int index = hashFunction(name);
        Node* newNode = new Node(name);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted: " << name << " at index " << index << endl;
    }

    void search(const char* name) {
        int index = hashFunction(name);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (compareNames(temp->name, name)) {
                cout << "Name found: " << name << " at index " << index << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Name not found: " << name << endl;
    }

    void remove(const char* name) {
        int index = hashFunction(name);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (compareNames(temp->name, name)) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Deleted: " << name << " from index " << index << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Name not found, cannot delete: " << name << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            if (temp == nullptr) {
                cout << "NULL";
            } else {
                while (temp != nullptr) {
                    cout << temp->name << " -> ";
                    temp = temp->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* temp = table[i];
            while (temp != nullptr) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
    }
};

int main() {
    HashTable ht;
    int choice;
    char name[50];

    do {
        cout << "\nTelephone Directory Menu:\n";
        cout << "\n1. Insert Name\n";
        cout << "2. Search Name\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Delete Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name to insert: ";
                cin >> name;
                ht.insert(name);
                break;
            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                ht.search(name);
                break;
            case 3:
                ht.display();
                break;
            case 4:
                cout << "Enter name to delete: ";
                cin >> name;
                ht.remove(name);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
