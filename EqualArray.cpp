#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution
{
  public:
    static int minMoves2(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int count = 0, median = nums[nums.size() / 2];

        for (int &num : nums) count += abs(num - median);
        return count;
    }
};

int main()
{
    vector<int> numbers = {1, 2, 3};
    Solution::minMoves2(numbers);

    for (const int &num : numbers) { cout << num << " "; }

    cout << "\n";
}