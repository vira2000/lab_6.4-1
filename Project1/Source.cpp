#include <iostream>
#include <cmath>

using namespace std;

void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i << " > ";
        cin >> arr[i];
    }
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findAbsMinEl(int* arr, int size)
{
    int min = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (abs(min) > abs(arr[i]))
            min = arr[i];
    }

    return min;
}

int indexOfFirstNegativeElement(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            return i;
    }

    return -1;
}

int sumOfAbsValuesFromIndex(int* arr, int size, int index)
{
    int sum = 0;

    for (int i = index; i < size; i++)
    {
        sum += abs(arr[i]);
    }

    return sum;
}

void removeElement(int* arr, int size, int index)
{
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0;
}

void removeElementsInRange(int* arr, int size, int a, int b)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= a && arr[i] <= b)
        {
            removeElement(arr, size, i);
            i--;
            size--;
        }
    }
}

int main()
{
    int n;

    cout << "N > ";
    cin >> n;

    int* arr = new int[n];

    fillArray(arr, n);

    cout << "Array: ";
    printArray(arr, n);

    cout << "Min abs value: " << findAbsMinEl(arr, n) << endl;

    int index = indexOfFirstNegativeElement(arr, n);

    cout << "Index of first negative element: " << index << endl;

    if (index != -1)
    {
        cout << "Sum of abs elements after first negative el: " << sumOfAbsValuesFromIndex(arr, n, index + 1) << endl;
    }

    int a, b;

    cout << "Deleting range from > ";
    cin >> a;

    cout << "Deleting range to > ";
    cin >> b;

    removeElementsInRange(arr, n, a, b);

    cout << "Result array: ";
    printArray(arr, n);

    return 0;
}