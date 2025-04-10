#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to check for balanced parentheses
bool isBalanced(string expression) {
    int balance = 0; // Keeps track of open parentheses
    for (char ch : expression) {
        if (ch == '(') {
            balance++;
        } else if (ch == ')') {
            if (balance == 0) {
                return false;
            }
            balance--;
        }
    }
    return balance == 0;
}

// Helper function to perform operations
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Function to evaluate a simple mathematical expression
int evaluateExpression(string expression) {
    stack<int> values;    // Stack to store values
    stack<char> operators; // Stack to store operators

    for (int i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        // Skip spaces
        if (ch == ' ') {
            continue;
        }

        // If the character is a digit, extract the full number
        if (isdigit(ch)) {
            int value = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            values.push(value);
            i--; // Adjust for the increment in the loop
        } 
        // If the character is an '(', push it to operators
        else if (ch == '(') {
            operators.push(ch);
        } 
        // If the character is ')', solve the sub-expression
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop(); // Remove '('
        } 
        // If the character is an operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!operators.empty() &&
                   ((ch == '+' || ch == '-') || (ch == '*' || ch == '/')) &&
                   ((operators.top() == '*' || operators.top() == '/') || (operators.top() == '+' || operators.top() == '-')) ) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(ch);
        }
    }

    // Evaluate the remaining expression
    while (!operators.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

int main() {
    string expression;

    cout << "Enter a mathematical expression: ";
    getline(cin, expression);

    if (!isBalanced(expression)) {
        cout << "Invalid expression: Unbalanced parentheses.\n";
    } else {
        int result = evaluateExpression(expression);
        cout << "The expression is valid. Result: " << result << "\n";
    }

    return 0;
}
