#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// stones[i]为第i块石头的重量
// 选两个石头，设x<=y（均为两块石头的重量）
// 如果x==y，两块石头都被销毁
// 否则x被销毁，y的新重量为y-x
// 要求最后剩下的石头重量最小（没有石头时，返回0）

// 第一步转换：为了让“剩下石头的重量最小”，实际上是将石头分成两堆，保证重量尽可能相等
// 也就是求背包重量为sum/2时，能够放下的最大价值（stones=weights=values）
// 返回abs(sum-dp.back().back()*2)
// 1、数组含义：dp[i][j]表示考虑0-i个石头，背包为j时的最大价值（不会超过j）
// 2、递推公式：dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i]]+values[i]) / dp[i-1][j]
// 3、初始化：dp[i][0]=0,dp[0][j]=values[0] when j>=weights[0]
// 4、遍历顺序：从大到小，从大到小
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        
    }
};

int main()
{
    Solution s;
}
