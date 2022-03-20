#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 一维数组
// 1、数组含义：dp[i]表示背包容量为i时物品的最大价值
// 2、递推公式：dp[i] = max(dp[i], dp[i-weight] + value)
// 3、初始化：0
// 4、遍历顺序：物品递增，容量递增（小容量背包考虑当前物品，大容量背包也考虑当前物品，才是完全背包问题）
class Solution
{
public:
    // 物品重量，物品价值，背包最大重量
    int completePacket(vector<int> &weights, vector<int> &values, int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < weights.size(); i++)
        {
            for (int j = weights[i]; j <= n; j++)
            {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    int n = 4;
    int res = s.completePacket(weights, values, n);
    cout << res << endl;
}