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
        vector<vector<int>> dp(values.size() + 1, vector<int>(n + 1, 0));
        // 0号物品
        for (int weight = weights[0]; weight <= n; weight++)
        {
            dp[0][weight] = values[0];
        }

        for (int item = 1; item <= values.size(); item++)
        {
            for (int weight = 0; weight <= n; weight++)
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
        return dp[values.size()][n];
    }
};

int main()
{
    Solution s;
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    int res = s.bag(value, weight, bagweight);
    cout << res << endl;
}