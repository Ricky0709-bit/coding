#include<iostream>
using namespace std;

int main()
{
    int r, c;
    cout << "Enter the number of rows and columns:";
    cin >> r >> c;

    int x[r][c], y[r][c], result[r][c];
    int sum = 0;

    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter the element at position [" << i << "][" << j << "] of matrix x: ";
            cin >> x[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter the element at position [" << i << "][" << j << "] of matrix y: ";
            cin >> y[i][j];
        }
    }

  
    cout << "Matrix x is:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

  
    cout << "Matrix y is:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << y[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Multiplication of matrix x and y:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum = 0;
            for (int k = 0; k < c; k++)
            {
                sum += x[i][k] * y[k][j];
            }
            result[i][j] = sum;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
