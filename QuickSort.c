#include <stdio.h>

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
            printf("%d, ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
}

void swap(int arr[], int firstIndex, int secondIndex)
{
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
}

int partition(int arr[], int startIndex, int endIndex)
{
    int pValue = arr[endIndex];
    int pIndex = startIndex;

    for (int currentIndex = startIndex; currentIndex < endIndex; currentIndex++)
    {
        if (arr[currentIndex] <= pValue)
        {
            swap(arr, currentIndex, pIndex);
            pIndex++;
        }
    }

    swap(arr, pIndex, endIndex);
    return pIndex;
}

void sort(int arr[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int pIndex = partition(arr, startIndex, endIndex);
        sort(arr, startIndex, pIndex - 1);
        sort(arr, pIndex + 1, endIndex);
    }
}

void reverseArr(int arr[], int size)
{
    int front = 0, back = size - 1;
    while (front < back)
    {
        int temp = arr[front];
        arr[front] = arr[back];
        arr[back] = temp;
        front++;
        back--;
    }
}

void quickSort(int arr[], int size)
{
    sort(arr, 0, size - 1);
}
void testQuickSort()
{
    int arr[] = {0, 2, 4, 3, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before sort: ");
    printArr(arr, size);
    quickSort(arr, size);
    printf("After sort: ");
    printArr(arr, size);
}
