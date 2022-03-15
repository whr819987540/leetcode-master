#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定n，n个结点，结点值为1-n
// 要求返回所有不同的二叉搜索树的个数

// 1、数组含义：dp[i]表示i个结点时二叉搜索树的最大个数
// 2、递推公式：dp[i]=∑(dp[j-1]*dp[i-j]),1<=i<=n,1<=j<=i
// 3、初始化：dp[0]=1，空树
// 4、遍历顺序：从小到大
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; //空树
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }
        return dp.back();
    }
};

// 根据描述，显然可以用递归，但是递归的空间复杂度将非常大
class Solution2
{
public:
    int numTrees(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        int sum = 0;
        for (int root = 1; root <= n; root++)
        {
            sum = sum + (numTrees(root - 1) * numTrees(n - root));
        }
        return sum;
    }
};
int main()
{
    Solution s1;
    Solution2 s2;
    int n = 10;
    cout << s1.numTrees(n) << "    " << s2.numTrees(n) << endl;
}
