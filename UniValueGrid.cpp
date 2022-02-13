#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution
{
  public:
    static int minOperations(vector<vector<int>> &grid, int x)
    {
        // x = 2
        //    2  4  6  8
        //   -----------
        // 2| 0  2  4  6
        // 4| 2  0  2  4
        // 6| 4  2  0  2
        // 8| 6  4  2  0
        // possible because all the difference has a factor 2

        // x = 1
        // 1: 4, 1, 2
        // 5: 4, 3, 2
        // 2: 1, 3, 1
        // 3: 2, 4, 1
        // possible because all the difference has a factor 1

        // x = 2
        // 1: 1, 2, 3
        // 2: 1, 1, 3
        // 3: 2, 1, 1
        // 4: 3, 2, 1
        // impossible because not all the difference has 2 as a factor

        vector<int> numbers;
        for (auto &row : grid) numbers.insert(numbers.end(), row.begin(), row.end());
        std::sort(numbers.begin(), numbers.end());

        int count = 0, median = numbers[numbers.size() / 2];
        for (const int &number : numbers)
        {
            if (abs(number - median) % x) return -1;
            count += abs(number - median) / x;
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    cout << Solution::minOperations(grid, 2);
}