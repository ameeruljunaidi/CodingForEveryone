#include <math.h>
#include <stdio.h>

int main(void)
{
    // Program gives the sine of a value between 0 and 1 (non-inclusive)

    double value = 0.0;

    // This do-while loop will keep asking the user for input as until the user give a valid input
    // However, if the user puts a string, the program will stop and print out an error message instead

    do
    {
        // If the numeric input is not a valid input, throw this error message and keep asking for input

        if (value < 0 || value > 1)
            printf("Invalid number. Try again.\n");

        printf("Input a value (between 0 and 1 non-inclusive): ");
        scanf("%lf", &value);

        // If the numeric input is valid, then print out the answer
        // The loop will automatically break as the conditional statement for the loop is no longer true

        if (value > 0 && value < 1)
            printf("Sine of %lf is %lf", value, sin(value));

    } while (value < 0 || value > 1);

    // If the loop breaks without getting a valid numeric input, it is most likely because a string was given rather
    // than a numeric input

    if (value == 0.0)
        printf("Some unexpected error occurred. Did you enter a string instead of a number?\n");

    return 0;
}
