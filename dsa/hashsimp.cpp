#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

struct Entry {
    string name;
    string phone;
    bool isOccupied;
    bool isDeleted;
};

Entry hashTable[SIZE];

// Hash function based on first character of the name
int hashFunction(string name) {
    return (int(name[0]) % SIZE);
}

// Insert a new contact
void insert(string name, string phone) {
    int index = hashFunction(name);
    int originalIndex = index;

    while (hashTable[index].isOccupied && !hashTable[index].isDeleted) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            cout << "Hash table is full!\n";
            return;
        }
    }

    hashTable[index].name = name;
    hashTable[index].phone = phone;
    hashTable[index].isOccupied = true;
    hashTable[index].isDeleted = false;
    cout << "Contact added at index " << index << "!\n";
}

// Search a contact by name
void search(string name) {
    int index = hashFunction(name);
    int originalIndex = index;

    while (hashTable[index].isOccupied) {
        if (hashTable[index].name == name && !hashTable[index].isDeleted) {
            cout << "Found: " << name << " -> " << hashTable[index].phone << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == originalIndex) break;
    }

    cout << "Contact not found!\n";
}

// Delete a contact by name
void deleteContact(string name) {
    int index = hashFunction(name);
    int originalIndex = index;

    while (hashTable[index].isOccupied) {
        if (hashTable[index].name == name && !hashTable[index].isDeleted) {
            hashTable[index].isDeleted = true;
            cout << "Contact " << name << " deleted successfully!\n";
            return;
        }
        index = (index + 1) % SIZE;
        if (index == originalIndex) break;
    }

    cout << "Contact not found!\n";
}

// Display all contacts
void display() {
    cout << "\nTelephone Directory:\n";
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].isOccupied && !hashTable[i].isDeleted) {
            cout << i << ": " << hashTable[i].name << " -> " << hashTable[i].phone << endl;
        }
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].isOccupied = false;
        hashTable[i].isDeleted = false;
    }

    int choice;
    string name, phone;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Display Directory\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phone;
                insert(name, phone);
                break;
            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                search(name);
                break;
            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                deleteContact(name);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
