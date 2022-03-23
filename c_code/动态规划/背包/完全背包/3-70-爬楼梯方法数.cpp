#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// n阶楼梯，每次可以爬1或2层
// 问有多少种爬法
// 爬法，显然是排列问题，因为21和12是两种不同的爬法

// 考虑原题，dp-斐波拉契数列
// 1、数组含义：dp[i]表示爬到第i层的方法数
// 2、递推公式：dp[i] = dp[i-1] + dp[i-2]
// 3、初始化：dp[0] = 1, dp[1] = 1
// 4、遍历顺序：楼梯递增
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// 引申
// 楼梯数n，每次可以走1/2/3/m步
// 还是问爬到顶的方法数
// n为背包容量，m为物品
// 物品显然可重复，所以是完全背包。背包容量递增
// 因为12和21不同，排列，所以先遍历背包容量，再遍历物品
// 否则就等价于提前规定好物品的顺序了
// 1、数组含义：dp[i]表示走到第i层的方法数
// 2、递推公式：dp[i] = dp[i-1] + dp[i-2] + dp[i-m]
// 3、初始化：dp[0] = 1
// 4、遍历顺序：先背包容量（递增），再物品
class Solution2
{
public:
    int climbStairs(int n, int m)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                if (j >= i)
                {
                    dp[j] = dp[j] + dp[j - i];
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    {
        Solution s;
        int res1 = s.climbStairs(10);
        cout << "res1:" << res1 << endl;
        Solution2 s2;
        int res2 = s2.climbStairs(10, 2);
        cout << "res2:" << res2 << endl;
    }
}