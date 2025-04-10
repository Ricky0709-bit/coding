#include <iostream>
using namespace std;

const int MAX_KEYS = 3;

class BPTreeNode {
public:
    int keys[MAX_KEYS];
    BPTreeNode* children[MAX_KEYS + 1];
    BPTreeNode* next; 
    bool leaf;
    int numKeys;

    BPTreeNode(bool isLeaf) {
        leaf = isLeaf;
        numKeys = 0;
        next = nullptr;
        for (int i = 0; i < MAX_KEYS + 1; i++) children[i] = nullptr;
    }
};

class BPTree {
    BPTreeNode* root;

public:
    BPTree() { root = nullptr; }

    void insert(int key);
    void display();
};

void splitLeaf(BPTreeNode* parent, BPTreeNode* leaf, int index) {
    BPTreeNode* newLeaf = new BPTreeNode(true);
    int mid = (MAX_KEYS + 1) / 2;
    newLeaf->numKeys = MAX_KEYS - mid;

    for (int i = 0; i < newLeaf->numKeys; i++)
        newLeaf->keys[i] = leaf->keys[mid + i];

    leaf->numKeys = mid;
    newLeaf->next = leaf->next;
    leaf->next = newLeaf;

    for (int i = parent->numKeys; i > index; i--) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }

    parent->keys[index] = newLeaf->keys[0];
    parent->children[index + 1] = newLeaf;
    parent->numKeys++;
}

void insertInternal(BPTreeNode*& node, int key, BPTreeNode*& child) {
    if (node == nullptr) {
        node = new BPTreeNode(false);
        node->keys[0] = key;
        node->children[0] = child;
        node->children[1] = nullptr;
        node->numKeys = 1;
        return;
    }

    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) i++;

    insertInternal(node->children[i], key, child);

    if (node->numKeys == MAX_KEYS) {
        cout << "Internal node split required (not implemented in this simplified version).\n";
    }
}

void BPTree::insert(int key) {
    if (!root) {
        root = new BPTreeNode(true);
        root->keys[0] = key;
        root->numKeys = 1;
        return;
    }

    BPTreeNode* curr = root;
    BPTreeNode* parent = nullptr;

    while (!curr->leaf) {
        parent = curr;
        int i = 0;
        while (i < curr->numKeys && key > curr->keys[i]) i++;
        curr = curr->children[i];
    }

    int i = curr->numKeys - 1;
    while (i >= 0 && curr->keys[i] > key) {
        curr->keys[i + 1] = curr->keys[i];
        i--;
    }

    curr->keys[i + 1] = key;
    curr->numKeys++;

    if (curr->numKeys > MAX_KEYS) {
        if (!parent) {
            BPTreeNode* newRoot = new BPTreeNode(false);
            newRoot->children[0] = curr;
            splitLeaf(newRoot, curr, 0);
            root = newRoot;
        } else {
            splitLeaf(parent, curr, 0); 
        }
    }
}

void BPTree::display() {
    BPTreeNode* curr = root;
    while (curr && !curr->leaf) curr = curr->children[0];

    cout << "B+ Tree Leaves: ";
    while (curr) {
        for (int i = 0; i < curr->numKeys; i++)
            cout << curr->keys[i] << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    BPTree tree;
    int choice, key;

    do {
        cout << "\n--- B+ Tree Menu ---\n";
        cout << "1. Insert\n2. Display\n3. Exit\nEnter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                tree.insert(key);
                cout << "Key " << key << " inserted successfully.\n";
                break;
            case 2:
                tree.display();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
