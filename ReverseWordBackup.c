#include <stdio.h>

void reverse_string(char *original_string, char *reversed_string, int size)
{
    int end_index = size, rs_index = 0;
    int is_first_word = 1, is_last_word = 1;

    for (int start_index = size; start_index >= 0; start_index--)
    {
        if (original_string[start_index] != ' ' && start_index != 0) continue;

        for (int j = start_index; j < end_index; j++)
        {
            if (is_first_word)
            {
                is_first_word = 0;
                continue;
            }

            if (start_index == 0 && is_last_word)
            {
                is_last_word = 0;
                reversed_string[rs_index] = ' ';
                rs_index++;
            }

            reversed_string[rs_index] = original_string[j];
            rs_index++;
        }

        end_index = start_index;
    }

    reversed_string[rs_index] = '\0';
}

int main()
{
    char original_string[] = "i am ironman";
    int size = (sizeof(original_string) / sizeof(original_string[0]) - 1);
    char reversed_string[size + 1];
    reverse_string(original_string, reversed_string, size);
    printf("%s\n", reversed_string);

    return 0;
}
