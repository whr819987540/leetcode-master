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


int main()
{
    Solution s;
}