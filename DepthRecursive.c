#include <stdio.h>
#include <time.h>

void print_map(int map[6][6])
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j) printf("%d  ", map[i][j]);
        printf("\n");
    }
    printf("\n");
}

void solve_overload(int arr[6][6], int map[6][6], int x, int y, int number)
{
    if (arr[x][y] != number || map[x][y]) return;
    map[x][y] = 1;

    int up_x = (x - 1 >= 0 && x - 1 < 6) ? x - 1 : -1;
    int down_x = (x + 1 >= 0 && x + 1 < 6) ? x + 1 : -1;
    int right_y = (y + 1 >= 0 && y + 1 < 6) ? y + 1 : -1;
    int left_y = (y - 1 >= 0 && y - 1 < 6) ? y - 1 : -1;

    if (up_x != -1) solve_overload(arr, map, up_x, y, number);
    if (down_x != -1) solve_overload(arr, map, down_x, y, number);
    if (right_y != -1) solve_overload(arr, map, x, right_y, number);
    if (left_y != -1) solve_overload(arr, map, x, left_y, number);
}

void solve_recursive(int arr[6][6], int map[6][6], int x, int y)
{
    int number = arr[x][y];
    solve_overload(arr, map, x, y, number);
}

int main()
{
    int arr[6][6] = {
            {1, 1, 1, 2, 3, 3},
            {1, 1, 2, 2, 3, 4},
            {1, 2, 2, 2, 4, 4},
            {1, 1, 1, 2, 4, 4},
            {4, 4, 4, 4, 4, 2},
            {4, 4, 4, 4, 2, 2}
    };

    int map[6][6];
    for (int i = 0; i < 6; ++i) for (int j = 0; j < 6; ++j) map[i][j] = 0;

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    // Start time tracking

    solve_recursive(arr, map, 1, 5);
    print_map(map);

    // End time tracking
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Number of operations: %.3f", cpu_time_used);

    return 0;
}