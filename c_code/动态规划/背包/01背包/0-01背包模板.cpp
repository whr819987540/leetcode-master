#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1、数组含义：dp[i][j]表示考虑0-i号物品、背包最大重量为j时的最大价值
// 2、递推公式：
// if j>=weight[i] then dp[i][j]=max(dp[i-1][j]不放物品i,value[i]+dp[i-1][j-weight[i]]放物品i)
// else dp[i][j]=dp[i-1][j]，放不下i，只能考虑前i-1个物品
// 3、初始化：dp[i][0]=0，背包重量为0；dp[0][i]=value[0] when i>=weight[0]，当背包重量>=0的重量时，必然放物品0
// 4、遍历顺序：递增，递增
class Solution
{
public:
    int bag(vector<int> &values, vector<int> &weights, int n)
    {
        // 这里注意，应该是values.size()*(n+1)维矩阵
        // 因为values对应物品，本身就从0开始
        // 而背包重量为n，从0开始要+1
        vector<vector<int>> dp(values.size(), vector<int>(n + 1, 0));
        // 0号物品
        for (int weight = weights[0]; weight <= n; weight++)
        {
            dp[0][weight] = values[0];
        }
        // 物品从1开始，因为0已经被初始化了
        for (int item = 1; item < values.size(); item++)
        {
            // 重量从1开始，0已被初始化
            for (int weight = 1; weight <= n; weight++)
            {
                if (weight >= weights[item])
                {
                    dp[item][weight] = max(dp[item - 1][weight],
                                           dp[item - 1][weight - weights[item]] + values[item]);
                }
                else
                {
                    dp[item][weight] = dp[item - 1][weight];
                }
            }
        }
        return dp[values.size() - 1][n];
    }
};

// 1、数组含义：dp[j]表示背包容量为i时，背包的最大价值。
// - 此时怎么知道考虑到哪个物品呢？外层循环遍历物品
// 2、递推公式：dp[j] = max(dp[j] , dp[j-weight] + value)
// 3、初始化：初始化还没有开始遍历物品，所以不考虑价值，价值都为0
// 4、遍历顺序：物品递增，重量递减
class Solution2
{
public:
    int bag(vector<int> &values, vector<int> &weights, int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < values.size(); i++)
        {
            // 不需要j>=0
            // 因为j<weights[i]时，内层循环会保留dp[j]的值
            // 相当于拷贝了一次数组
            for (int j = n; j >= weights[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
        return dp[n];
    }
};

int main()
{
    {
        Solution s;
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagweight = 4;
        int res = s.bag(value, weight, bagweight);
        cout << res << endl;
    }

    {
        Solution2 s;
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagweight = 4;
        int res = s.bag(value, weight, bagweight);
        cout << res << endl;
    }
}