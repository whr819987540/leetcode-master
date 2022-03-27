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
}