#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10

typedef struct list
{
    int *values; // An array of integers
    int length;  // The amount of elements added to the array
    int size;    // The total allotted space in the array
} list;

// Prototypes
list createList();                                                      // Initialize a list
void clearList(list *this);                                             // Reset list to empty with INII_SIZE size
void freeList(list *this);                                              // Free list from memory
void addNumber(list *this, int number);                                 // Add a number to the end of the list
void addAll(list *this, int arr[], int size);                           // Add all numbers in an array to list
void quickSort(list *this, int startIndex, int endIndex);               // Sort the list using quicksort
int partition(list *this, int startIndex, int endIndex);                // Helper function for quicksort
void swap(list *this, int firstIndex, int secondIndex);                 // Swap element between two indices
void mergeSort(list *this, int startIndex, int endIndex);               // Sort the list using mergesort
void merge(list *this, int startIndex, int midIndex, int endIndex);     // Helper function for merge sort
int binarySearch(list *this, int toFind, int startIndex, int endIndex); // Search an element using binary search
void reverse(list *this);                                               // Reverse the list
void printList(list *this);                                             // Print list

list createList()
{
    list this;

    this.values = (int *)calloc(INIT_SIZE, sizeof(int));
    this.length = 0;
    this.size = INIT_SIZE;

    return this;
}

void clearList(list *this)
{
    free(this->values);
    this->values = (int *)calloc(10, sizeof(int));
    this->length = 0;
    this->size = INIT_SIZE;
}

void freeList(list *this)
{
    free(this->values);
}

void addNumber(list *this, int number)
{
    if ((this->length) < this->size)
    {
        this->values[this->length] = number;
        this->length++;

        return;
    }

    this->values = (int *)realloc(this->values, this->size * 2 * sizeof(int));
    this->values[this->length] = number;
    this->length++;
    this->size = this->size * 2;
}

void addAll(list *this, int arr[], int size)
{
    for (int i = 0; i < size; i++) addNumber(this, arr[i]);
}

void printList(list *this)
{
    for (int i = 0; i < this->length; i++) printf("%d ", this->values[i]);
    printf("\n");
}

void swap(list *this, int firstIndex, int secondIndex)
{
    int temp = this->values[firstIndex];
    this->values[firstIndex] = this->values[secondIndex];
    this->values[secondIndex] = temp;
}

int partition(list *this, int startIndex, int endIndex)
{
    int pValue = this->values[endIndex];
    int pIndex = startIndex;

    for (int i = startIndex; i < endIndex; i++)
    {
        if (this->values[i] < pValue)
        {
            swap(this, i, pIndex);
            pIndex++;
        }
    }

    swap(this, pIndex, endIndex);

    return pIndex;
}

void quickSort(list *this, int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int pIndex = partition(this, startIndex, endIndex);
        quickSort(this, startIndex, pIndex - 1);
        quickSort(this, pIndex + 1, endIndex);
    }
}

void reverse(list *this)
{
    int front = 0;
    int back = this->length - 1;

    while (front < back)
    {
        swap(this, front, back);
        front++;
        back--;
    }
}

void merge(list *this, int startIndex, int midIndex, int endIndex)
{
    int leftSize = midIndex - startIndex + 1;
    int rightSize = endIndex - midIndex;

    int leftArr[leftSize], rightArr[rightSize];

    for (int i = 0; i < leftSize; i++) leftArr[i] = this->values[startIndex + i];
    for (int j = 0; j < rightSize; j++) rightArr[j] = this->values[midIndex + 1 + j];

    int leftIndex = 0, rightIndex = 0, mergedIndex = startIndex;

    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            this->values[mergedIndex] = leftArr[leftIndex];
            ++leftIndex;
        }
        else
        {
            this->values[mergedIndex] = rightArr[rightIndex];
            ++rightIndex;
        }
        ++mergedIndex;
    }

    while (leftIndex < leftSize)
    {
        this->values[mergedIndex] = leftArr[leftIndex];
        ++leftIndex;
        ++mergedIndex;
    }

    while (rightIndex < rightSize)
    {
        this->values[mergedIndex] = rightArr[rightIndex];
        ++rightIndex;
        ++mergedIndex;
    }
}

void mergeSort(list *this, int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        mergeSort(this, startIndex, midIndex);
        mergeSort(this, midIndex + 1, endIndex);
        merge(this, startIndex, midIndex, endIndex);
    }
}

int binarySearch(list *this, int toFind, int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return -1;

    int midIndex = startIndex + (endIndex - startIndex) / 2;

    if (this->values[midIndex] == toFind) return midIndex;
    if (this->values[midIndex] > toFind)
        return binarySearch(this, toFind, startIndex, midIndex);
    else
        return binarySearch(this, toFind, midIndex + 1, endIndex);
}

int testList()
{
    list test = createList();

    int numbers[] = {4, 0, 2, 3, 1, 5, 8, 6, 7, 15, 14, 13, 11, 12, 10, 9};
    int size = sizeof(numbers) / sizeof(int);

    addAll(&test, numbers, size);

    int toFind = 13;
    int searchResult = binarySearch(&test, toFind, 0, test.length - 1);
    (searchResult != -1)
        ? printf("Index of %d is: %d\nArray[%d] = %d\n", toFind, searchResult, searchResult, test.values[searchResult])
        : printf("Number not found in list");

    printf("Before sorting: ");
    printList(&test);

    printf("Quick sorting: ");
    quickSort(&test, 0, test.length - 1);
    printList(&test);

    freeList(&test);

    return 0;
}
