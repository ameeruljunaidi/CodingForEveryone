#include <stdio.h>

#define MAX 100000

int main()
{
    int count = MAX;   // To keep track of how many integers to read in the do-while loop
    int arr_size = 0;  // To keep track of how many integers we have in the array to print later
    int arr[MAX];      // Initialize the array with MAX size
    char buffer;       // Initialize a temporary char variable to catch the empty space between integers
    int int_max = 0;   // Initialize variable to keep track of the maximum int
    int int_total = 0; // Initialize variable to keep track of total int
    double int_avg;    // Initialize variable to count average

    do // Do the following loop while array_size is less than count (which the user will input as first integer)
    {
        if (count == MAX) // If the count is still max, initialize it to the count from user input
        {

            scanf("%d%c", &count, &buffer);
        }
        else // If the user has already input a count of integers, take the integers and store them in the array
        {
            scanf("%d%c", &arr[arr_size], &buffer);

            int_total += arr[arr_size];  // Add the current int to the int_total variable

            if (arr[arr_size] > int_max) // If the current int is larger the currently stored, switch
            {
                int_max = arr[arr_size];
            }

            if (arr_size == count - 1)  // If this is the last int in the array, calculate the average
            {
                int_avg = (double)int_total / count;
            }

            arr_size++;
        }
    } while (arr_size < count);

    // Print the array
    printf("List of ints in array: ");
    for (int j = 0; j < arr_size; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");

    // Print the average and max
    printf("Average int is %lf and max int is %d", int_avg, int_max);

    return 0;
}
