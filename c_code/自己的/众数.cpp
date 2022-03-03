#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // map找到频率，key-value放到vector中排序
    // 找到所有频率等于最大频率的项
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    vector<int> usingMap(vector<int> sample)
    {
        map<int, int> my_map;
        vector<pair<int, int>> my_vt;
        vector<int> res;
        // map统计频率
        for (auto i : sample)
        {
            my_map[i]++;
        }
        // key-value入vector
        for (auto i : my_map)
        {
            my_vt.push_back(pair<int, int>(i.first, i.second));
        }
        // 对value排序
        sort(my_vt.begin(), my_vt.end(), cmp);

        res.push_back(my_vt[0].first);
        for (int i = 1; i < my_vt.size() && my_vt[i].second == my_vt[0].second; i++)
        {
            res.push_back(my_vt[i].first);
        }
        return res;
    }

    // 先排序
    // 在一次遍历中，设置count和maxCount
    vector<int> usingDoubleCount(vector<int> sample)
    {
        // 排序
        sort(sample.begin(), sample.end());
        vector<int> res;
        res.push_back(sample[0]);
        int count = 1, maxCount = 1;
        for (int i = 1; i < sample.size(); i++)
        {
            if (sample[i] == sample[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count == maxCount)
            {
                res.push_back(sample[i]);
            }
            else if (count > maxCount)
            {
                res.clear();
                res.push_back(sample[i]);
                maxCount = count;
            }
        }
        return res;
    }

    // 排序
    // 第一次遍历找到最大的频率
    // 第二次遍历找到频率==最大频率的
    vector<int> usingDoubleTraverse(vector<int> sample)
    {
        sort(sample.begin(), sample.end());
        int count = 1, maxCount = 1;
        // 第一次遍历
        for (int i = 1; i < sample.size(); i++)
        {
            if (sample[i] == sample[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            maxCount = maxCount > count ? maxCount : count;
        }
        // 第二次遍历
        vector<int> res;
        count = 1;
        int i = 0;
        for (int i = 1; i < sample.size(); i++)
        {
            if (count == maxCount)
            {
                res.push_back(sample[i - 1]);
            }
            if (sample[i - 1] == sample[i])
            {
                count++;
            }
            else
            {
                count = 1;
            }
        }
        if (count == maxCount)
        {
            res.push_back(sample[sample.size()-1]);
        }
        return res;
    }
    void display(vector<int> r)
    {
        for (auto i : r)
        {
            cout << i << endl;
        }
        cout << "-----------\n";
    }
};

int main()
{
     vector<int> sample = {1, 3, 5, 3, 6, 4, 3, 2, 1, 4, 5, 1};
    // vector<int> sample = {1, 2, 1, 2};
    //vector<int> sample = {1, 2};
    Solution s;
    vector<int> res;
    res = s.usingMap(sample);
    s.display(res);

    res = s.usingDoubleCount(sample);
    s.display(res);

    res = s.usingDoubleTraverse(sample);
    s.display(res);
}