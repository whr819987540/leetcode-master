#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// 给一个无重复元素的数组c，目标和t
// 从c中选任意多个元素，且这些元素可以重复，使他们的和为t
// 相比于C(n,k)，这个没有元素个数限制，没有重复的限制
// 第一层用了c，下面还可以用c
// 终止条件只是和超过了t
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        res.clear(), path.clear();
        func(candidates, 0, candidates.size(), target, 0);
        return res;
    }
    // 参数
    // 数组c，目标和t，现在的和sum
    // 左右边界，不能往回找，比如1,1,2和2,1,1，所以不能还是从头开始找
    // 但是可以重复，所以还是从left开始找
    // 而C(n,k)那题，不能重复，所以从left+1开始找
    void func(vector<int> &candidates, int left, int right, int target, int sum)
    {
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        else if (sum > target)
        {
            return;
        }

        for (int i = left; i < right; i++)
        {
            // 当前结点
            path.push_back(candidates[i]);
            sum += candidates[i];
            // 递归
            func(candidates, i, right, target, sum);
            // 回溯
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

// 先对c进行排序，剪枝
class Solution
{
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        res.clear(), path.clear();
        sort(candidates.begin(), candidates.end());
        func(candidates, 0, candidates.size(), target, 0);
        return res;
    }
    void func(vector<int> &candidates, int left, int right, int target, int sum)
    {
        // target不可能大于sum，因为进行了剪枝
        if (target == sum)
        {
            res.push_back(path);
            return;
        }
        // 剪枝
        for (int i = left; i < right && sum + candidates[i] <= target; i++)
        {
            // 处理结点
            path.push_back(candidates[i]);
            sum += candidates[i];
            // 递归
            // 因为是组合，所以需要左边界，不能回头
            // 因为可以重复，所以从i开始
            func(candidates, i, right, target, sum);
            // 回溯
            sum -= candidates[i];
            path.pop_back();
        }
    }
};