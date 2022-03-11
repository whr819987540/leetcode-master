#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// - 从左往右遍历，如果右侧比左侧评分高，右侧=左侧+1
// - 前面处理了右侧>左侧的情况，还可能出现1,4,3这种4比左侧和右侧都大的情况
// - 从右往左遍历，如果左侧比右侧评分高，左侧=max（左侧，右侧+1）
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> nums(ratings.size(), 1);
        // 从左往右遍历
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                nums[i] = nums[i - 1] + 1;
            }
        }
        // 从右往左遍历
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                nums[i] = max(nums[i], nums[i + 1] + 1);
            }
        }
        // 统计糖果总数
        int result = 0;
        for (auto num : nums)
        {
            result += num;
        }
        return result;
    }
};