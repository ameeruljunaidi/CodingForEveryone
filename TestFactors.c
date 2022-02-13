#include <limits.h>
#include <stdio.h>

#define TEST_COUNT 2147483647

int isPrime(int x)
{
    for (int i = 2; i < x / 2; i++)
    {
        if (x % i == 0) return 0;
    }

    return 1;
}

void printFactor(int n)
{
    int arr[1000];
    int arr_idx = 0;
    int number = n;
    int divisor = 2;

    if (isPrime(n))
    {
        arr[arr_idx] = n;
        arr_idx++;
        arr[arr_idx] = -1;
    }

    while (number > 1) // while the number is not 1, if 1 we stop
    {
        if (number % divisor == 0) // if the number can be divided by the divisor
        {
            number /= divisor;      // divide it
            arr[arr_idx] = divisor; // add it into the arr
            arr_idx++;              // increment the index to point to next slot in array
        }
        else {
            divisor++; // if number can't be divided by divisor anymore, then increment the divisor
        }

        arr[arr_idx] = -1; // set the end of the array to be -1
    }

    printf("Prime of %d: ", n); // print the factors, if any of the factors are not prime, then break the loop
    for (int i = 0; i < 1000; i++)
    {
        if (arr[i] == -1) break; // if end of list of factors, break the loop
        printf("%d ", arr[i]);

        if (!isPrime(arr[i])) // if the current factor is not prime, print error and break the loop
        {
            printf("Factor %d is not prime!", arr[i]);
            break;
        }
    }
    printf("\n");
}

int main()
{
    printf("%d", INT_MAX);
    // for (int i = 0; i < TEST_COUNT; i++) printFactor(i);
}
