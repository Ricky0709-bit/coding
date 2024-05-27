#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
private:
    string name;
    float price;
    int quantity;
public:
    void setData(string n, float p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Price: Rs " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    string getName() {
        return name;
    }

    float getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

    void updatePrice(float newPrice) {
        price = newPrice;
    }

    void updateQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    void updatename(string newName) {
        name = newName;
    }

    void createDataFile() {
        ofstream outFile("items.txt");
        if (!outFile) {
            cerr << "Error: Unable to create file!" << endl;
            return;
        }
        outFile.close();
        cout << "File created successfully." << endl;
    }

    void addItem() {
        ofstream outFile("items.txt", ios::app);
        if (!outFile) {
            cerr << "Error: Unable to open file!" << endl;
            return;
        }
        string name;
        float price;
        int quantity;
        cout << "Enter item details:" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Price: Rs ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;
        Item newItem;
        newItem.setData(name, price, quantity);
        outFile << name << " " << price << " " << quantity << endl;
        outFile.close();
        cout << "Item added successfully." << endl;
    }

    void searchItem(string itemName) {
        ifstream inFile("items.txt");
        if (!inFile) {
            cerr << "Error: Unable to open file!" << endl;
            return;
        }
        string name;
        float price;
        int quantity;
        bool found = false;
        while (inFile >> name >> price >> quantity) {
            if (name == itemName) {
                found = true;
                Item item;
                item.setData(name, price, quantity);
                cout << "Item found:" << endl;
                item.display();
                break;
            }
        }
        if (!found) {
            cout << "Item not found." << endl;
        }
        inFile.close();
    }

    void displayAllItems() {
        ifstream inFile("items.txt");
        if (!inFile) {
            cerr << "Error: Unable to open file!" << endl;
            return;
        }
        string name;
        float price;
        int quantity;
        while (inFile >> name >> price >> quantity) {
            Item item;
            item.setData(name, price, quantity);
            item.display();
            cout << endl;
        }
        inFile.close();
    }

    void updateItem(string itemName) {
        ifstream inFile("items.txt");
        if (!inFile) {
            cerr << "Error: Unable to open file!" << endl;
            return;
        }
        ofstream tempFile("temp.txt");
        string name;
        float price;
        int quantity;
        bool found = false;
        while (inFile >> name >> price >> quantity) {
            if (name == itemName) {
                found = true;
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new price: Rs ";
                cin >> price;
                cout << "Enter new quantity: ";
                cin >> quantity;
            }
            tempFile << name << " " << price << " " << quantity << endl;
        }
        inFile.close();
        tempFile.close();
        remove("items.txt");
        rename("temp.txt", "items.txt");
        if (found) {
            cout << "Item updated successfully." << endl;
        } else {
            cout << "Item not found." << endl;
        }
    }
};

int main() {
    Item obj;
    int choice;
    string itemName;
    cout << "\nWelcome to Inventory Management System" << endl;
    do {
        cout << "\nMenu:" << endl;
        cout << "\n1. Create Data File" << endl;
        cout << "2. Add Item" << endl;
        cout << "3. Search Item" << endl;
        cout << "4. Display All Items" << endl;
        cout << "5. Update Item" << endl;
        cout << "6. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                obj.createDataFile();
                break;
            case 2:
                obj.addItem();
                break;
            case 3:
                cout << "Enter item name to search: ";
                cin >> itemName;
                obj.searchItem(itemName);
                break;
            case 4:
                obj.displayAllItems();
                break;
            case 5:
                cout << "Enter item name to update: ";
                cin >> itemName;
                obj.updateItem(itemName);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
