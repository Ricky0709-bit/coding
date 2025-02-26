#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    cout << "Enter the number of columns: ";
    cin >> cols;

    int arr[rows][cols];

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            cin >> arr[i][j];
        }
    }

    int row, col;
    cout << "Enter the row and column of the element you want the address for (0-indexed): ";
    cin >> row >> col;

    int *baseAddress = &arr[0][0];

    int elementSize = sizeof(arr[0][0]);

    int *rowmajor = baseAddress + ((row * cols + col) * elementSize);
    int *colmajor =baseAddress+((row+col*rows)*elementSize);

    cout << "Base address of the array: " << baseAddress << endl;
    cout << "Address of element at position (" << row << ", " << col << "): " << rowmajor <<"ANd"<<colmajor<< endl;

    return 0;
}
