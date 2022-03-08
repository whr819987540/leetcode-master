#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 相比于79求幂集，本题的数组中可能有重复元素
//  [1,2,2]
// [[],[1],[1,2],[1,2,2],[2],[2,2]]
// 和处理有重复元素的组合一样，横向遍历时，不能有重复元素
// 比如1,1,2，同一层中出现过1，没必要再出现1
// 但在纵向遍历时，重复元素可以，保证1,1,2的存在
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // 先对nums排序方便横向遍历找重复元素
        sort(nums.begin(), nums.end());
        res.clear(), path.clear();

        backtracking(nums, 0);
        return res;
    }
    // 参数：left用来记录有序数组的左边界
    void backtracking(const vector<int> &nums, int left)
    {
        // 引入null，不管left有没有越界
        res.push_back(path);
        if (left == nums.size())
        {
            return;
        }

        for (int i = left; i < nums.size(); i++)
        {
            // 当前结点
            // 不能和前一个元素重复，同时起到了剪枝的作用
            if (i != left && nums[i] == nums[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            // 递归
            backtracking(nums, i + 1);
            // 回溯
            path.pop_back();
        }
    }
};