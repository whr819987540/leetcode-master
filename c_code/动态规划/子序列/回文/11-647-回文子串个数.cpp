#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定一个字符串s，返回s的子串中是回文串的子串的个数
// 回文串：正序、逆序相同的字符串
// 单个字符也是回文串，空串不是回文串
// 子串：s的某个连续序列

// 1、数组含义：dp[i][j]表示字符串s以i开头、以j结尾时是回文串的子串的个数
// 2、递推公式：要求i<j
// if s[i]==s[j],dp[i][j]=dp[i+1][j-1]+dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]
//                       =dp[i+1][j]+dp[i][j-1]
// else, dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]
// 最后减去dpdp[i+1][j-1]是因为dp[i+1][j]和dp[i][j-1]重复考虑了i+1到j-1这个字符串
// 3、初始化：i==j,dp[i][j]=1，其余为0
// 4、遍历顺序：递减，递增
// 最后应该返回dp[0][s.size()-1]，因为最后需要考虑整个字符串
class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
        }

        for (int i = s.size() - 1; i >= 0; i--)
        {
            // 不用j>=i，因为相等的情况已经被初始化了
            for (int j = i + 1; j < s.size(); j++)
            {
                printf("i=%d,j=%d,s[i]=%c,s[j]=%c\n", i, j, s[i], s[j]);
                if (s[i] == s[j])
                {
                    if (i == j - 1)
                    {
                        dp[i][j] = 3;
                        cout << 1 << endl;
                    }
                    else
                    {
                        // dp[i][j] = dp[i + 1][j - 1] + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                        dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
                        cout << 2 << endl;
                    }
                }
                else
                {
                    // 重复考虑了i+1到j-1这个字符串
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                    cout << 3 << endl;
                }
                printf("dp[i][j]=%d\n", dp[i][j]);
            }
        }
        display_matrix(dp);
        return dp[0].back();
    }
    void display_matrix(const vector<vector<int>> &dp)
    {
        for (auto inner : dp)
        {
            for (auto outer : inner)
            {
                cout << outer << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    {
        Solution s;
        string data = "abc";
        cout << s.countSubstrings(data) << endl;
    }

    {
        Solution s;
        string data = "aaa";
        cout << s.countSubstrings(data) << endl;
    }
}