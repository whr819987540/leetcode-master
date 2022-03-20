#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定数组nums(无重复数字)，目标和target
// 从nums中选取数字（可重复选取）使得和为target
// 3/1/1和1/1/3是不同的序列，也就是说是排列问题
// 返回可行的排列数

// 回溯
// 横向遍历：因为原数组中无重复数字，所以不需要处理
// 纵向遍历：可以选自己（可以重复选取）,可以回头（排列）
class Solution
{
public:
    int cnt; // 排列数
    int combinationSum4(vector<int> &nums, int target)
    {
        cnt = 0;
        backtracking(nums, target, 0);
        return cnt;
    }

    // 搜索整棵树，所以不需要返回值
    void backtracking(const vector<int> &nums, const int target, int sum)
    {
        if (sum >= target)
        {
            if (sum == target)
            {
                cnt++;
            }
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 当前结点
            sum += nums[i];
            // 递归
            backtracking(nums, target, sum);
            // 回溯
            sum -= nums[i];
        }
    }
};

int main()
{
    {
        Solution s;
        vector<int> data{1, 2, 3};
        int n = 4;
        int cnt = s.combinationSum4(data, n);
        cout << cnt << endl;
    }
}