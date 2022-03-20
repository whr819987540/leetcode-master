#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 检查一个数组是否能被分割为两个子数组，使得子数组之和相等
// 等价于某个子数组之和等于原数组之和的一半

// 暴力枚举（回溯）
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // nums升序排序，便于横向遍历时进行剪枝
        sort(nums.begin(), nums.end());
        // 求和
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }

        if (sum % 2)
        {
            return false;
        }
        else
        {
            return backtracking(nums, 0, 0, sum);
        }
    }

    bool backtracking(const vector<int> &nums, int left, int pwd_sum, const int &total_sum)
    {
        if (left == nums.size())
        {
            return false;
        }
        if (pwd_sum * 2 == total_sum)
        {
            return true;
        }

        for (int i = left; i < nums.size(); i++)
        {
            if (i != left && nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                // 当前结点
                pwd_sum += nums[i];
                // 递归
                if (backtracking(nums, i + 1, pwd_sum, total_sum))
                {
                    return true;
                };
                // 回溯
                pwd_sum -= nums[i];
            }
        }
        return false;
    }
};

// n=sum/2,values即为数值，weights也为数值
// 检查背包重量为n时，能否放到价值为n的物品（不可能超过n，因为每个物品的weight=value）

// 二维数组
// 1、数组含义：dp[i][j]表示考虑0-i个物品，最大重量为j时的最大价值
// 2、递推公式：
// if j>=weights[i], dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+values[i])
// else dp[i][j] = dp[i-1][j]
// 3、初始化：dp[i][0]=0, dp[0][j]=values[0] when j>=weight[0]
// 4、遍历顺序：
// 最后，dp[values.size()-1][n]==n

// 用dp的关键是能将原题目抽象为01背包问题，即是否选择放入某个子数组的问题
class Solution1
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = sumCalculate(nums);
        if (sum % 2) //奇数
        {
            return false;
        }
        else
        {
            sum = sum / 2;
        }
        // nums = weights = values
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, 0));
        // dp[i][0]=0
        // dp[0][i]=values[0] if i>=weights[0]
        for (int weight = nums[0]; weight <= sum; weight++)
        {
            dp[0][weight] = nums[0];
        }

        for (int item = 1; item < nums.size(); item++)
        {
            for (int weight = 1; weight <= sum; weight++)
            {
                // weight>=weights[item]
                if (weight >= nums[item])
                {
                    dp[item][weight] = max(dp[item - 1][weight], dp[item - 1][weight - nums[item]] + nums[item]);
                }
                else
                {
                    dp[item][weight] = dp[item - 1][weight];
                }
            }
        }
        return dp[nums.size() - 1][sum] == sum;
    }

    int sumCalculate(const vector<int> &nums)
    {
        int res = 0;
        for (auto num : nums)
        {
            res += num;
        }
        return res;
    }

    void display(const vector<vector<int>> &data)
    {
        for (auto outer : data)
        {
            for (auto inner : outer)
            {
                cout << inner << " ";
            }
            cout << endl;
        }
        cout << "----------\n";
    }
};

// 一维数组
// 1、数组含义：dp[j]表示重量为j时的最大价值
// 2、递推公式：dp[j] = max( dp[j], dp[j-weight] + value)
// 3、初始化：还没有遍历物品，所以价值都为0
// 4、遍历顺序：物品递增，重量递减
// 最后，检查dp[n]==n
class Solution2
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = sumCalculate(nums);
        if (sum % 2) //奇数
        {
            return false;
        }
        else
        {
            sum = sum / 2;
        }

        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[sum] == sum;
    }
    int sumCalculate(const vector<int> &nums)
    {
        int res = 0;
        for (auto num : nums)
        {
            res += num;
        }
        return res;
    }
};
int main()
{
    {
        Solution1 s;
        {
            vector<int> data{1, 5, 11, 5};
            cout << s.canPartition(data) << endl;
        }

        {
            vector<int> data{1, 2, 3, 5};
            cout << s.canPartition(data) << endl;
        }
    }

    {
        Solution2 s;
        {
            vector<int> data{1, 5, 11, 5};
            cout << s.canPartition(data) << endl;
        }

        {
            vector<int> data{1, 2, 3, 5};
            cout << s.canPartition(data) << endl;
        }
    }
}