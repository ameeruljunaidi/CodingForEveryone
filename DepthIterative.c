#include <stdio.h>

void print_map(int map[6][6])
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j) printf("%d  ", map[i][j]);
        printf("\n");
    }
    printf("\n");
}

void print_queue(int queue[36][2], int size)
{
    if (!size) return;

    for (int i = 0; i < 36; ++i) printf("%d, %d\n", queue[i][0], queue[i][1]);
    printf("------\n");
}

void solve(int ori[6][6], int map[6][6], int x, int y)
{
    int number = ori[x][y]; // Get the number to look for
    map[x][y] = 1;          // Flip the current coordinate in the mapping to true

    int queue[6 * 6][2]; // Initialize the queue
    for (int i = 0; i < 6 * 6; ++i)
        for (int j = 0; j < 2; ++j)
            queue[i][j] = 0;

    int queue_index = 0, queue_size = 1; // To keep track of current index of queue and the size of queue
    queue[queue_index][0] = x;           // Initialize first in the queue to be current x-coordinate
    queue[queue_index][1] = y;           // Initialize first in the queue to be current y-coordinate

    while (queue_size)  // Loop wil run while there is something in the queue
    {
        int flipped = 0; // Variable to keep track if there is a cell in mapping that is flipped
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                // Get the check cell coordinate
                int curr_x = queue[queue_index][0];
                int curr_y = queue[queue_index][1];

                if (ori[i][j] != number) continue;        // If current cell is not equal to number, skip
                if (map[i][j]) continue;                  // If already visited (mapping already flipped), skip
                if (i == curr_x && j == curr_y) continue; // If it is the check cell, skip


                // Check if current cell is neighboring check cell
                // up_check, down_check, right_check, and left_check would be true if the current cell is neighboring
                // the check cell, which is the latest cell (coordinate x and y) added to the queue

                int up_x = (i - 1 >= 0 && i - 1 < 6) ? i - 1 : -1;
                int up_y = (up_x != -1) ? j : -1;
                int up_check = (up_x != -1 && up_y != -1) ? up_x == curr_x && up_y == curr_y : 0;

                int down_x = (i + 1 >= 0 && i + 1 < 6) ? i + 1 : -1;
                int down_y = (down_x != -1) ? j : -1;
                int down_check = (down_x != -1 && down_y != -1) ? down_x == curr_x && down_y == curr_y : 0;

                int right_y = (j + 1 >= 0 && j + 1 < 6) ? j + 1 : -1;
                int right_x = (right_y != -1) ? i : -1;
                int right_check = (right_x != -1 && right_y != -1) ? right_x == curr_x && right_y == curr_y : 0;

                int left_y = (j - 1 >= 0 && j - 1 < 6) ? j - 1 : -1;
                int left_x = (left_y != -1) ? i : -1;
                int left_check = (left_x != -1 && left_y != -1) ? left_x == curr_x && left_y == curr_y : 0;

                // Store checkers in an array
                // Loop checkers, if any checker is true, then add current cell to queue
                int checkers[4];
                checkers[0] = up_check;
                checkers[1] = down_check;
                checkers[2] = right_check;
                checkers[3] = left_check;

                for (int m = 0; m < 4; ++m)
                {
                    if (checkers[m])
                    {
                        map[i][j] = 1;             // Flip mapping to 1
                        ++queue_index;             // Increment queue index
                        ++queue_size;              // Increment queue size
                        queue[queue_index][0] = i; // Add x-coordinate of current cell to queue
                        queue[queue_index][1] = j; // Add y-coordinate of current cell to queue
                        flipped = 1;               // Toggle flipped
                        break;                     // We only need one of the checkers to be true
                    }
                }
            }
        }

        // If we have gone through whole board, and nothing is flipped, it means we have completed the check cell
        if (!flipped)
        {
            queue[queue_index][0] = 0; // Reset it back to zero
            queue[queue_index][1] = 0; // Reset it back to zero
            --queue_index;             // Decrement queue_index
            --queue_size;              // Increment queue_index
        }
    }
}

int main()
{
    int arr[6][6] = {
            {1, 1, 1, 2, 3, 3},
            {1, 1, 2, 2, 3, 4},
            {1, 2, 2, 2, 4, 4},
            {1, 1, 1, 2, 4, 4},
            {4, 4, 4, 4, 2, 2},
            {4, 4, 4, 4, 2, 2}
    };

    int map[6][6];
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            map[i][j] = 0;

    solve(arr, map, 1, 1);
    print_map(arr);
    print_map(map);

    return 0;
}
