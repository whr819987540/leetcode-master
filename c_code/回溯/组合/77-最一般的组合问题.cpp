#include <vector>
using namespace std;
// 给定n和k，在1-n这n个数中选取k个数
// 要求列出所有情况
// 数学上就是C(n,k)

class Solution
{
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k)
    {
        // 初始化
        path.clear(), res.clear();
        func(1, n, k);
        return res;
    }

    // 因为是组合问题，不能重复选，所以确定一下数组的范围
    void func(int left, int right, int k)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        // 如果后面数组的总数都不能满足要求，没必要再递归了
        // 还有的元素个数=right-i+1
        // 还需要的元素个数=k-path.size()
        // right-i+1>=k-path.size()即i<=right+1-k+path.size()
        for (int i = left; i <= right + 1 - k + path.size(); i++)
        {
            // 处理本结点
            path.push_back(i);
            // 递归
            // 此时因为选取了i，所以后面只能从i+1开始
            func(i + 1, right, k);
            // 回溯
            path.pop_back();
        }
    }
};