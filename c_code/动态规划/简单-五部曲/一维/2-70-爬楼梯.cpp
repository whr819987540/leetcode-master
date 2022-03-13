#include <iostream>
#include <vector>
using namespace std;

// 1、数组含义：dp[i]表示爬到第i层的方法数
// 2、递推公式：dp[i]=dp[i-1]+dp[i-2]
// 爬到i之前，如果最后走一层，那么之前在i-1；如果走两层，那么之前在i-2
// 3、初始化：dp[1]=1,dp[2]=2
// 4、遍历顺序：从前往后
class Solution
{
    public:
    int climbStairs(int n)
    {
        if (n < 3)
        {
            return n;
        }
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int res = s.climbStairs(5);
    cout << res << endl;
}