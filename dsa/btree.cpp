#include <iostream>
using namespace std;

const int MAX = 3; // Max keys per node (order = MAX+1)

class BTreeNode {
public:
    int keys[MAX];
    BTreeNode* children[MAX + 1];
    int numKeys;
    bool leaf;

    BTreeNode(bool isLeaf) {
        leaf = isLeaf;
        numKeys = 0;
        for (int i = 0; i < MAX + 1; i++) children[i] = nullptr;
    }

    void traverse();
    BTreeNode* search(int k);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode* y);
};

class BTree {
public:
    BTreeNode* root;

    BTree() { root = nullptr; }

    void traverse() {
        if (root) root->traverse();
    }

    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(int k);
};

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < numKeys; i++) {
        if (!leaf)
            children[i]->traverse();
        cout << keys[i] << " ";
    }

    if (!leaf)
        children[i]->traverse();
}

BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < numKeys && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf)
        return nullptr;

    return children[i]->search(k);
}

void BTree::insert(int k) {
    if (!root) {
        root = new BTreeNode(true);
        root->keys[0] = k;
        root->numKeys = 1;
    } else {
        if (root->numKeys == MAX) {
            BTreeNode* s = new BTreeNode(false);
            s->children[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->children[i]->insertNonFull(k);
            root = s;
        } else
            root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = numKeys - 1;

    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        numKeys++;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (children[i + 1]->numKeys == MAX) {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->leaf);
    z->numKeys = MAX / 2;

    for (int j = 0; j < MAX / 2; j++)
        z->keys[j] = y->keys[j + (MAX / 2) + 1];

    if (!y->leaf) {
        for (int j = 0; j < MAX / 2 + 1; j++)
            z->children[j] = y->children[j + (MAX / 2) + 1];
    }

    y->numKeys = MAX / 2;

    for (int j = numKeys; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = numKeys - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[MAX / 2];
    numKeys++;
}

int main() {
    BTree tree;
    int choice, key;

    do {
        cout << "\n--- B-Tree Menu ---\n";
        cout << "1. Insert\n2. Traverse\n3. Search\n4. Exit\nEnter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                tree.insert(key);
                cout << "Key " << key << " inserted successfully.\n";
                break;
            case 2:
                cout << "Tree: ";
                tree.traverse();
                cout << endl;
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (tree.search(key)) 
                    cout << "Key " << key << " found.\n";
                else 
                    cout << "Key " << key << " not found.\n";
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

