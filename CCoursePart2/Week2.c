#include <stdio.h>
#include <stdlib.h>

typedef enum month
{
    jan,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
} month;

int month_lookup[12]; // An array to look up the last day of each month - month_lookup[0] = 31, month_lookup[1] = 28,
// month_lookup[2] = 31, ... , etc.

typedef struct date
{
    month current_month;
    int current_day;
} date;

// Function to check if the current day is the last day of the month
// This will be done using the month_lookup array defined above
int is_last_day(date date)
{
    if (date.current_day == month_lookup[date.current_month])
        return 1;

    return 0;
}

// Function to check if it is a valid date or note
// This will be done using the month_lookup array defined above
int invalid_date(date date)
{
    if (date.current_day > month_lookup[date.current_month])
        return 1;

    return 0;
}

// The function that returns a date for the next day
date nextday(date input)
{
    date ret; // Initialize the return date instance

    if (invalid_date(input)) // Exit program if date input is invalid
    {
        printf("Invalid date.");
        exit(1);
    }

    // If the current day is the last day, then proceed to next month and first day
    // If not, keep the current month, and add a day to the current day
    if (is_last_day(input))
    {
        if (input.current_month == 11)
            ret.current_month = 0;
        else
            ret.current_month = input.current_month + 1;

        ret.current_day = 1;
    }
    else
    {
        ret.current_month = input.current_month;
        ret.current_day = input.current_day + 1;
    }

    return ret;
}

// Function to print the date
void printdate(date date)
{
    if (invalid_date(date)) // Exit program if invalid date
    {
        printf("Invalid date.");
        exit(1);
    }

    switch (date.current_month)
    {
    case jan:
        printf("January ");
        break;
    case feb:
        printf("February ");
        break;
    case mar:
        printf("March ");
        break;
    case apr:
        printf("April");
        break;
    case may:
        printf("May ");
        break;
    case jun:
        printf("June ");
        break;
    case jul:
        printf("July ");
        break;
    case aug:
        printf("August ");
        break;
    case sep:
        printf("September ");
        break;
    case oct:
        printf("October ");
        break;
    case nov:
        printf("November ");
        break;
    case dec:
        printf("December ");
        break;
    }

    printf("%d", date.current_day);
}

int main(void)
{
    // Populate the lookup table
    for (int i = 0; i < 12; i++)
    {
        int max_days;

        if (i == 1)
            max_days = 28;
        else if (i == 3 || i == 5 || i == 8 || i == 10)
            max_days = 30;
        else
            max_days = 31;

        month_lookup[i] = max_days;
    }

    date input_date;         // Instantiate date variable
    int current_month_input; // Initialize current month input variable
    int current_day_input;   // Initialize current day input variable

    // Take user input for current month, exit program if invalid
    printf("Input current month (1: Jan, 2: Feb, ... , 12: Dec): ");
    scanf("%d", &current_month_input);
    current_month_input--;

    if (current_month_input < 0 || current_month_input > 11)
    {
        printf("Invalid month input. Please try again.");
        exit(1);
    }

    input_date.current_month = current_month_input;

    // Take user input for current day, exit program if invalid
    printf("Input current day: ");
    scanf("%d", &current_day_input);

    if (current_day_input < 1 || current_day_input > month_lookup[input_date.current_month])
    {
        printf("Invalid day input. Please try again.");
        exit(1);
    }

    input_date.current_day = current_day_input;

    // Last check, if invalid date, exit program
    if (invalid_date(input_date))
    {
        printf("Invalid date.");
        exit(1);
    }

    // Print answer
    printf("Today is ");
    printdate(input_date);
    printf(" and tomorrow is ");
    printdate(nextday(input_date));
    printf(".\n");
}
