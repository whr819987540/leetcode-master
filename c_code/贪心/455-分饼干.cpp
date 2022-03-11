#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

数组g为每个孩子的最小胃口，s为饼干的尺寸
目标是分配饼干，满足尽可能多的孩子
首先对g和s降序排序
对于最大的饼干，应该分配给能满足条件且胃口最大的孩子

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // 排序
        sort(g.begin(), g.end()), sort(s.begin(), s.end());
        int cnt = 0;              // 计数值
        int index = s.size() - 1; // 待分配饼干的下标
        // 反向遍历胃口数组
        for (int i = g.size() - 1; i >= 0 && index >= 0; i--)
        {
            if (s[index] >= g[i])
            {
                cnt++;
                index--; // 分配饼干
            }
        }
        return cnt;
    }
};