#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 给定一个序列，可能有重复元素
// 要得到该序列的子序列，且该子序列为非递减序列（当出现重复元素时）
// 非递减序列至少有两个元素
// [4,4,3,2,1]
// [[4,4]]
// [4,6,7,7]
// [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        path.clear(), res.clear();
        backtracking(nums, 0);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int> &nums, int left)
    {
        // null值
        // 这里要求path中至少有两个元素
        if (path.size() >= 2)
        {
            res.push_back(path);
        }
        // 越界，退出
        if (left == nums.size())
        {
            return;
        }

        map<int, bool> record; // 访问记录
        for (int i = left; i < nums.size(); i++)
        {
            // 当前结点
            // 1、保证未访问过
            // 2、保证非递减即当前元素>=path的最后一个元素（如果path有元素）
            // 注意这里在访问path的最后一个元素时，需要保证path有元素
            if (record[nums[i]] || path.size() && nums[i] < path.back())
            {
                continue;
            }
            record[nums[i]] = true;
            path.push_back(nums[i]);

            // 递归
            backtracking(nums, i + 1);
            // 回溯
            path.pop_back();
            // 不能修改访问记录
        }
    }
};

int main()
{
    vector<int> data = {4, 6, 7, 7};
    Solution s;
    vector<vector<int>> res = s.findSubsequences(data);
    for (auto outer : res)
    {
        for (auto inner : outer)
        {
            cout << inner << " ";
        }
        cout << endl;
    }
}