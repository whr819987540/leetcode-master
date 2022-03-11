#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

// 地点抽象为结点，
// 票抽象为边
class Solution
{
private:
    vector<vector<string>> res;
    vector<string> path; // 存放到过的城市
    // key 为票也就是两个城市组成的数组（有序），value是能否通行
    map<vector<string>, bool> able;

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // 找出所有出现过的城市并按照字典序排列
        set<string> cities = allCities(tickets);
        // 构建可行map，初始化为true，表示这两个城市可以从前者到后者
        for (auto ticket : tickets)
        {
            able[ticket] = true;
        }

        // 当前位置
        string pwd_city = "JFK";
        backtracking(tickets, cities, pwd_city);
        // cout << res.size() << endl;
        // 题目保证至少有一条路
        // 遍历整棵树会获得所有可能的结果，应该选取字典序最小的结果
        // 因为cities已经按照字典序排序了，所以res中的第一个值即为最终结果
        return res[0];
    }

    // 找到最短的即可，无需遍历整棵树，所以又返回值
    void backtracking(const vector<vector<string>> &tickets,
                      const set<string> &cities, string pwd_city)
    {
        // 终止：到过的城市数=票数+1
        if (path.size() == tickets.size() + 1)
        {
            res.push_back(path);
            // cout << "over" << endl;
            return;
        }
        vector<string> tmp = {pwd_city};
        for (auto city : cities)
        {
            tmp.push_back(city);
            // cout << pwd_city << "->" << city << " " << able[tmp] << endl;
            // 有pwd_city到city的票
            if (able[tmp] == true)
            {
                // 当前结点
                able[tmp] = false;
                path.push_back(city);
                // 递归
                backtracking(tickets, cities, city);
                // 回溯
                path.pop_back();
                able[tmp] = true;
            }
            // 更换目的地
            tmp.pop_back();
        }
    }

    set<string> allCities(const vector<vector<string>> &tickets)
    {
        set<string> my_set;
        for (auto outer : tickets)
        {
            for (auto inner : outer)
            {
                my_set.insert(inner);
            }
        }
        return my_set;
    }
};