#include<iostream>
#include<stack>
using namespace std;

int isbalanced(string exp)
{
    int count = 0;
    for(int i=0; i<exp.length(); i++)
    {
        char c = exp[i];
        if(c == '(')
        {
            count++;
        }
        else if(c == ')')
        {
            if(count == 0)
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
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int precedence(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int eval(string exp)
{
    stack<int> operands;
    stack<char> operators;

    for(int i=0; i<exp.length(); i++)
    {
        char c = exp[i];

        if(c >= '0' && c <= '9')
        {
            int value = 0;
            while(i < exp.length() && exp[i] >= '0' && exp[i] <= '9')
            {
                value = value * 10 + (exp[i] - '0');
                i++;
            }
            operands.push(value);
            i--; 
        }
        else if(c == '(')
        {
            operators.push(c);
        }
        else if(c == ')')
        {
            while(!operators.empty() && operators.top() != '(')
            {
                int a = operands.top();
                operands.pop();
                int b = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(operation(b, a, op));
            }
            operators.pop(); 
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            while(!operators.empty() && precedence(operators.top()) >= precedence(c))
            {
                int a = operands.top();
                operands.pop();
                int b = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(operation(b, a, op));
            }
            operators.push(c);
        }
    }

    while(!operators.empty())
    {
        int a = operands.top();
        operands.pop();
        int b = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        operands.push(operation(b, a, op));
    }

    return operands.top();
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
        cout << "The expression is valid.\nResult: " << result << "\n";
    }

    return 0;
}
