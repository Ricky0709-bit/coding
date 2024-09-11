#include<iostream>
using namespace std;

int main()
{
    int d,pol[d+1];
    cout << "Enter the highest degree of polynomial: ";
    cin >> d;

   
    cout << "Enter the coefficients of polynomial: ";
    for (int i = d; i >= 0; i--)
    {
        cin >> pol[i];
    }

    cout << "Polynomial equation: ";
    bool isFirst = true;
    for (int i = d; i >= 0; i--)
    {
        if (pol[i] != 0)
        {
            if (!isFirst)
            {
                cout << " + ";
            }
            else
            {
                isFirst = false;
            }

            if (pol[i] < 0)
            {
                cout << " - ";
                pol[i] = -pol[i];
            }

            if (i == 0)
            {
                cout << pol[i];
            }
            else if (i == 1)
            {
                cout << pol[i] << "x";
            }
            else
            {
                cout << pol[i] << "x^" << i;
            }
        }
    }
    if (isFirst)
    {
        cout << "0";
    }
    cout << "\n";
 
    return 0;
}