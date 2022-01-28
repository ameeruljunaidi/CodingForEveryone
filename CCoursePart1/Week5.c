#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main()
{
    char buff[MAX]; // Initialize a buffer variable of type string (char[])
    FILE *fp;       // Initialize a file pointer

    // Check if file exist in the system, if not, then print an error message and exit the program
    if ((fp = fopen("Input.txt", "r")) == NULL)
    {
        printf("Error opening the file.");
        exit(1);
    }

    fscanf(fp, "%[^\n]", buff); // Scan the file for the int and store them in the buffer
    fclose(fp);                 // Close the file once we already have all we need from the file

    // From here, we need to split the string based on some delimiter and store the numbers (which are still char[] at
    // this point) into an array that we can work with later on

    char delim[] = "  \t";           // The delimiter to split the char[] by
    char *ptr = strtok(buff, delim); // This pointer points to the first index location in the buffer with the delimiter

    // Use a while loop to get all the ints
    // First need to check with the function isdigit() to see if it is a valid number
    // If it is not a valid number, an error message will be printed and program will exit
    // Next need to convert the char[] that we have into an int, and then store it into the ints array

    if (!isdigit(*ptr)) // Check if the first entry in the file is a valid digit, exit if not
    {
        printf("Invalid number.");
        exit(1);
    }

    int count = atoi(ptr); // This variable keep tracks of how many ints we're supposed to keep
    int array[count];      // Initialize array of count size

    ptr = strtok(NULL, delim); // This moves the pointer to the next location after the delimiter was found
    // Essentially moving to the next weight

    int index = 0; // This will keep track of the current index within the loop
    int total = 0; // This will keep track of the total sum of ints
    int max = 0; // Variable to keep track of the largest number
    double average; // Initialize variable to store the average of all the ints

    while (ptr != NULL)
    {
        if (!isdigit(*ptr))
        {
            printf("Invalid number.");
            exit(1);
        }

        array[index] = atoi(ptr);
        total += array[index];

        if (index == count - 1) // If it is the last element, count the average
        {
            average = (double) total / count;
        }

        if (array[index] > max) // If the current element is larger than the one we have stored, replace
        {
            max = array[index];
        }

        index++;

        ptr = strtok(NULL, delim); // This moves the pointer to the next location after the delimiter was found
        // Essentially moving to the next weight
    }

    printf("The integers in array are: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\nThe average of the integers is %lf and the maximum integer is %d.\n", average, max);

    return 0;
}
