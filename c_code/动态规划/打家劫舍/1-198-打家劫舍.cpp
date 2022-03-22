#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// nums表示第i个屋子的价值
// 要求不偷盗相邻的屋子
// 返回偷盗的最大总价值

// 1、数组含义：dp[i]表示偷盗到第i个屋子获得的最大总价值
// 2、递推公式：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
// 3、初始化：dp[0]=nums[0],dp[1]=max(nums[0],nums[1])
// 4、遍历顺序：递增
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }
};

int main()
{
    {
        Solution s;
        vector<int> data = {1, 2, 3, 1};
        cout << s.rob(data) << endl;
    }

    {
        Solution s;
        vector<int> data = {1};
        cout << s.rob(data) << endl;
    }
}