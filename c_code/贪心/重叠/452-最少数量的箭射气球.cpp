#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给出气球的直径区间，返回最少箭的数量，使得所有气球都被射爆
// 首先对气球按照左边界升序排序，右边界升序排序
// 检查第i+1个气球的左边界
// 如果在第i个左右边界之间，表明有重叠
// 因为第i个气球肯定是要被射爆的，所以需要将他们一起射爆
// 位置为这两个气球右边界的最小值
// 然后检查后面气球是否包括这个位置，如果在，同时被射爆

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        for (auto outer : points)
        {
            for (auto inner : outer)
            {
                cout << inner << " ";
            }
            cout << endl;
        }
        int num = 0;
        int pos;
        for (int i = 0; i < points.size(); i++)
        {
            if (i + 1 < points.size() && points[i + 1][0] >= points[i][0] && points[i + 1][0] <= points[i][1])
            {
                // 右边界的最小值为发射位置
                pos = min(points[i][1], points[i + 1][1]);
                // 检查还可能被射中的气球
                i += 2;
                while (i < points.size() && pos >= points[i][0] && pos <= points[i][1])
                {
                    i++;
                }
                // 此时i指向射不了的气球，应该回退
                i--;
            }
            num++;
        }
        return num;
    }
};

// 上面的逻辑有错误
// 备选射击位置为i的右边界
// 如果i+1的左边界在i的左边界和备选射击位置的范围内，取i+1的右边界和射击位置的最小值作为备选的射击位置
// 如果i+2的左边界也在i的左边界和备选射击位置的范围内，取i+2的右边界和设计位置的最小值作为备选的射击位置
// 这样能保证i被射中，且射击位置最靠左侧
// 而后续气球的左边界都在i的左边界-设计位置的范围内，所以后续气球也能被射中

// [[1,9],[7,16],[2,5],[7,12],[9,11],[2,10],[9,16],[3,9],[1,3]]
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
        {
            return 0;
        }
        sort(points.begin(), points.end()); // 升序
        int pos = points[0][1];             // start的右边界作为备选位置
        int num = 1;
        for (int i = 1; i < points.size(); i++)
        {
            // i的左边界应该<=pos（设计位置)
            if (points[i][0] <= pos)
            {
                // 更新射击位置，继续搜索
                pos = min(pos, points[i][1]);
            }
            else
            {
                num++;
                pos = points[i][1];
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> data = {{1, 9}, {7, 16}, {2, 5}, {7, 12}, {9, 11}, {2, 10}, {9, 16}, {3, 9}, {1, 3}};
    int res = s.findMinArrowShots(data);
    cout << res << endl;
}