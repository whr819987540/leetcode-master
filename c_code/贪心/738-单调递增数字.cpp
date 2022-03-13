#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 如果一个数字从左到右的所有相邻位都满足左侧<=右侧，则称这个数是单调递增的
// 给定一个n，找到一个i，使得i为不超过n的最大单调递增整数
class Solution1
{
public:
    int monotoneIncreasingDigits(int n)
    {
        // 将n分拆
        vector<int> bits = split(n);
        int res = bits[0];
        // if bits[i-1]<=bits[i],continue
        // else bits[i-1]=bits[i-1] - 1，其余位补9
        for (int i = 1; i < bits.size(); i++)
        {
            // 不满足
            if (bits[i - 1] > bits[i])
            {
                // 回退一位
                res = res - 1;
                while (i < bits.size())
                {
                    res = res * 10 + 9;
                    i++;
                }
                break;
            }
            res = res * 10 + bits[i];
        }
        return res;
    }
    vector<int> split(int i)
    {
        vector<int> bits;
        while (i)
        {
            bits.push_back(i % 10);
            i = i / 10;
        }
        reverse(bits.begin(), bits.end());
        return bits;
    }
};

// 上面的有bug，332，对第二个3回退，但是没有对第1个3回退
// 所以还是老老实实用一个vector来记录就好
class Solution2
{
public:
    int monotoneIncreasingDigits(int n)
    {
        // 将n分拆
        vector<int> bits = split(n);
        // if bits[i-1]<=bits[i],continue
        // else: 向左找到和bits[i-1]相等的，令其值为bits[i-1] - 1，后面的位补9
        // 这里必须要往左找相等的，否则修改i-1，i-1会和它左侧的冲突
        for (int i = 1; i < bits.size(); i++)
        {
            // 不满足
            if (bits[i - 1] > bits[i])
            {
                // 向左寻找
                int j = i - 1;
                while (j - 1 >= 0 && bits[j] == bits[j - 1])
                {
                    j--;
                }
                bits[j]--;
                // 将右侧的都替换为9
                for (j = j + 1; j < bits.size(); j++)
                {
                    bits[j] = 9;
                }
            }
        }
        // 累乘
        int res = 0;
        for (auto bit : bits)
        {
            res = res * 10 + bit;
        }
        return res;
    }
    vector<int> split(int i)
    {
        vector<int> bits;
        while (i)
        {
            bits.push_back(i % 10);
            i = i / 10;
        }
        reverse(bits.begin(), bits.end());
        return bits;
    }
};
class Solution3
{
public:
    int monotoneIncreasingDigits(int n)
    {
        // 将n分拆
        vector<int> bits = split(n);
        // 从右往左遍历
        for (int i = bits.size() - 1; i - 1 >= 0; i--)
        {
            if (bits[i - 1] > bits[i])
            {
                bits[i - 1]--;
                // 右侧的值都变为9
                for (int j = i; j < bits.size(); j++)
                {
                    bits[j] = 9;
                }
            }
        }
        int res = 0;
        for (auto bit : bits)
        {
            res = res * 10 + bit;
        }
        return res;
    }

    vector<int> split(int i)
    {
        vector<int> bits;
        while (i)
        {
            bits.push_back(i % 10);
            i = i / 10;
        }
        reverse(bits.begin(), bits.end());
        return bits;
    }
};

// 进行两次优化
// 1、不拆分 2、置9只进行一次
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string str = to_string(n);
        // 从右往左遍历
        int pos = str.size();// pos到str.size()-1都需置0
        for (int i = str.size() - 1; i >= 1; i--)
        {
            if (str[i - 1] > str[i])
            {
                str[i - 1]--;
                pos = i;
            }
        }
        for (; pos < str.size(); pos++)
        {
            str[pos] = '9';
        }
        return stoi(str);
    }
};

int main()
{
    Solution s;
    int res = s.monotoneIncreasingDigits(13324);
    cout << res;
}