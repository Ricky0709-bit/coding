#include<iostream>
using namespace std;

void coeff(int pol[],int d)
{
 cout << "Enter the coefficients of the polynomial: ";
 for (int i = d; i >= 0; i--) 
 {
    cin >> pol[i];
 }
}

void print(int pol[],int d)
{
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
}

int main()
{
 int d;
 cout << "Enter the degree of the polynomial: ";
 cin>>d;

 int pol[d+1];
 coeff(pol,d);
 print(pol,d);
 return 0;
}