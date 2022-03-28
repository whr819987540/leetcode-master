#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定字符串s、t，返回s的子序列中等于t的子序列数目
// s = "babgbag", t = "bag"
// Output: 5

// 1、数组含义：dp[i][j]表示考虑s的前i个字符，t的前j个字符的结果
// 2、递推公式：if s[i]==t[j],dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
// 前者表示t的最后一个字符来自s的最后一个字符，后者表示j的最后一个字符不来自s的最后一个字符
// else dp[i][j]=dp[i-1][j]，二者最后一个字符不同，只能缩减s，不能缩减t，因为t是子序列
// 3、初始化：注意到可能越界，所以行列补一个单位
// dp[i][0]=1,i>=0
// dp[0][j]=0,j>0
// 其余为0
// 4、遍历顺序：递增，递增
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<vector<unsigned long>> dp(s.size() + 1, vector<unsigned long>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        display_matrix(dp);
        return dp[s.size()][t.size()];
    }

    void display_matrix(const vector<vector<unsigned long>> &dp)
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
        string s1 = "babgbag", s2 = "bag";
        cout << s.numDistinct(s1, s2) << endl;
    }
}