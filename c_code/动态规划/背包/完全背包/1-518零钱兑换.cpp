#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定一个数组coins，里面的元素表示不同硬币的面额
// 给定amount，要求选择一些硬币，使得硬币的面额之和==amount
// 硬币数无限
// 最后返回组合数
// 注意这里要求的是组合数，也就是说不考虑选择顺序，比如5=1+2+2和2+1+2是一种组合（方法）

// 1、数组含义：dp[i]表示用这些硬币构成面额为i的方法数
// 2、递推公式：dp[i] = dp[i] + dp[i - coin]
// 3、初始化：dp[0]=1，不考虑所有硬币时，使面额为0的方法有1种，使面额为其他值的方法为0种
// 4、遍历顺序：首先是完全背包问题，所以背包容量递增
// 然后是组合问题，所以先遍历物品，再遍历背包容量
// 如果是排列问题，先遍历背包容量，后遍历物品
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution s;
}