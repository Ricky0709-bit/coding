#include<iostream>
using namespace std;

void coeff(int pol1[], int pol2[], int d1, int d2) {
    cout << "Enter the coefficients of the 1st polynomial: ";
    for (int i = d1; i >= 0; i--) {
        cin >> pol1[i];
    }

    cout << "Enter the coefficients of the 2nd polynomial: ";
    for (int i = d2; i >= 0; i--) {
        cin >> pol2[i];
    }
}

void printPolynomial(int pol[], int d, const string &name) {
    cout << name << " Polynomial equation: ";
    bool isFirst = true;
    for (int i = d; i >= 0; i--) {
        if (pol[i] != 0) {
            if (!isFirst) {
                cout << " + ";
            } else {
                isFirst = false;
            }

            if (pol[i] < 0) {
                cout << " - ";
                pol[i] = -pol[i];
            }

            if (i == 0) {
                cout << pol[i];
            } else if (i == 1) {
                cout << pol[i] << "x";
            } else {
                cout << pol[i] << "x^" << i;
            }
        }
    }
    if (isFirst) {
        cout << "0";
    }
    cout << "\n";
}

void poladd(int res[], int pol1[], int pol2[], int d1, int d2) {
    int d = (d1 > d2) ? d1 : d2; 
    for (int i = 0; i <= d; i++) {
        if (i <= d1 && i <= d2) {
            res[i] = pol1[i] + pol2[i];
        } else if (i <= d1) {
            res[i] = pol1[i];
        } else {
            res[i] = pol2[i];
        }
    }
}

int main() {
    int d1, d2;
    cout << "Enter the max. degree of polynomial 1 and 2:" << endl;
    cin >> d1 >> d2;

    int pol1[d1 + 1], pol2[d2 + 1], res[max(d1, d2) + 1]; 
    
    coeff(pol1, pol2, d1, d2);
    
    printPolynomial(pol1, d1, "1st");
    printPolynomial(pol2, d2, "2nd");
    
    poladd(res, pol1, pol2, d1, d2);  
    printPolynomial(res, max(d1, d2), "Resultant");

    return 0;
}
