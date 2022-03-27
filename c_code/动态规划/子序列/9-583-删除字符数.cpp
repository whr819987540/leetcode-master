#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定两个字符串word1，word2，返回使得word1==word2的最小步数
// 每一步，都可以删除两个字符串中的任意一个字符

// 1、数组含义：dp[i][j]表示考虑word1的前i个字符、word2的前j个字符，所需要的最小步数
// 2、递推公式：if word1[i]==word2[j], dp[i][j]=dp[i-1][j-1]，相同，不用删
// else dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1],2)
// 删除word1的最后一个字符，删除word2最后一个字符，删除word1、word2的最后一个字符
// 3、初始化：注意到可能溢出，所以给行列都增加一个单位
// dp[0][j]=j,dp[i][0]=i
// 4、遍历顺序：递增，递增
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 1; j <= word2.size(); j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 2);
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
        string word1 = "leetcode", word2 = "etco";
        cout << s.minDistance(word1, word2) << endl;
    }
}