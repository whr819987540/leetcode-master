#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定一个字符串数组，每个字符串由字符01组成；给定整数m、n
// 返回数组最大子集的元素个数，使得子集中0字符的个数<=m，1字符的个数<=n
// strs = ["10","0001","111001","1","0"], m = 5, n = 3
// ["10","0001","1","0"]
// Output: 4

// 1、数组含义：dp[i][j]表示0字符个数不超过i、1字符个数不超过j时最大子集的元素个数
// 2、递推公式：遍历字符串，设字符串0的个数为num0,1的个数为num1
// 前值表示不放入当前字符串，后值表示放入当前字符串（+1）
//            dp[i][j] = max(dp[i][j],dp[i-num0][j-num1] + 1)
// 3、初始化：dp[0][j]，查找字符串“1”的个数；dp[i][0]，查找字符串"0"的个数
// 4、遍历顺序：从小到大，从小到大
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 初始化
        // dp[0][j]，‘1’的个数
        int str_1_num = get_str_num(strs, "1");
        for (int j = 1; j <= min(n, str_1_num); j++)
        {
            dp[0][j] = j;
        }
        for (int j = min(n, str_1_num) + 1; j <= n; j++)
        {
            dp[0][j] = min(n, str_1_num);
        }
        // dp[i][0]，‘0’的个数
        int str_0_num = get_str_num(strs, "0");
        for (int i = 1; i <= min(n, str_0_num); i++)
        {
            dp[i][0] = i;
        }
        for (int i = min(n, str_0_num) + 1; i <= n; i++)
        {
            dp[i][0] = min(n, str_0_num);
        }

        // 遍历，实际上只需要每个字符串的01数量
        vector<vector<int>> nums = countStrs01Num(strs);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (auto num : nums)
                {
                    int num0 = num[0], num1 = num[1];
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
        }
    }
    vector<vector<int>> countStrs01Num(const vector<string> &strs)
    {
        vector<vector<int>> data;
        for (auto str : strs)
        {
            data.push_back({get_char_num(str, '0'), get_char_num(str, '1')});
        }
    }

    int get_str_num(const vector<string> &strs, const string s)
    {
        int cnt = 0;
        for (auto str : strs)
        {
            if (str == s)
            {
                cnt++;
            }
        }
        return cnt;
    }
    int get_char_num(const string &s, const char c)
    {
        int cnt = 0;
        for (auto i : s)
        {
            if (i == c)
            {
                cnt++;
            }
        }
        return cnt;
    }
};

// 在写三层循环最内部时，想到一个问题，如果单纯这样取最大值
// 无法避免一个字符串被重复取的情况
// 所以应该将遍历字符串放在外层
// 为什么要这样做呢？
// 字符串相等于物品，有01字符个数两个维度，背包也有两个容量限制（01字符个数）
// 物品的values都为1（在增加子集数量上，效果都为1）
class Solution1
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 初始化
        // dp[0][j]，‘1’的个数
        int str_1_num = get_str_num(strs, "1");
        for (int j = 1; j <= min(n, str_1_num); j++)
        {
            dp[0][j] = j;
        }
        for (int j = min(n, str_1_num) + 1; j <= n; j++)
        {
            dp[0][j] = min(n, str_1_num);
        }
        // dp[i][0]，‘0’的个数
        int str_0_num = get_str_num(strs, "0");
        for (int i = 1; i <= min(m, str_0_num); i++)
        {
            dp[i][0] = i;
        }
        for (int i = min(m, str_0_num) + 1; i <= m; i++)
        {
            dp[i][0] = min(m, str_0_num);
        }

        display(dp);

        // 遍历，实际上只需要每个字符串的01数量
        vector<vector<int>> nums = countStrs01Num(strs);
        display(nums);
        for (auto num : nums) // 遍历字符串/物品
        {
            int num0 = num[0], num1 = num[1];
            // for (int i = 1; i <= n; i++) // 背包的两个维度
            // {
            //     for (int j = 1; j <= m; j++)
            //     {
            //         if (i >= num0 && j >= num1) //同时满足两个维度的限制
            //         {
            //             dp[i][j] = max(dp[i][j], dp[i - num0][j - num1]);
            //         }
            //     }
            // }

            // 优化遍历起点
            cout << "num0:" << num0 << " num1:" << num1 << endl;
            for (int i = num0; i <= m; i++) // 背包的两个维度+同时满足两个维度的限制
            {
                for (int j = num1; j <= n; j++)
                {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
            display(dp);
        }
        display(dp);
        return dp[m][n];
    }
    vector<vector<int>> countStrs01Num(const vector<string> &strs)
    {
        vector<vector<int>> data;
        for (auto str : strs)
        {
            data.push_back({get_char_num(str, '0'), get_char_num(str, '1')});
        }
        return data;
    }

    int get_str_num(const vector<string> &strs, const string s)
    {
        int cnt = 0;
        for (auto str : strs)
        {
            if (str == s)
            {
                cnt++;
            }
        }
        return cnt;
    }
    int get_char_num(const string &s, const char c)
    {
        int cnt = 0;
        for (auto i : s)
        {
            if (i == c)
            {
                cnt++;
            }
        }
        return cnt;
    }
    void display(const vector<vector<int>> &data)
    {
        for (auto outer : data)
        {
            for (auto inner : outer)
            {
                cout << inner << "\t";
            }
            cout << endl;
        }
        cout << "----------\n";
    }
};

