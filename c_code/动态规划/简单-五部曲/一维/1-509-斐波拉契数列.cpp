#include <iostream>
#include <vector>
using namespace std;

// 动态规划解决斐波拉契数列
// 1、数组含义：dp[i]表示第i个斐波拉契数
// 2、递推公式：dp[i]=dp[i-1]+dp[i-2]
// 3、初始化：dp[0]=0,dp[1]=1
// 4、遍历顺序，从左往右
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int *dp = new int[n + 1]();
        dp[0] = 0, dp[1] = 1;
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
    int res = s.fib(5);
    cout << res << endl;
}