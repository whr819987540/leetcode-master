#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 55是输出能否跳过去
// 45是输出跳过去的最小步数

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // 每次选择i+nums[i]最大的进行跳跃
        int pwd_loc = 0;
        int furthest = pwd_loc + nums[pwd_loc];
        int cnt = 0;
        while (pwd_loc < nums.size() - 1)
        {
            // 没到最后位置，且不能前进
            if (nums[pwd_loc] == 0)
            {
                return -1;
            }
            // 不需要中间结点即可到达
            if (furthest >= nums.size() - 1)
            {
                cnt++;
                break;
            }
            // 还需要中间结点
            // 在pwd_loc+1到furthest间找i+nums[i]的最大值
            int i = pwd_loc + 1;
            int max_index = i;
            int max = i + nums[i];
            for (; i <= furthest; i++)
            {
                if (i + nums[i] > max)
                {
                    max = i + nums[i];
                    max_index = i;
                }
            }
            // 修改pwd_loc
            pwd_loc = max_index;
            // 同时修改furthest
            furthest = max;
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> data = {2, 3, 1, 1, 4};
    Solution s;
    s.jump(data);
}