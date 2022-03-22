#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// nums表示第i个屋子的价值，这些屋子围成一个环
// 要求不偷盗相邻的屋子
// 返回偷盗的最大总价值

// 1、数组含义：dp[i]表示偷到第i家时获得的最大价值
// 2、递推公式：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
// 同时用两个标志指示是否选择了第0家
// 3、初始化：dp[0]=nums[0],first=true，表示选择了第0家
// dp[1] = max(nums[0], nums[1]),second=nums[0]>nums[1]
// 4、遍历顺序：递增

// [2,2,4,3,2,5]无法解决这个bug
// 最后dp[5]=11,second=true,dp[4]=8
// 输出为9
// 而选择2,3,5可以到10
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        bool first, second;
        vector<int> dp(nums.size());
        dp[0] = nums[0], first = true;
        dp[1] = max(nums[0], nums[1]), second = nums[0] > nums[1];

        for (int i = 2; i < nums.size(); i++)
        {
            if (dp[i - 2] + nums[i] > dp[i - 1])
            {
                dp[i] = dp[i - 2] + nums[i];
                swap(first, second);
            }
            else
            {
                dp[i] = dp[i - 1];
                first = second;
            }
        }
        if (second) // 偷最后一家时，也偷了第一家
        {
            return max(dp[nums.size() - 2], dp[nums.size() - 1] - min(nums[0], nums[nums.size() - 1]));
        }
        else // 偷最后一家时，没有头第一家
        {
            return dp[nums.size() - 1];
        }
    }
};

int main()
{
    {
        Solution s;
        vector<int> data = {2, 3, 2};
        cout << s.rob(data) << endl;
    }
}