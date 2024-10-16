#include <iostream>
using namespace std;

void countingSort(float arr[], int size) 
{
    int maxVal = int(arr[0]);
    for (int i = 1; i < size; i++) 
    {
        if (int(arr[i]) > maxVal) 
        {
            maxVal = int(arr[i]);
        }
    }

    int count[maxVal + 1] = {0};
    float output[size];

    for (int i = 0; i < size; i++) 
    {
        count[int(arr[i])]++;
    }

    for (int i = 1; i <= maxVal; i++) 
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) 
    {
        output[count[int(arr[i])] - 1] = arr[i];
        count[int(arr[i])]--;
    }

    for (int i = 0; i < size; i++) 
    {
        arr[i] = output[i];
    }
}

void insertionSort(float arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int size) 
{
    float maxVal = arr[0];
    float minVal = arr[0];

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
        if (arr[i] < minVal)
            minVal = arr[i];
    }

    float range = maxVal - minVal;

    int bucketCount = size;
    float buckets[bucketCount][size];
    int bucketSizes[bucketCount] = {0};

    for (int i = 0; i < size; i++) 
    {
        int bucketIndex = int((arr[i] - minVal) / range * (bucketCount - 1));
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) 
    {
        if (bucketSizes[i] > 0) 
        {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) 
            {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

void displayArray(float arr[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    float arr[size];
    cout << "Enter " << size << " values (integer or floating-point):" << endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }

    int choice;
    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Sort using Counting Sort\n";
        cout << "2. Sort using Bucket Sort\n";
        cout << "3. Exit\n";
        cout << "Choose an option (1-3): ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                countingSort(arr, size);
                cout << "Sorted array using Counting Sort: ";
                displayArray(arr, size);
                break;
            case 2:
                bucketSort(arr, size);
                cout << "Sorted array using Bucket Sort: ";
                displayArray(arr, size);
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
