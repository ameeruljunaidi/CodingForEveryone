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

void sort(int arr[], int size)
{
    for (int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        int currentValue = arr[currentIndex];
        int traverseIndex = currentIndex - 1;

        while (traverseIndex >= 0 && arr[traverseIndex] > currentValue)
        {
            arr[traverseIndex + 1] = arr[traverseIndex];
            arr[traverseIndex] = currentValue;
            traverseIndex--;
        }
    }
}

void insertionSortTest()
{
    int arr[] = {4, 2, 0, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArr(arr, size);

    sort(arr, size);

    printf("After sorting: ");
    printArr(arr, size);
}
