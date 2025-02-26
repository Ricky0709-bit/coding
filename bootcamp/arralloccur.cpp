// 17) WAP to enter the 10 element array and print the occurrence of all element ?

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool counted[n] = {false};

    for (int i = 0; i < n; i++)
    {
        if (!counted[i])
        {
            int count = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] == arr[i])
                {
                    count++;
                    counted[j] = true;
                }
            }
            cout << "Element " << arr[i] << " occurs " << count << " times." << endl;
        }
    }

    return 0;
}
