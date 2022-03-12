#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 先排序，再从左往右遍历
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.empty())
        {
            return res;
        }
        // 按照左边界升序、右边界升序排序
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            // 存在重叠
            if (intervals[i][0] <= right)
            {
                right = max(right, intervals[i][1]);
            }
            else
            {
                res.push_back({left, right});
                left = intervals[i][0], right = intervals[i][1];
            }
        }
        // 最后一个区间，若合并，没放入；若不合并，也没放入
        res.push_back({left, right});
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> data = {{1, 4}, {4, 5}};
    vector<vector<int>> res = s.merge(data);
    for (auto outer : res)
    {
        for (auto inner : outer)
        {
            cout << inner << " ";
        }
        cout << endl;
    }
}