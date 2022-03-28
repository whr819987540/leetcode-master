#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定字符串s，返回最长回文子序列的长度
// 回文：正序和逆序相同
// 子序列：不要求连续
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

// 1、数组含义：dp[i][j]表示s以i开头、j结尾时最长回文子序列的长度
// 2、递推公式：
// j>=i
// if s[i]==s[j]
//      if i==j,dp[i][j]=1
//      else if i==j-1,dp[i][j]=2
//      else dp[i][j]=dp[i+1][j-1]+2
// else dp[i][j]=max(dp[i+1][j],dp[i][j-1])
// 3、初始化：0
// 4、遍历顺序：递减，递增
// 最后返回dp[0][s.size()-1]

// 647不能直接将dp定义为结果，而本题可以，因为本题的递推公式是max
// 不需要考虑是否重复
// 而647是个数，需要考虑重复
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j)
                    {
                        dp[i][j] = 1;
                    }
                    else if (j == i + 1)
                    {
                        dp[i][j] = 2;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else
                {
                    // i、j不相等，只能删除一个
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        display(dp);
        return dp[0][s.size() - 1];
    }

    void display(const vector<vector<int>> &dp)
    {
        for (auto outer : dp)
        {
            for (auto inner : outer)
            {
                cout << inner << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    {
        Solution s;
        string data = "bbbab";
        cout << s.longestPalindromeSubseq(data) << endl;
    }

    {
        Solution s;
        string data = "cbbd";
        cout << s.longestPalindromeSubseq(data) << endl;
    }
}