// 不需要初始化，否则会重复找到单独的字符串“0”或“1”
class Solution2
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        display(dp);

        // 遍历，实际上只需要每个字符串的01数量
        vector<vector<int>> nums = countStrs01Num(strs);
        display(nums);
        for (auto num : nums) // 遍历字符串/物品
        {
            int num0 = num[0], num1 = num[1];
            // 优化遍历起点
            cout << "num0:" << num0 << " num1:" << num1 << endl;
            for (int i = num0; i <= m; i++) // 背包的两个维度+同时满足两个维度的限制
            {
                for (int j = num1; j <= n; j++)
                {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
            display(dp);
        }
        display(dp);
        return dp[m][n];
    }
    vector<vector<int>> countStrs01Num(const vector<string> &strs)
    {
        vector<vector<int>> data;
        for (auto str : strs)
        {
            data.push_back({get_char_num(str, '0'), get_char_num(str, '1')});
        }
        return data;
    }

    int get_str_num(const vector<string> &strs, const string s)
    {
        int cnt = 0;
        for (auto str : strs)
        {
            if (str == s)
            {
                cnt++;
            }
        }
        return cnt;
    }
    int get_char_num(const string &s, const char c)
    {
        int cnt = 0;
        for (auto i : s)
        {
            if (i == c)
            {
                cnt++;
            }
        }
        return cnt;
    }
    void display(const vector<vector<int>> &data)
    {
        for (auto outer : data)
        {
            for (auto inner : outer)
            {
                cout << inner << "\t";
            }
            cout << endl;
        }
        cout << "----------\n";
    }
};

// 遍历顺序错误
// 两个维度都应该从大到小遍历，为什么？
// 如果从小到大遍历，ij比较小时，可能将当前字符串放入，ij比较大时，又将当前字符串放入
// 而如果从大到小遍历，即使ij比较大时，将当前字符串放入，遍历到ij较小时，dp不会用到ij较大时的dp值
// 只会用到ij更小时的dp值，而ij更小时的dp值一定是没有放入当前字符串的值
// 所以不会重复
class Solution3
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        display(dp);

        // 遍历，实际上只需要每个字符串的01数量
        vector<vector<int>> nums = countStrs01Num(strs);
        cout << "0s 1s \n";
        display(nums);
        for (auto num : nums) // 遍历字符串/物品
        {
            int num0 = num[0], num1 = num[1];
            // 优化遍历起点
            cout << "num0:" << num0 << " num1:" << num1 << endl;
            // 同时对遍历维度的终点进行优化
            for (int i = m; i >= num0; i--) // 背包的两个维度+同时满足两个维度的限制
            {
                for (int j = n; j >= num1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
            display(dp);
        }
        display(dp);
        return dp[m][n];
    }
    vector<vector<int>> countStrs01Num(const vector<string> &strs)
    {
        vector<vector<int>> data;
        for (auto str : strs)
        {
            data.push_back({get_char_num(str, '0'), get_char_num(str, '1')});
        }
        return data;
    }

    int get_str_num(const vector<string> &strs, const string s)
    {
        int cnt = 0;
        for (auto str : strs)
        {
            if (str == s)
            {
                cnt++;
            }
        }
        return cnt;
    }
    int get_char_num(const string &s, const char c)
    {
        int cnt = 0;
        for (auto i : s)
        {
            if (i == c)
            {
                cnt++;
            }
        }
        return cnt;
    }
    void display(const vector<vector<int>> &data)
    {
        for (auto outer : data)
        {
            for (auto inner : outer)
            {
                cout << inner << "\t";
            }
            cout << endl;
        }
        cout << "----------\n";
    }
};

int main()
{
    {
        Solution3 s;
        vector<string> strs{"10", "0001", "111001", "1", "0"};
        int m = 5, n = 3;
        int res = s.findMaxForm(strs, m, n);
        cout << res << endl;
    }
}