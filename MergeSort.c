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

void merge(int arr[], int startIndex, int midIndex, int endIndex)
{
    int rightSize = midIndex - startIndex + 1;
    int leftSize = endIndex - midIndex;
    int rightArr[rightSize], leftArr[leftSize];

    for (int i = 0; i < leftSize; i++) leftArr[i] = arr[midIndex + 1 + i];
    for (int j = 0; j < rightSize; j++) rightArr[j] = arr[startIndex + j];

    int leftIndex = 0, rightIndex = 0, mergedIndex = startIndex;

    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[mergedIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergedIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < leftSize)
    {
        arr[mergedIndex] = leftArr[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < rightSize)
    {
        arr[mergedIndex] = rightArr[rightIndex];
        rightIndex++;
        mergedIndex++;
    }
}

void sort(int arr[], int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return;

    int midIndex = startIndex + (endIndex - startIndex) / 2;
    sort(arr, startIndex, midIndex);
    sort(arr, midIndex + 1, endIndex);
    merge(arr, startIndex, midIndex, endIndex);
}

void testMergeSort()
{
    int arr[] = {0, 2, 4, 3, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before sort: ");
    printArr(arr, size);
    sort(arr, 0, size - 1);
    printf("After sort: ");
    printArr(arr, size);
}
