#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution
{
public:
    static int maxSubArray(vector<int> &nums)
    {
        int largest = nums[0];
        int sum = 0;

        for (const int &num: nums)
        {
            if (sum < 0) sum = 0;
            sum += num;
            largest = std::max(sum, largest);
        }

        return largest;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution::maxSubArray(nums);
}