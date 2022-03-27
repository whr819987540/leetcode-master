#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定一个整数数组nums
// 返回某个连续数组的和，要求和最大
// [-2,1,-3,4,-1,2,1,-5,4]
// 6 = [4,-1,2,1]

// 贪心
// 遍历一次，只要不为负数（可以使后面值变大）就不重新开始
// 在遍历时，同时记录最大值
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // res必须被初始化为第一个值，保证有结果输出
        // 实际上初始化为INT_MIN也行，但是不能初始化为0
        // sum由于还没考虑值，所以初始化为0
        int res = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 顺序不能颠倒
            // 否则更新sum之后的0会影响结果
            res = max(res, sum + nums[i]);
            sum = max(sum + nums[i], 0);
        }
        return res;
    }
};

// 1、数组含义：dp[i]表示一定放第i个数时，最大子数组和
// 这样能保证连续
// 2、递推公式：dp[i]=max(dp[i-1]+nums[i],nums[i])
// 因为必须放第i个数，所以，要么接上第i-1个数，要么不接上
// 这个和674有点像，都是对一个数组进行操作
// 3、初始化：dp[0]=nums[0]
// 4、遍历顺序：递增
class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            // if (dp[i - 1] > 0)
            // {
            //     dp[i] = dp[i - 1] + nums[i];
            // }
            // else
            // {
            //     dp[i] = nums[i];
            // }
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        // return dp[nums.size() - 1];
        // 最大子数组和不一定以最后一个元素结尾
        return res;
    }
};

int main()
{
    {
        Solution s;
        vector<int> data = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        cout << s.maxSubArray(data) << endl;
    }

    {
        Solution s;
        vector<int> data = {-2, 1, -3};
        cout << s.maxSubArray(data) << endl;
    }

    {
        Solution s;
        vector<int> data = {-2, -3, -1};
        cout << s.maxSubArray(data) << endl;
    }

    {
        Solution2 s;
        vector<int> data = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        cout << s.maxSubArray(data) << endl;
    }

    {
        Solution2 s;
        vector<int> data = {-2, 1, -3};
        cout << s.maxSubArray(data) << endl;
    }

    {
        Solution2 s;
        vector<int> data = {-2, -3, -1};
        cout << s.maxSubArray(data) << endl;
    }
}