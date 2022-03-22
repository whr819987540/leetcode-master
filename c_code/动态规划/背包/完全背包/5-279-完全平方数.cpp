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

// 1、数组含义：dp[i]表示和为i时的最小个数
// 2、递推公式：dp[i] = min(dp[i],dp[i-square_num]+1)
// 3、初始化：dp[0]=0，其他值为INT_MAX
// 4、遍历顺序：一个值可以被重复选取，完全背包，背包容量递增
// 不考虑顺序，背包容量和物品的遍历顺序不影响结果
// 先遍历背包容量，后遍历物品
class Solution2
{
public:
    int numSquares(int n)
    {
        // 物品
        vector<int> squares = generate_items(n);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int j = 1; j <= n; j++)
        {
            for (int i = 0; i < squares.size(); i++)
            {
                if (j >= squares[i] && dp[j - squares[i]] != INT_MAX)
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

// 回溯
// 横向遍历：没有重复值，不需要处理
// 纵向遍历：可以重复（找自己），不可以回头（不考虑顺序）
// 遍历整棵树，所以没有返回值
class Solution3
{
public:
    int pwd_path_length; // 当前路径长度
    int shortest_path;   // 最短路径长度
    // 没有必要记录路径，因为只是求一个长度
    int numSquares(int n)
    {
        // 小于等于n的完全平方数
        vector<int> squares = generate_items(n);

        pwd_path_length = 0;
        shortest_path = INT_MAX;

        backtracking(squares, n, 0, 0);
        return shortest_path;
    }

    void backtracking(const vector<int> &squares, const int &target, int sum, int left)
    {
        if (sum == target)
        {
            shortest_path = min(shortest_path, pwd_path_length);
            return;
        }
        else if (sum > target)
        {
            return;
        }

        for (int i = left; i < squares.size(); i++)
        {
            // 当前结点
            sum += squares[i];
            pwd_path_length++;
            // 递归
            backtracking(squares, target, sum, i);
            // 回溯
            pwd_path_length--;
            sum -= squares[i];
        }
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
    {
        Solution s;
        int n = 203;
        int res = s.numSquares(n);
        printf("n=%d,res=%d\n", n, res);
    }
    {
        Solution2 s;
        int n = 11;
        int res = s.numSquares(n);
        printf("n=%d,res=%d\n", n, res);
    }
    {
        Solution2 s;
        int n = 13;
        int res = s.numSquares(n);
        printf("n=%d,res=%d\n", n, res);
    }

    {
        Solution3 s;
        int n = 11;
        int res = s.numSquares(n);
        printf("n=%d,res=%d\n", n, res);
    }
    {
        Solution3 s;
        int n = 13;
        int res = s.numSquares(n);
        printf("n=%d,res=%d\n", n, res);
    }
}