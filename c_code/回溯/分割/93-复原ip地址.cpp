#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 给定一个由数字组成的字符串s，给出所有可能的ip地址
// 比如"25525511135"
// 输出：["255.255.11.135","255.255.111.35"]
// ip地址的数字的范围是0-255，数字不能有前导0
class Solution
{
public:
    vector<string> res;
    vector<string> path;
    vector<string> restoreIpAddresses(string s)
    {
        res.clear(), path.clear();
        backtracking(s, 0);
        return res;
    }

    // 参数：string s，左边界left
    void backtracking(const string &s, int left)
    {
        if (path.size() == 4)
        {
            // 搜索完s
            if (left == s.size())
            {
                res.push_back(join(path));
            }
            return;
        }

        for (int i = left; i < s.size(); i++)
        {
            // 当前结点
            string substr = s.substr(left, i - left + 1);
            // 剪枝
            // 超过255，不需要往后搜索
            if (atoi(substr.c_str()) > 255)
            {
                break;
            }
            path.push_back(substr);

            // 递归
            backtracking(s, i + 1);

            // 回溯
            path.pop_back();

            // 考虑前导0
            // 若左边界为0，只能选0，不需要往后搜索了
            // 也可以视为一种剪枝
            if (s[left] == '0')
            {
                break;
            }
        }
    }

    // 根据path生成ip string
    string join(const vector<string> &path)
    {
        string res;
        for (int i = 0; i < path.size() - 1; i++)
        {
            res += path[i] + ".";
        }
        res += path.back();
        return res;
    }
};

int main()
{
    Solution s;
    string tmp = s.join({"1", "1", "1", "1"});
    cout << tmp << endl;
}