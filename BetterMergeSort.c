#include <stdio.h>
#include <stdlib.h>

int *aux; // A global pointer to an array  used during copying
          // This is better because only once copy is made throughout the program

/**
 * A function to merge two sub-arrays together
 *
 * i: index of left sub-array initialized to lo
 * j: index of right sub-array initialized to mid
 * N: size of the merged array (hi - lo, hence why we need hi to be last index + 1)
 *
 * Loop through all the entirety of the size of the merged array and insert elements to it depending on some conditions
 * The is one edge case, however: one sub-array might be fully copied over before the other
 * Meaning there would be left over in the other sub-array, this will be dealt with appropriately
 *
 * @param a is an array that contains all the integers (pass by reference)
 * @param lo the index of the first element
 * @param mid the index of the middle element
 * @param hi the index of the last element + 1
 */
void merge(int a[], int lo, int mid, int hi)
{
    int i = lo, j = mid, N = hi - lo;
    for (int k = 0; k < N; ++k)
    {
        if (i == mid) aux[k] = a[j++];         // if left sub-array completed, fill from right sub-array
        else if (j == hi) aux[k] = a[i++];     // and vice versa
        else if (a[j] < a[i]) aux[k] = a[j++]; // if element from right sub-array is smaller, add that to aux
        else aux[k] = a[i++];                  // and vice versa
    }
    for (int k = 0; k < N; ++k) a[lo + k] = aux[k]; // copy every thing back to original array
}

/**
 * Function to merge sort the array
 * Stop when the size of the array is exactly one or less than one
 *
 * @param a is an array that contains all the integers (pass by reference)
 * @param lo the index of the first element
 * @param hi  the index of the last element + 1
 */
void merge_sort(int a[], int lo, int hi)
{
    int N = hi - lo;
    if (N <= 1) return;
    int mid = lo + N / 2;
    merge_sort(a, lo, mid);
    merge_sort(a, mid, hi);
    merge(a, lo, mid, hi);
}

/**
 * Driver function to sort the array
 *
 * @param a is an array that contains all the integers (pass by reference)
 * @param s the size of the array
 */
void sort(int a[], int s)
{
    aux = (int *)malloc(sizeof(int) * s);
    merge_sort(a, 0, s);
    free(aux);
}

int main()
{
    int a[] = {230, 797, 783, 256, 606};
    int s = sizeof(a) / sizeof(a[0]);
    sort(a, s);
    for (int i = 0; i < s; ++i) printf("%d ", a[i]);
    return 0;
}