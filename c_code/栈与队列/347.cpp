// 从元素个数为n的数组中选出个数前k高的元素
// 可以用map来实现，元素为key，次数为value
// 然后对values来排序

// 这个题目可以引申到获取前k大元素的题目上

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 对map按照value进行排序
        // 然后取前k个pair的value

        // 统计出现次数
        map<int, int> my_map;
        for (auto c : nums)
        {
            my_map[c]++;
        }

        // 将map的kv转成pair放入vector容器
        vector<pair<int, int>> tmp_sort;
        for (auto i = my_map.begin(); i != my_map.end(); i++)
        {
            tmp_sort.push_back(make_pair(i->first, i->second));
        }

        // 对value排序
        // sort(tmp_sort.begin(), tmp_sort.end(), cmp);
        sort(tmp_sort.begin(), tmp_sort.end(),
             [](const pair<int, int> &x, const pair<int, int> &y) -> int
             { return x.second > y.second; });

        // 得到统计结果
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(tmp_sort[i].first);
        }
        return res;
    }

    int cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

// 上面将map装成vector进行快速排序，是nlogn的时间复杂度
// 排序这一步，因为只要k个值，可以用大小为k的小顶堆
// 保证堆的元素是前k个最大的值
// 这样的时间复杂度是nlogk
class NewSolution
{

public:
    // 用于构建最小堆
    class cmp
    {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y)
        {
            return x.second > y.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // map统计出现次数
        map<int, int> my_map;
        for (auto i : nums)
        {
            my_map[i]++;
        }

        // 定义一个最小堆
        // 第一个参数是元素类型，第二个参数是底层容器的数据类型
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;
        // 扫描map，并保持最小堆的大小为k
        for (auto i : my_map)
        {
            // 先插入，最小堆会自动调整元素的位置
            min_heap.push(i);
            // 超过数量，弹出最小的元素
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }

        // 输出最小堆的元素
        // 定义一个大小为k的vector
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = min_heap.top().first;
            min_heap.pop();
        }
        return res;
    }
};

int main()
{
    // map<int, int> my_map;
    // cout << my_map[0] << endl;
    // my_map[1]++;
    // cout << my_map[1] << endl;
    Solution s;
    vector<int> i = {3, 3, 3, 2, 2, 2, 2, 1};
    vector<int> res = s.topKFrequent(i, 2);
    // for (auto i = res.begin(); i != res.end();i++){
    //     cout << *i << endl;
    // }
    return 0;
}