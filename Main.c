#include <stdio.h>

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size * 2; ++i) printf("%d ", *(arr + i));
}

int main()
{
    int arr[2][2] = {{1, 2}, {3, 4}};
    print_arr(*arr, 2);
    return 0;
}