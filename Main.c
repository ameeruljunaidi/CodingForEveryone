#include <stdio.h>
#include <stdlib.h>

int *aux; // A global pointer to an array  used during

void merge(int a[], int lo, int mid, int hi)
{
    int i = lo, j = mid, N = hi - lo;
    for (int k = 0; k < N; ++k)
    {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }
    for (int k = 0; k < N; ++k) a[lo + k] = aux[k];
}

void merge_sort(int a[], int lo, int hi)
{
    int N = hi - lo;
    if (N <= 1) return;
    int mid = lo + N / 2;
    merge_sort(a, lo, mid);
    merge_sort(a, mid, hi);
    merge(a, lo, mid, hi);
}

void sort(int a[], int s)
{
    aux = (int *) malloc(sizeof(int) * s);
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