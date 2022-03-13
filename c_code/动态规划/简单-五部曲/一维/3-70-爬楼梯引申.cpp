#include <iostream>
#include <vector>
using namespace std;

// 原题是每次最多只能上两层
// 可以引申到上m层

// 1、数组含义：dp[i]表示上到第i层的方法数
// 2、递推公式：dp[i]=dp[i-1]+dp[i-2]+dp[i-n],i-n>=0&&1<=n<=m
// 3、初始化：dp[0]=1，后面的值在初始化时，与m的取值有关，所以只初始化一个值，后续的初始化放到循环中进行
// 4、遍历顺序：从左往右
class Solution
{
public:
    int climbStairs(int n, int m)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int n = 1; n <= m && i - n >= 0; n++)
            {
                dp[i] += dp[i - n];
            }
            cout << "i=" << i << " dp[i]=" << dp[i] << endl;
        }
        return dp[n];
    }
};

void test(int n, int m)
{
    Solution s;
    int res = s.climbStairs(n, m);
    cout << res << endl;
    cout << "----------\n";
}
int main()
{
    test(5, 1);
    test(5, 2);
    test(5, 3);
}