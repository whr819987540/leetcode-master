#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 给定一个集合，求其幂集
// 如nums = [1,2,3]
// [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }

    void backtracking(vector<int> &nums, int left)
    {
        // 不管left是否越界，都将path放进去
        // 等价于加上一个null进行结束
        res.push_back(path);
        if (left == nums.size())
        {
            return;
        }

        for (int i = left; i < nums.size(); i++)
        {
            // 当前结点
            path.push_back(nums[i]);
            // 递归
            backtracking(nums, i + 1);
            // 回溯
            path.pop_back();
        }
    }
};