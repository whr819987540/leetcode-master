#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 全排列
// 给一个数组，没有重复元素
// 返回所有排列情况
// nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// 排列中，横向遍历可以是所有值
// 纵向遍历，只要这个值在这个路径上没访问过，都可以访问
// 因为是路径访问记录，所以参数应该放到回溯函数中或者设置为全局变量

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    // 参数：record，记录是否访问过
    // 不需要知道左边界，因为可以回头，只要该元素未被访问过
    void backtracking(const vector<int> &nums, map<int, bool> &record)
    {
        // 取叶子结点的结果（因为对path的大小有限制）
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // 当前结点
            if (record[nums[i]])
            {
                continue;
            }
            path.push_back(nums[i]);
            record[nums[i]] = true;
            // 递归
            backtracking(nums, record);
            // 回溯
            record[nums[i]] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        map<int, bool> record;
        res.clear(), path.clear(),record.clear();
        backtracking(nums, record);
        return res;
    }
};