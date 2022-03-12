#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给若干个区间，要求删除一些区间，使得剩下的区间没有重叠
// 且要求删除的个数最少
// 返回删除区间的个数

// 先按照左边界升序、右边界升序排序
// 对于区间i，如果i+1[0]<i[1]重叠，i和i+1中至少要删除一个
// 那么删除哪一个呢？
// 应该删除右边界大的，因为右边界大，更有可能覆盖到别的区间左侧
// 再检查i+2直到，i+k[0]>=i[1]

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int num = 0;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < right)
            {
                num++;
            }
            else
            {
                right = intervals[i][1];
            }
        }
        return num;
    }
};

// 上面的问题在于，为什么要保留靠左边的呢？
// 显然不能从左遍历，因为是按照左边界递增的顺序排序
// 从左遍历，右边界可能非常大，占用很大的位置
// 比如[[1,10],[1,2],[2,3],[3,4]]
// 所以应该从右往左遍历

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int left = intervals.back()[0];
        int num = 0;
        for (int i = intervals.size() - 2; i >= 0; i--)
        {
            if (intervals[i][1] > left)
            {
                num++;
            }
            else
            {
                left = intervals[i][0];
            }
        }
        return num;
    }
};