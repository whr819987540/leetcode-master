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

// 上面的二维数组+遍历二维数组的子数组超时
// 压缩为一维数组，然后对一维数组的子数组遍历，找最大值
// 1、数组含义：dp[j]表示第二个字符串以j结尾时最长公共子序列的长度
// 2、递推公式：if text1[i]==text2[j],dp[j]=max(dp[n])+1,n<j
// 否则维持原值（必须维持原值，因为dp数组需要记录历史结果）
// 为什么能这样？因为虽然dp数组定义为以j结尾，但是压缩后，可以不以j结尾
// 因为dp数组还用来记录历史结果
// 3、初始化：0
// 4、遍历顺序：递增，递增
class Solution2
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int max_length = 0;
        vector<int> dp(text2.size(), 0);

        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[j] = get_max(dp, j) + 1;
                    max_length = max(max_length, dp[j]);
                }
            }
        }
        return max_length;
    }

private:
    int get_max(const vector<int> &dp, int j)
    {
        int res = 0;
        for (int i = 0; i < j; i++)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    {
        Solution s;
        string text1 = "abcde", text2 = "aecd";
        cout << s.longestCommonSubsequence(text1, text2) << endl;
    }

    {
        Solution s;
        string text1 = "abc", text2 = "abc";
        cout << s.longestCommonSubsequence(text1, text2) << endl;
    }

    {
        Solution s;
        string text1 = "abcba", text2 = "abcbcba";
        cout << s.longestCommonSubsequence(text1, text2) << endl;
    }

    {
        Solution2 s;
        string text1 = "abcde", text2 = "aecd";
        cout << s.longestCommonSubsequence(text1, text2) << endl;
    }

    {
        Solution2 s;
        string text1 = "abc", text2 = "abc";
        cout << s.longestCommonSubsequence(text1, text2) << endl;
    }

    {
        Solution2 s;
        string text1 = "abcba", text2 = "abcbcba";
        cout << s.longestCommonSubsequence(text1, text2) << endl;
    }
}