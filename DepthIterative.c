#include <stdio.h>
#include <time.h>

#define SIZE 6

void print_map(int map[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j) printf("%d  ", map[i][j]);
        printf("\n");
    }
    printf("\n");
}

void print_queue(int queue[SIZE * SIZE][2], int size)
{
    if (!size) return;
    for (int i = 0; i < SIZE * SIZE; ++i) printf("%d, %d\n", queue[i][0], queue[i][1]);
    printf("------\n");
}

void solve(int ori[SIZE][SIZE], int map[SIZE][SIZE], int x, int y)
{
    int number = ori[x][y]; // Get the number to look for
    map[x][y] = 1;          // Flip the current coordinate in the mapping to true

    int queue[SIZE * SIZE][2]; // Initialize the queue
    for (int i = 0; i < SIZE * SIZE; ++i) for (int j = 0; j < 2; ++j) queue[i][j] = 0;

    int queue_index = 0, queue_size = 1;                   // To keep track of current index and the size of queue
    queue[queue_index][0] = x, queue[queue_index][1] = y;  // Initialize first in the queue to be the given coordinate

    while (queue_size)
    {
        // Loop through the whole board (all rows and columns)
        // For every (current) cell, we are checking if it is adjacent to the check cell (the latest x, y in queue)
        // If it neighbors check cell, and is equal to number, and the mapping at that coordinate is 0
        // then mark that location i, j on the map as 1, add it to the queue, and re-run the loop (reset i & j to zero)
        // with the check cell as the newly added to queue i, j coordinate
        // If we have gone through whole board, and nothing is flipped
        // It means we have completed the check cell and need to remove the latest check cell in queue

        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if (ori[i][j] != number || map[i][j]) continue; // If current cell != number, and already visited, skip

                int curr_x = queue[queue_index][0], curr_y = queue[queue_index][1]; // Get the check cell coordinate
                if (i == curr_x && j == curr_y) continue;                           // If it is the check cell, skip

                int up_x = (i - 1 >= 0 && i - 1 < SIZE) ? i - 1 : -1;
                int down_x = (i + 1 >= 0 && i + 1 < SIZE) ? i + 1 : -1;
                int right_y = (j + 1 >= 0 && j + 1 < SIZE) ? j + 1 : -1;
                int left_y = (j - 1 >= 0 && j - 1 < SIZE) ? j - 1 : -1;

                int up_check = (up_x != -1) ? up_x == curr_x && j == curr_y : 0;
                int down_check = (down_x != -1) ? down_x == curr_x && j == curr_y : 0;
                int right_check = (right_y != -1) ? i == curr_x && right_y == curr_y : 0;
                int left_check = (left_y != -1) ? i == curr_x && left_y == curr_y : 0;

                if (!up_check && !down_check && !right_check && !left_check) continue; // Skip if not neighboring

                map[i][j] = 1;               // Flip mapping to 1
                ++queue_index, ++queue_size; // Increment trackers
                queue[queue_index][0] = i;   // Add x-coordinate of current cell to queue
                queue[queue_index][1] = j;   // Add y-coordinate of current cell to queue
                i = 0, j = 0;                // Restart loop, same as "break" here for inner loop

            } // Inner loop, column
        } // Outer loop, row

        queue[queue_index][0] = 0;   // Reset it back to zero
        queue[queue_index][1] = 0;   // Reset it back to zero
        --queue_index, --queue_size; // Decrement Trackers

    } // Outer while loop, loop while queue_size > 0
}

int main()
{
    int arr[SIZE][SIZE] = {
            {1, 1, 1, 2, 3, 3},
            {1, 1, 2, 2, 3, 4},
            {1, 2, 2, 2, 4, 4},
            {1, 1, 1, 2, 4, 4},
            {4, 4, 4, 4, 4, 2},
            {4, 4, 4, 4, 2, 2}
    };

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int map[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) for (int j = 0; j < SIZE; ++j) map[i][j] = 0;

    solve(arr, map, 1, 5);
    print_map(map);

    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Number of operations: %.3f", cpu_time_used);

    return 0;
}
