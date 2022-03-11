#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 输入为打乱顺序后的数组
// 每一项的第一个值表示身高，第二个值表示前面>=该身高的人数
// 要求输出数组原来的顺序，使得每一项的第二个值满足身高约束
// [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
// [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

// 应该首先根据身高较高的第二项安排位置
// 但是身高较低的优先级较高，因为将身高较低的放在左侧，不会影响第二项的正确性
// 如果被占据，应该将右侧序列集体右移
class Solution
{
private:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        // 身高降序，排名升序
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        else
        {
            return a[0] > b[0];
        }
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> res(people.size(), {0, 0});
        // 对people按照身高排序
        sort(people.begin(), people.end(), cmp);
        for (auto person : people)
        {
            int index = person[1];
            // 手写
            // 被占用
            if (res[index][0] != 0)
            {
                // 将size-2到index的所有值后移一个
                for (int i = people.size() - 2; i >= index; i--)
                {
                    // 被占用
                    if (res[i][0])
                    {
                        res[i + 1] = res[i];
                    }
                }
            }
            res[index] = person;

            // insert
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> data = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution s;
    s.reconstructQueue(data);
}