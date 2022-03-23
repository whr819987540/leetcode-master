#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定一个数组nums，要求返回最长、严格递增、连续子序列的长度
// 和300的区别就在于674要连续
// [1,3,5,4,7]
// 3 [1,3,5] [1,3,5,7]或[1,3,4,7]虽然更长，但是不连续

// 1、数组含义：dp[i]表示前i个数的最长、严格递增、连续子序列的长度
// 2、递推公式：dp[i] = dp[i-1]+1，如果nums[i]>nums[i-1]；否则维持原值，然后继续从1开始递增
// 3、初始化：1
// 4、遍历顺序：递增
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    {
        Solution s;
    }
}