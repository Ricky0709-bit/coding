#include <iostream>
using namespace std;

void merge(int x[], int L, int mid, int R) 
{
    int NL = mid - L + 1;
    int NR = R - mid;

    int left[NL], right[NR];

    for (int i = 0; i < NL; i++)
        left[i] = x[L + i];  

    for (int i = 0; i < NR; i++)
        right[i] = x[mid + 1 + i];

    int i = 0, j = 0, k = L;
    while (i < NL && j < NR) 
    {
        if (left[i] <= right[j]) 
        {
            x[k] = left[i];
            i++;
        } 
        else 
        {
            x[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < NL) 
    {
        x[k] = left[i];
        i++;
        k++;
    }

    while (j < NR) 
    {
        x[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int x[], int L, int R) {
    if (L < R) {
        int mid = L + (R - L) / 2;

        mergesort(x, L, mid);
        mergesort(x, mid + 1, R);

        merge(x, L, mid, R);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
