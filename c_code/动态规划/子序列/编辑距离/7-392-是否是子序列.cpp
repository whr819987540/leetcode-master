#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定字符串s、t，判断s是不是t的子序列
// 子序列是在不改变原序列元素相对位置的基础上，不删除或删除一些元素，得到的新序列

// 1、数组含义：dp[i][j]表示只考虑s的i个字符和t的j个字符时，是不是子序列
// 2、递推公式：if s[i]==t[j], dp[i][j]=dp[i-1][j-1]
// else dp[i][j]=dp[i][j-1],这里只能是dp[i][j-1]子串不能少，只能缩减原串
// 3、初始化：为了防止越界，行列都需要多加一个单位
// dp[i][0]，子串不为空，原串为空，false,i!=0
// dp[0][j]，子串为空，原串空或不空，true
// 4、遍历顺序：递增，递增
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(t.size() + 1, true));
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i][0] = false;
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};

int main()
{
    {
        Solution s;
        string s1 = "abc", s2 = "ahbgdc";
        cout << s.isSubsequence(s1, s2) << endl;
    }
    {
        Solution s;
        string s1 = "axc", s2 = "ahbgdc";
        cout << s.isSubsequence(s1, s2) << endl;
    }
}