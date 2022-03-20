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

// dp
// 1、数组含义：dp[i]表示使得和为i的排列数
// 2、递推公式：dp[i] = dp[i] + dp[i-nums]
// 3、初始化：dp[0] = 1，不考虑任何数字时，要使和为0，就是一个数都不放
// 4、遍历顺序：可以重复选取数字，是完全背包，背包容量递增
// 是排列问题，需要重复考虑物品顺序，所以先遍历背包容量，再遍历物品
class Solution2
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        // 先遍历背包容量，从大到小
        // 背包容量从哪儿开始？
        // 如果题目规定物品的重量都是正数，没必要从0开始，因为0时肯定放不下物品
        // 如果重量可以为0，则遇到为0的物品，dp[i] += dp[i-0]即dp[i] = dp[i]*2
        // 还是修改为0比较稳妥
        for (int j = 0; j <= target; j++)
        {
            // 再遍历物品
            for (int i = 0; i < nums.size(); i++)
            {
                if (j >= nums[i])
                {
                    dp[j] = dp[j] + dp[j - nums[i]];
                }
                // 否则，放不进物品i，保留原值即可
            }
        }
        return dp[target];
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

    {
        Solution2 s;
        vector<int> data{1, 2, 3};
        int n = 4;
        int cnt = s.combinationSum4(data, n);
        cout << cnt << endl;
    }
}