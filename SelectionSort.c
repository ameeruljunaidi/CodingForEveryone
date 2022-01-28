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

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }

        swap(arr, i, minIndex);
    }
}

int testSelectionSort()
{
    int arr[] = {4, 2, 0, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArr(arr, size);

    sort(arr, size);

    printf("After sorting: ");
    printArr(arr, size);

    return 0;
}
