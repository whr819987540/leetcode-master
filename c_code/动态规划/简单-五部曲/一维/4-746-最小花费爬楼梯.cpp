#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1、数组含义：dp[i]表示到第i层的最小花费且已支付该层费用
// 2、递推公式：dp[i]=min(dp[i-1],dp[i-2])+cost[i]
// 3、初始化：dp[0]=cost[0],dp[1]=cost[1]，因为可以从0或1出发
// 4、遍历顺序：从左往右
// 最后取dp[dp.size()-1]（最后走一步）和dp[dp.size()-2]（最后走两步）的最小值
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};

int main()
{
    Solution s;
}