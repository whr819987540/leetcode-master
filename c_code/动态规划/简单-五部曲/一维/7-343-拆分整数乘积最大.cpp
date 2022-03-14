#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个正整数n
// 将其拆分为至少两个正整数的和，使得这些正整数的乘积最大
// 以7为例，7的最大值应该是1/6 2/5 3/4 拆分最大值的乘积的最大值

// 1、数组含义：dp[i]表示i拆分后的乘积最大值
// 2、递推公式：dp[i] = max(dp[1]*dp[i-1],dp[2]*dp[i-2],dp[3]*dp[i-3],dp[n]*dp[i-n]) n<=i/2
// 可以用一棵树来理解,dp[i]=dp[k]*dp[i-k]
// 继续拆分后，k和i-k拆分项的和等于i，相当于是继续进行了拆分
// 3、初始化：dp[1]=1(注意1的含义),dp[2]=1
// 4、遍历顺序：从左往右

// 有一个bug，在计算dp[i]时，dp[i]=dp[n]+dp[i-n],n<=i/2
// 如果dp[n]<n，应该取dp[n]=n，可以理解为不对n进行拆分，dp[i-n]也是如此
// 但是在递推公式中不能引入0，因为至少需要对i进行一次拆分
// 比如dp[1]=1,dp[2]=1,dp[3]=max(dp[1]+dp[2])=1，实际上1、2可以不拆分
// dp[3]=2
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                // 可以理解为不进行拆分
                // 可以对原数组值进行修改，因为这些中间数据不是结果
                dp[j] = max(dp[j], j), dp[i - j] = max(dp[i - j], i - j);
                dp[i] = max(dp[i], dp[j] * dp[i - j]);

                // 也可以写成
                // 不对原数组进行修改，更加符合dp数组的含义
                // dp[i] = max(dp[i], max(dp[j], j) * max(dp[i - j], i - j));
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution s;
    int res = s.integerBreak(10);
    cout << res << endl;
}
