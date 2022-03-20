#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// stones[i]为第i块石头的重量
// 选两个石头，设x<=y（均为两块石头的重量）
// 如果x==y，两块石头都被销毁
// 否则x被销毁，y的新重量为y-x
// 要求最后剩下的石头重量最小（没有石头时，返回0）

// 第一步转换（最关键的一步）：为了让“剩下石头的重量最小”，实际上是将石头分成两堆，保证重量尽可能相等
// 也就是求背包重量为sum/2时，能够放下的最大价值（stones=weights=values）
// 返回abs(sum-dp.back().back()*2)
// 1、数组含义：dp[i][j]表示考虑0-i个石头，背包为j时的最大价值（不会超过j）
// 2、递推公式：dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i]]+values[i]) / dp[i-1][j]
// 3、初始化：dp[i][0]=0,dp[0][j]=values[0] when j>=weights[0]
// 4、遍历顺序：从大到小，从大到小

// 和413极为相似，主要步骤相同，weights=values，背包重量=sum(weights)/2
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = get_sum(stones);
        int n = sum / 2;
        // stones.size()*int(sum/2)
        vector<vector<int>> dp(stones.size(), vector<int>(n + 1, 0)); // dp[i][0]=0
        for (int weight = stones[0]; weight <= n; weight++)
        {
            dp[0][weight] = stones[0];
        }

        for (int item = 1; item < stones.size(); item++)
        {
            for (int weight = 1; weight <= n; weight++)
            {
                if (weight >= stones[item])
                {
                    dp[item][weight] = max(dp[item - 1][weight],
                                           dp[item - 1][weight - stones[item]] + stones[item]);
                }
                else
                {
                    dp[item][weight] = dp[item - 1][weight];
                }
            }
        }
        return abs(dp[stones.size() - 1][n] * 2 - sum);
    }

    int get_sum(const vector<int> &stones)
    {
        int sum = 0;
        for (auto stone : stones)
        {
            sum += stone;
        }
        return sum;
    }
};

int main()
{
    Solution s;
}
