#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [2,3,1,1,4]
// 初始位置为index=0
// 数组元素值表示索引值最大可以增加多少
// 问是否能到达最后一个索引
// 因为可以离散变化，所以每次都希望找到一个最大增加值
// index=0，最大可以走两个索引。因为走两个，无法到最后，所以进行如下比较：
// 走一个，是3，走两个，是1
// 所以选择走1
// index=1，可以走3，index+3>=size()所以结束

class Solution
{
public:
    // [2,3,1,1,4]
    bool canJump(vector<int> &nums)
    {
        int index = 0;
        while (index < nums.size())
        {
            // 刚好到达
            if (index == nums.size() - 1)
            {
                return true;
            }
            // 走不动了且没有到达终点
            if (nums[index] == 0)
            {
                return false;
            }
            // 不需要经过中间结点就能到达
            // 同时防止index+nums[index]越界
            if (index + nums[index] >= nums.size() - 1)
            {
                return true;
            }
            // 借助中间结点
            // 搜索可达范围内(index+1到index+nums[index])范围内的最大值对应索引
            // 搜索可达范围内的最大值index
            // 特别注意，如果在可达范围内，有多个最大值，应该选最远的
            // 所以值>=max时，就需要更新index
            index = get_max_index(nums, index);
        }
    }
    int get_max_index(vector<int> &nums, int index)
    {
        int max_index = index + 1;
        int max = nums[max_index];
        for (int i = index + 1; i <= index + nums[index]; i++)
        {
            if (nums[i] >= max)
            {
                max_index = i;
                max = nums[i];
            }
        }
        return max_index;
    }
};

// 不应该比较index+1到nums[index]中nums[i]的最大值
// 而应该是i+nums[i]的最大值
class Solution
{
public:
    // [2,3,1,1,4]
    bool canJump(vector<int> &nums)
    {
        int index = 0;
        while (index < nums.size())
        {
            // 刚好到达
            if (index == nums.size() - 1)
            {
                return true;
            }
            // 走不动了且没有到达终点
            if (nums[index] == 0)
            {
                return false;
            }
            // 不需要经过中间结点就能到达
            // 同时防止index+nums[index]越界
            if (index + nums[index] >= nums.size() - 1)
            {
                return true;
            }
            // 借助中间结点
            // 搜索可达范围内(index+1到index+nums[index])范围内的最大值+索引值对应索引
            // 这才是下次可以到达的最远地方
            // 4,2,0,0,1,2
            index = get_max_index(nums, index);
        }
    }
    int get_max_index(vector<int> &nums, int index)
    {
        int max_index = index + 1;
        int max = nums[max_index];
        for (int i = index + 1; i <= index + nums[index]; i++)
        {
            if (nums[i] + i >= max + max_index)
            {
                max_index = i;
                max = nums[i];
            }
        }
        return max_index;
    }
};

// 进一步精简代码，用furthest来代替i+nums[i]
// 比较巧妙的是循环条件中有furthest，且在循环汇总更新该变量
class Solution
{
public:
    // [2,3,1,1,4]
    bool canJump(vector<int> &nums)
    {
        int furthest = 0 + nums[0];
        for (int index = 0; index <= furthest; index++)
        {
            furthest = (index + nums[index]) > furthest ? (index + nums[index]) : furthest;
            if (furthest >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};