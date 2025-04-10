#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    void init() { 
        top = -1; 
    }
    void push(char c) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = c;
        }
    }
    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0';
    }
    bool isEmpty() { return top == -1; }
};

void reverseString(char str[]) {
    Stack stack;
    stack.init();
    for (int i = 0; str[i] != '\0'; i++) {
        stack.push(str[i]);
    }
    int i = 0;
    while (!stack.isEmpty()) {
        str[i++] = stack.pop();
    }
}

int main()
{
    char str[MAX_SIZE];
    cout << "Enter a string: ";
    cin.getline(str, MAX_SIZE);
    reverseString(str);
    cout << "Reversed string: " << str << endl;
    return 0;
}
