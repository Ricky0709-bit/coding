#include <iostream>
using namespace std;

void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[low];  
    int i = low + 1, j = high;

    while (true) 
    {
        while (i <= high && arr[i] <= pivot)
               i++; 
        while (arr[j] > pivot) 
               j--;              
        if (i >= j) 
               break;                       
        swap(arr[i], arr[j]);                    
    }
    swap(arr[low], arr[j]);                     
    return j;                                    
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);      
        quickSort(arr, low, pi - 1);            
        quickSort(arr, pi + 1, high);            
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    quickSort(arr, 0, n - 1);

    cout << "Sorted array using Quick Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;
}