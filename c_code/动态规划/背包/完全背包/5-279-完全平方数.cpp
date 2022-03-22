#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

// 给定n，返回和为n的完全平方数的最小个数
// 可以重复选同一个完全平方数
// 11 = 9 + 1 + 1
// 12 = 4 + 4 + 4

// i为背包容量，所有小于n的完全平方数为物品
// 尝试将这些物品放入背包中，使得物品和为i且物品数最小
// 1、数组含义：dp[i]表示和为i时的最小个数
// 2、递推公式：dp[i] = min(dp[i],dp[i-square_num]+1)
// 3、初始化：dp[0]=0，其他值为INT_MAX
// 4、遍历顺序：一个值可以被重复选取，完全背包，背包容量递增
// 不考虑顺序，背包容量和物品的遍历顺序不影响结果
// 先遍历物品，后遍历背包容量
class Solution
{
public:
    int numSquares(int n)
    {
        // 形成物品
        vector<int> squares = generate_items(n);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < squares.size(); i++)
        {
            for (int j = squares[i]; j <= n; j++)
            {
                if (dp[j - squares[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - squares[i]] + 1);
                }
            }
        }
        return dp[n];
    }
    vector<int> generate_items(int n)
    {
        vector<int> res;
        for (int i = 1; i <= sqrt(n); i++)
        {
            res.push_back(i * i);
        }
        return res;
    }
};

int main()
{
    {
        Solution s;
        int n = 11;
        int res = s.numSquares(n);
        printf("n=%d,res=%d\n", n, res);
    }
    {
        Solution s;
        int n = 13;
        int res = s.numSquares(n);
        printf("n=%d,res=%d\n", n, res);
    }
}