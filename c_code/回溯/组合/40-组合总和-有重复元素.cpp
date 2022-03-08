#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// 给一个可能有重复元素的数组c，目标和t
// 从c中选任意多个元素，这些元素在c中是可以重复的，但每个元素只能在结果集合中出现一次，使他们的和为t
// 也就是说，c中本身可以有重复元素，但元素不能被重复选
// 因为是组合，不能回头；因为不能重复选，不能选自己，所以左边界+1

// 错误
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        res.clear(), path.clear();
        func(candidates, 0, candidates.size(), target, 0);
        return res;
    }
    void func(vector<int> &candidates, int left, int right, int target, int sum)
    {
        if (target == sum)
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
            // 处理当前结点
            path.push_back(candidates[i]);
            sum += candidates[i];
            // 递归
            func(candidates, i + 1, right, target, sum);
            // 回溯
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

// 因为有重复元素所以必须先排序比如这个
// [10, 1, 2, 7, 6, 1, 5]
// [[1,2,5],[1,7],[1,6,1],[2,6],[2,1,5],[7,1]]
// [1,1,2,5,6,7,10]
// 这个难点就在于重复元素有时可以同时出现(1,1,6)，有时又不想让它们同时出现(1,2,5和2,1,5)

// 先排序
// 对于重复元素
// 针对第一种情况，在递归里面可以同时出现，只要不是自己、不回头就行
// 针对第二种情况，排序后，在同一层里面不应该出现重复元素

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        res.clear(), path.clear();
        sort(candidates.begin(), candidates.end());
        func(candidates, 0, candidates.size(), target, 0);
        return res;
    }
    void func(vector<int> &candidates, int left, int right, int target, int sum)
    {
        if (target == sum)
        {
            res.push_back(path);
            return;
        }
        // 顺便剪枝
        for (int i = left; i < right && sum + candidates[i] <= target; i++)
        {
            // 在横向遍历中，不能出现重复元素
            // 检查i!=left，因此该元素没有前值
            if (i != left && candidates[i] == candidates[i - 1])
            {
                // 该元素出现过
                continue;
            }
            // 处理当前结点
            path.push_back(candidates[i]);
            sum += candidates[i];
            // 递归
            // 在递归里面可以出现重复元素，只要不是自己、不回头即可
            func(candidates, i + 1, right, target, sum);
            // 回溯
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution s;
    s.combinationSum2(candidates, target);
}