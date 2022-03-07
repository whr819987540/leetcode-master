#include <vector>
using namespace std;

// 在1-9中不重复的选取k个数，使之和为n
// 显然k<=9
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n)
    {
        path.clear(), res.clear();
        func(1, 9, 0, k, n);
        return res;
    }
    // 需要确定左右边界，两个参数
    // 为了避免重复求和，记录一下当前path的和
    void func(int left, int right, int sum, int k, int n)
    {
        // sum已经超过n，因为是正整数
        // 所以没必要再找了
        if (sum > n)
        {
            return;
        }
        // 注意最多选k个值
        if (path.size() == k)
        {
            // 和满足条件
            if (sum == n)
            {
                res.push_back(path);
            }
            return;
        }
        // 剩余结点数=right-i+1
        // 还需要的结点数=k-path.size()
        // right-i+1>=k-path.size()
        // i<=right+1-l+path.size()
        for (int i = left; i <= right && i <= right + 1 - k + path.size(); i++)
        {
            // 处理当前结点
            path.push_back(i);
            sum += i;
            // 递归
            func(i + 1, right, sum, k, n);
            // 回溯
            sum -= i;
            path.pop_back();
        }
    }
};