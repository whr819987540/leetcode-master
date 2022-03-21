#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定coins数组，里面的元素表示硬币的面额
// 给定面额和target
// 要求硬币的面额之和为target
// 如果可以构成，返回最少的硬币数，否则返回-1
// 每种硬币的数量无限

// 完全背包

// 1、数组含义：dp[i]表示构成i的最小硬币数
// 2、递推公式：dp[i] = min(dp[i], dp[i-coins] + 1)
// 3、初始化：全0
// 4、遍历顺序：完全背包，所以背包容量递增
// 不涉及排列组合，所以背包和物品的遍历顺序不影响结果
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        vector<int> dp(amount + 1, 0);
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                // 背包容量和硬币面值相同时，只放当前硬币是最少方法
                if (j == coins[i])
                {
                    dp[j] = 1;
                }
                // 放当前硬币存在可行解
                else if (dp[j - coins[i]] != 0)
                {
                    if (dp[j] == 0)
                    {
                        dp[j] = dp[j - coins[i]] + 1;
                    }
                    else
                    {
                        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                    }
                }
                // // 放当前硬币不存在可行解
                // else if (dp[j - coins[i]] == 0)
                // {
                //     dp[j] = dp[j];
                // }
            }
            // display(dp);
        }
        return dp[amount] != 0 ? dp[amount] : -1;
    }
    void display(const vector<int> &data)
    {
        for (auto i : data)
        {
            cout << i << " ";
        }
        cout << "---------------------\n";
    }
};

int main()
{
    {
        Solution s;
        vector<int> data{1, 2, 5};
        int n = 11;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }

    {
        Solution s;
        vector<int> data{2};
        int n = 3;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }

    {
        Solution s;
        vector<int> data{1};
        int n = 0;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }
}