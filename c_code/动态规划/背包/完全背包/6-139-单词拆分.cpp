#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给一个字符串s和字符串数组wordDict
// 判断s是否能由wordDict中的字符串连接而成
// wordDict中的字符串可以被重复使用
// s = "leetcode", wordDict = ["leet","code"]
// true
// s = "applepenapple", wordDict = ["apple","pen"]
// true
// s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// false

// 1、数组含义：dp[i]表示是否可以构成s的前i个字符
// 2、递推公式：dp[i] = dp[i-len]
// 3、初始化：dp[0]=1,其余为0
// 4、遍历顺序：因为物品可以被重复使用，所以背包容量递增
// 先遍历背包容量再遍历物品
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        s = " " + s; // 补齐s[0]，方便编程
        for (int j = 1; j < dp.size(); j++)
        {
            for (int i = 0; i < wordDict.size(); i++)
            {
                // 从j开始往前扫描s，扫描wordDict[i].size()个字符，看是否能匹配
                // 如果匹配，则前j个字符能否被wordDict组成由dp[j-wordDict[i].size()]决定
                if (suit(s, wordDict[i], j))
                {
                    dp[j] = dp[j - wordDict[i].size()];
                }
            }
        }
        return dp.back();
    }
    bool suit(const string &s, const string &tmp, int j)
    {
        if (tmp.size() > j)
        {
            return false;
        }
        // s的下标从j开始，tmp的下标i从tmp.size()-1开始
        int i = tmp.size() - 1;
        for (; i >= 0; i--, j--)
        {
            if (tmp[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    {
        Solution s;
        string ss = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        bool res = s.wordBreak(ss, wordDict);
        cout << res << endl;
    }

    {
        Solution s;
        string ss = "applepenapple";
        vector<string> wordDict = {"apple", "pen"};
        bool res = s.wordBreak(ss, wordDict);
        cout << res << endl;
    }

    {
        Solution s;
        string ss = "catsandog";
        vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
        bool res = s.wordBreak(ss, wordDict);
        cout << res << endl;
    }
}