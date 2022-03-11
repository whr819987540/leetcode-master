#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 要求是连续的数组
// 使之和最大
// 从头开始遍历，记录和，如果大于max，更新max
// 如果和变为负，表明现在引入的值抵消了之前的所有成果
// 所以不能引入这个值
// 反向来看，对于当前值，前面的和如果大于max，则该值已经被记录
// 如果前面的和为正，则会增加当前值，应该放入
// 但是为负值，就不要放入了
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = INT_MIN;
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
            max = sum > max ? sum : max;
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return max;
    }
};