#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1、数组含义：dp[i][j]表示从[0][0]到[i][j]的方法数
// 2、递推公式：dp[i][j]=dp[i-1][j]（向右移动）+dp[i][j-1]（向上移动）
// 3、初始化：dp[0][i]=1，dp[j][0]=1
// 4、遍历顺序：横、纵
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // m*n的二维vector
        // 初始化为1，主要是将dp[0][i]和dp[j][0]置为1
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
}