#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定一个数组，要求返回最长递增子序列的长度
// 子序列不要求连续，递增是指严格递增
// nums = [10,9,2,5,3,7,101,18]
// Output: 4 [2,3,7,101]

// 1、数组含义：dp[i]表示前i个数的最长递增子序列的长度
// 2、递推公式：需要考察前i-1个数，如果比第i个数小，dp[i]=max(dp[i],dp[j]+1)
// 3、初始化：1，至少只放自己也满足严格递增的定义
// 4、遍历顺序：递增
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // 越界检查
        if (nums.size() == 0)
        {
            return 0;
        }

        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        // 最后一个元素不一定是最长递增子序列的结束位置
        // 所以dp.back()不对
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    {
        Solution s;
        vector<int> data{10, 9, 2, 5, 3, 7, 101, 18};
        int res = s.lengthOfLIS(data);
        cout << res << endl;
    }
}