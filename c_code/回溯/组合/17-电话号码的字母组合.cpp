#include <vector>
#include <string>
#include <map>
using namespace std;

// 给定一个只有2-9的字符串
// 将数字按照九键输入法映射到字母上

class Solution
{
public:
    // 先构建数字到字母的映射关系
    const string map[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> res;
    string path;
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        path = "";
        func(0, digits);
        return res;
    }
    // 参数
    // 需要知道当前数字下标
    // 需要知道数字字符串
    void func(int index, string digits)
    {
        // 终止
        if (index == digits.length())
        {
            if (path != "")
            {
                res.push_back(path);
            }
            return;
        }
        // 无法剪枝，因为这是在不同集合上的操作
        // 无法要求不重复或个数限制
        int digit = digits[index] - '0';
        string alphas = map[digit];
        for (auto alpha : alphas)
        {
            // 处理
            path += alpha;
            // 递归
            func(index + 1, digits);
            // 回溯
            path.erase(path.end() - 1);
        }
    }
};