//****************BUBBLE SORT SORTING ALGORITHM***************

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    int flag = 0;

    for (int i = 0; i < n - 1; i++)
    {

        flag = 0;

        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            flag = 1;
        }

        if (flag == 0)
        {
            break;
        }
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

    BubbleSort(arr, n);

    printArray(arr, n);

    return 0;
}