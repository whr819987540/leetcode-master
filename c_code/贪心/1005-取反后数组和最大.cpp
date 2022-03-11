#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 对nums中的元素进行k次取反，使得最后的数组和最大
// 对于负数，优先取反绝对值大的（扫描一次）
// 如果次数还有剩余
// 如果次数为偶数，返回当前数组和
// 否则，对最小的元素取反
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int i = 0;
        // 升序排序
        sort(nums.begin(), nums.end());
        while (i < nums.size() && k != 0)
        {
            // 对负数取反
            if (nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
                i++;
            }
            // 遇到正数或0
            else
            {
                // 对最小非负数取反
                if (k % 2 != 0)
                {
                    // 最小非负数出现在i或者i-1处
                    int index = i;
                    if (i - 1 >= 0 && nums[i - 1] < nums[i])
                    {
                        index = i - 1;
                    }
                    nums[index] = -nums[index];
                    k = 0;
                }
                break;
            }
        }
        // 查看退出循环的原因
        // if (k == 0)
        // {
        //     // 不需要继续处理
        //     // 直接求和
        // }
        // i越界
        // else
        if (k != 0)
        {
            // 对最小的非负数取反
            if (k % 2 != 0)
            {
                nums[nums.size() - 1] = -nums[nums.size() - 1];
            }
        }
        // 对序列求和
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }
        return sum;
    }
};

// 按照绝对值升序排序
class Solution
{
public:
    static bool cmp(const int &a, const int &b)
    {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // 按绝对值降序排序
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size() && k; i++)
        {
            if (nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k != 0 && k % 2 == 1)
        {
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        }
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }
        return sum;
    }
};