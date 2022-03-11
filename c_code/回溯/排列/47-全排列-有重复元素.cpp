#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 给定一个数组，可能有重复元素
// 输出其全排列
// 因为有重复元素，所以可以对数组排序
// [1,1,2,3]
// [1,1,2,3],[1,2,1,3],[1,2,3,1],
// [1,1,3,2],[1,3,1,2],[1,3,2,1],
// [1,2,1,3],[2,1,1,3],[2,1,3,1],
// [1,2,3,1],[2,1,3,1],[2,3,1,1],
// [1,3,1,2],[3,1,1,2],[3,1,2,1],
// [1,3,2,1],[3,1,2,1],[3,2,1,1]

// 横向遍历不重复，纵向遍历不重复使用一个元素
// 前面采用map来记录，这里换一下，使用bool数组
// 两种方法是等价的

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    bool *record;
    void backtracking(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            // cout << "over" << endl;
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 逻辑炸弹。1,1,2先选1，然后第一个1由于用过，不能选，第二个1由于重复不能选

            // // 没用过(纵向），不和左侧元素重复（横向）
            // if (record[i] || i != 0 && nums[i] == nums[i - 1])
            // {
            //     cout << "continue:"<<i<<" " << nums[i] << endl;
            //     continue;
            // }

            // 没用过(纵向），不和左侧元素重复（横向）
            // 注意要分开纵向和横向

            // 如果用过当然不能再用（纵向）
            if (record[i])
            {
                continue;
            }
            // 如果和前面的相同且前面的没被用（也就是在进行横向遍历），不能再用
            if (i != 0 && nums[i] == nums[i - 1] && record[i - 1] == false)
            {
                continue;
            }

            // cout << nums[i] << endl;
            // 当前结点
            path.push_back(nums[i]);
            record[i] = true;
            // 递归
            backtracking(nums);
            // 回溯
            record[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // false初始化record
        res.clear(), path.clear(), record = new bool[nums.size()]();
        sort(nums.begin(), nums.end());
        backtracking(nums);
        return res;
    }
};
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
}
int main()
{
    vector<int> data = {1, 1, 2};
    Solution s;
    vector<vector<int>> res = s.permuteUnique(data);
    display(res);
}