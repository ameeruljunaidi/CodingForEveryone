#include <stdio.h>

void reverse_string(char *original_string, char *reversed_string, int size)
{
    int end_index = size, rs_index = 0; // Initialize indices that we need to create new char array

    // Initialize a variable to check if this is the first word and last word to be added to the return array
    // We need this because this is one of the two edge cases mentioned later in this function body
    int is_first_word = 1, is_last_word = 1;

    for (int start_index = size; start_index >= 0; start_index--)
    {
        if (original_string[start_index] == ' ' || !start_index)
        {
            // If the current string is a space, that means we have just looped through one whole word
            // BUT, there are 2 edge cases: 1. last word in the sentence, and 2. first word in the sentence
            // Note that for edge case #2, this would not work since we won't reach a space
            // We would reach start_index == 0 for edge case #2

            for (int j = start_index; j < end_index; j++)
            {

                if (is_first_word) // To deal with edge case #1
                {
                    // For edge case #1, we do not want the first char in the return char array to be a space
                    // So start copying from index start_index + 1, if this is the first word in the return char array
                    // Do this by just skipping using the continue keyword

                    is_first_word = 0; // Toggle switch off

                    continue; // Skip this iteration (we do not need the space if first word)
                }

                if (!start_index && is_last_word) // To deal with edge case #2
                {
                    // For edge case #2, we do not want to miss the first word in the original char array
                    // We might miss it because of there is no space at the beginning of the original char array
                    // To fix this we only to add a space and move on to the next char

                    is_last_word = 0; // Toggle switch off

                    reversed_string[rs_index] = ' '; // Add the space
                    rs_index++;                      // Increment index of return char array
                }

                // Every time a char is copied over to the return char array, update the rs_index to point to the next
                // location in the return char array

                reversed_string[rs_index] = original_string[j];
                rs_index++;
            }

            // Once copying is done, update the end_index to be the index of the current start_index
            // This works for all cases, including edge case #2

            end_index = start_index;
        }
    }

    reversed_string[rs_index] = '\0'; // Make sure that the last char is null terminated
}

int main()
{
    char original_string[] = "i am ironman";
    int size = (sizeof(original_string) / sizeof(original_string[0]) - 1); // Without null character
    char reversed_string[size + 1];                                        // +1 to make space for null character
    reverse_string(original_string, reversed_string, size);
    printf("%s\n", reversed_string);

    return 0;
}