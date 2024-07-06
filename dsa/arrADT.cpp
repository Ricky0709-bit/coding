#include<iostream>
using namespace std;

class MyArray {
public:
    int totalSize;
    int usedSize;
    int* ptr;

    // Constructor to initialize the array
    MyArray(int totalSize, int usedSize) : totalSize(totalSize), usedSize(usedSize) {
        ptr = new int[totalSize];
    }

    // Destructor to free the memory
    ~MyArray() {
        delete[] ptr;
    }

    void show(MyArray *a)
    {
        for (int i = 0; i < a->usedSize; i++)
        {
            cout << a->ptr[i] << " ";
        }
    }

    void setVal(MyArray *a)
    {
        int n;
        for (int i = 0; i < a->usedSize; i++)
        {
            cout<<"enter element "<<i<<endl;
            cin >> n;
            a->ptr[i] = n;
        }
    }
};

int main() {
    MyArray a(10, 5);
    cout<<"we are running setval now \n"<<endl;
    a.setVal(&a);
    cout<<"we are running show now \n"<<endl;
    a.show(&a);
    return 0;
}