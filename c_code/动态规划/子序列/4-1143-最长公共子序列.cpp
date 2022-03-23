#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定两个字符串，返回它们最长公共子序列的长度
// 子序列可以不连续
// text1 = "abcde", text2 = "ace"
// Output: 3

// 1、数组含义：dp[i][j]表示两个字符串分别以i、j结尾时最长公共子序列的长度
// 2、递推公式：if text1[i]==text2[j],dp[i][j]=max(dp[m][n])+1,m<i,n<j
// 否则维持0值
// 3、初始化：0
// 4、遍历顺序：递增，递增
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int max_length = 0;
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = get_max(dp, i, j) + 1;
                    max_length = max(dp[i][j], max_length);
                }
            }
        }
        return max_length;
    }

private:
    int get_max(const vector<vector<int>> &dp, int i, int j)
    {
        int res = 0;
        for (int m = 0; m < i; m++)
        {
            for (int n = 0; n < j; n++)
            {
                res = max(dp[m][n], res);
            }
        }
        return res;
    }
};

int main()
{
    {
        Solution s;
        string text1 = "abcde", text2 = "aecd";
        cout << s.longestCommonSubsequence(text1, text2);
    }
}