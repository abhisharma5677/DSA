//****************SELECTION SORT SORTING ALGORITHM***************

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    int i, j, k;

    for (int i = 0; i < n - 1; i++)
    {
        k = i;

        for (int j = i; j < n; j++)
        {
            if (arr[k] > arr[j])
            {
                // arr[i] = arr[j];            MISTAKE THAT I WAS DOING
                k = j;
            }
        }

        // Swapping
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {2, 5, 8, 3, 9, 1, 7, 6, 4};

    int n = (sizeof(arr) / sizeof(arr[0]));

    printArray(arr, n);

    SelectionSort(arr, n);

    printArray(arr, n);

    return 0;
}