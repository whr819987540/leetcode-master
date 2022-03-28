#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定字符串word1、word2，通过以下三种方式将word1转化为word2
// 插入，删除，替换
// 返回最少的操作数
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// 1、数组含义：dp[i][j]表示考虑word1的前i个字符，word2的前j个字符所需要的最少操作数
// 2、递推公式：if word1[i]==word2[j], dp[i][j]=dp[i-1][j-1],相同则不需要操作
// else
// 替换，替换之后肯定相同：dp[i][j]=dp[i-1][j-1]+1
// 删除，只能删除word1中的最后一个字符：dp[i][j]=dp[i-1][j]+1
// 增添，只能对word1进行增添：dp[i][j]=dp[i][j-1]+1
// 最后取最小值
// 3、初始化：dp[0][j]=j，空串变j，增添j次
// dp[i][0]=i，i变空串，删除i次
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
                // 相同，最后一个字符不需要执行操作
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 替换，替换之后肯定相同：dp[i][j]=dp[i-1][j-1]+1
                    // 删除，只能删除word1中的最后一个字符：dp[i][j]=dp[i-1][j]+1
                    // 增添，只能对word1进行增添：dp[i][j]=dp[i][j-1]+1
                    // 最后取最小值

                    // 替换
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    // 删除
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    // 增添
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
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
        string word1 = "horse", word2 = "ros";
        cout << s.minDistance(word1, word2) << endl;
    }

    {
        Solution s;
        string word1 = "intention", word2 = "execution";
        cout << s.minDistance(word1, word2) << endl;
    }
}