#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    int arr[MAX_SIZE];
    int top;

    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) 
    {
        if (isFull()) 
        {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

int isbalanced(string exp)
{
    int count = 0;
    for (int i = 0; i < exp.length(); i++) 
    {
        char c = exp[i];
        if (c == '(') 
        {
            count++;
        } 
        else if (c == ')') 
        {
            if (count == 0) 
            {
                return false;
            }
            count--;
        }
    }
    return count == 0;
}

int operation(int a, int b, char op)
{
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int precedence(char op)
{
    if (op == '+' || op == '-') 
       return 1;
    if (op == '*' || op == '/') 
       return 2;
    return 0;
}

int eval(string exp)
{
    Stack operands, operators;

    for (int i = 0; i < exp.length(); i++) 
    {
        char c = exp[i];

        if (c >= '0' && c <= '9') 
        {
            int value = 0;
            while (i < exp.length() && exp[i] >= '0' && exp[i] <= '9') 
            {
                value = value * 10 + (exp[i] - '0');
                i++;
            }
            operands.push(value);
            i--; 
        } 
        else if (c == '(') 
        {
            operators.push(c);
        } 
        else if (c == ')') 
        {
            while (!operators.isEmpty() && operators.peek() != '(') 
            {
                int a = operands.pop();
                int b = operands.pop();
                char op = operators.pop();
                operands.push(operation(b, a, op));
            }
            operators.pop(); 
        } 
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(c)) 
            {
                int a = operands.pop();
                int b = operands.pop();
                char op = operators.pop();
                operands.push(operation(b, a, op));
            }
            operators.push(c);
        }
    }

    while (!operators.isEmpty()) 
    {
        int a = operands.pop();
        int b = operands.pop();
        char op = operators.pop();
        operands.push(operation(b, a, op));
    }

    return operands.peek();
}

int main() 
{
    string exp;

    cout << "Enter a mathematical expression: ";
    getline(cin, exp);

    if (!isbalanced(exp)) 
    {
        cout << "Invalid expression: Unbalanced parentheses.\n";
    } 
    else 
    {
        int result = eval(exp);
        cout << "The expression is valid. \n Result: " << result << "\n";
    }

    return 0;
}
