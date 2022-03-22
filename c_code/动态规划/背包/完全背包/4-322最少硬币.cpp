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

// 1、数组含义：dp[i]表示构成i的最小硬币数
// 2、递推公式：dp[i] = min(dp[i], dp[i-coins] + 1)
// 3、初始化：dp[0]表示构成和为0的最小硬币数，dp[0] = 0
// 因为是求最小值，所以其他值不能初始化为0，应该初始化为INT_MAX
// 这样就可以在比较过程中自动识别不可行的方法，而不用逐个判断
// 4、遍历顺序：完全背包，所以背包容量递增
// 不涉及排列组合，所以背包和物品的遍历顺序不影响结果
class Solution2
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // INT_MAX作为标志位，表示构成和为j的方法不存在
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        display(dp);
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                // dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                // dp[j - coins[i]] + 1可能溢出，变成负值，那自然是最小值
                // 如n=3 [2]
                // 0 INT_MAX INT_MAX INT_MAX
                // 0 INT_MAX min(INT_MAX,0+1) min(INT_MAX,INT_MAX+1)
                // 如果溢出为负值，表示仍然不可行

                //没有溢出，j-coins[i]!=INT_MAX，即j-coins[i]可行
                if (dp[j - coins[i]] != INT_MAX) // 保证不溢出
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
                // 如果溢出，j-coins[i]也不可行，所以dp[j]保留原值
            }
            display(dp);
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
    void display(const vector<int> &data)
    {
        // for (auto i : data)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n---------------------\n";
    }
};

// 用回溯来解决
// 需要遍历整棵树，找到可行解path，然后更新最短路径(初始化为INT_MAX)
// 横向遍历：硬币没有重复值，不需要剪枝
// 纵向遍历：硬币可以重复（可以找自己），不要求顺序（不能回头）
class Solution3
{
private:
    vector<int> path;
    int shortest_length;

public:
    int coinChange(vector<int> &coins, int amount)
    {
        path.clear(), shortest_length = INT_MAX;
        backtracking(coins, amount, 0, 0);
        return shortest_length == INT_MAX ? -1 : shortest_length;
    }
    // 遍历整棵树，没有返回值
    // 不能回头，可以找自己
    void backtracking(const vector<int> &coins, const int &amount, int left, int sum)
    {
        if (sum == amount)
        {
            shortest_length = min(shortest_length, int(path.size()));
            return;
        }
        else if (sum > amount)
        {
            return;
        }

        for (int i = left; i < coins.size(); i++)
        {
            // 当前结点
            path.push_back(coins[i]);
            sum += coins[i];
            // 递归
            backtracking(coins, amount, i, sum);
            // 回溯
            sum -= coins[i];
            path.pop_back();
        }
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

    {
        Solution2 s;
        vector<int> data{1, 2, 5};
        int n = 11;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }

    {
        Solution2 s;
        vector<int> data{2};
        int n = 3;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }

    {
        Solution2 s;
        vector<int> data{1};
        int n = 0;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }

    {
        Solution3 s;
        vector<int> data{1, 2, 5};
        int n = 11;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }

    {
        Solution3 s;
        vector<int> data{2};
        int n = 3;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }

    {
        Solution3 s;
        vector<int> data{1};
        int n = 0;
        int res = s.coinChange(data, n);
        cout << res << endl;
    }
}