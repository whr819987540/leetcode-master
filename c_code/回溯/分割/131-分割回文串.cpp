#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 回文串是轴对称的字符串，比如aaa，aba，a
// 要求从一个字符串中取子串，且子串为回文串

// 对题意理解错误，要求对这个字符串进行连续的分割
// 使分割的字符串均为回文串
// 而不是简单的找子串并判断

class Solution
{
public:
    vector<vector<string>> res;
    string path;
    vector<vector<string>> partition(string s)
    {
    }

    // 需要字符串s，左边界left
    void func(const string &s, int left)
    {
        if (isPalindrome(path))
        {
            // res.push_back(path);
        }
        if (left == s.size())
        {
            return;
        }

        for (int i = left; i < s.size(); i++)
        {
            // 当前结点
            path.push_back(s[i]);
            // 递归，不回头，不能重复选
            func(s, i + 1);
            // 回溯
            path.pop_back();
        }
    }

    bool isPalindrome(const string &data)
    {
        for (int i = 0; i < data.size() / 2; i++)
        {
            if (data[i] != data[data.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s)
    {
        res.clear();
        path.clear();
        func(s, 0);
    }

    // 需要知道字符串s，从哪里继续划分（上次划分结束位置）left
    void func(const string &s, int left)
    {
        // 结束
        if (left == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = left; i < s.size(); i++)
        {
            // 处理本结点
            // 也就是划分子串
            // 从left位置开始划分，后面取若干个字符
            // 这里要判断一下放入的子串是不是回文串
            string substr = s.substr(left, i - left + 1);
            if (!isPalindrome(substr))
            {
                // 当前不是回文串，不能停止
                // 比如aca，ac不是，但继续往后寻找aca是
                continue;
            }
            path.push_back(substr);
            // 递归，从i+1继续划分
            func(s, i + 1);
            // 回溯
            path.pop_back();
        }
    }

    bool isPalindrome(const string &data)
    {
        for (int i = 0; i < data.size() / 2; i++)
        {
            if (data[i] != data[data.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome("ab") << endl;
}