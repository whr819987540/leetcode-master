#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

// 1、虽然有了signal但是效率还是比较低
// 这里因为不是搜索整棵树
// 所以加上返回值
// 如果返回true，则退出横向遍历
// 2、因为不会有多个备选值了，所以不需要res了
class Solution
{
public:
    vector<string> path;           // 可以多次到同一城市
    map<vector<string>, int> able; // 票数
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // 获得所有要经过的城市
        set<string> cities = passedCities(tickets);
        // 构建[from,to]->ticket_num的映射
        initFromToTicketsMap(tickets);
        // 当前所在城市
        string pwd_city = "JFK";
        // 特别注意这里，当前城市首先要放进去
        path.push_back(pwd_city);
        backtracking(tickets, cities, pwd_city);
        return path;
    }

    bool backtracking(const vector<vector<string>> &tickets, const set<string> &cities, string pwd_city)
    {
        // 到达城市数=票数+1
        if (path.size() == tickets.size() + 1)
        {
            // cout << "over" << endl;
            return true;
        }

        vector<string> from_to = {pwd_city};
        for (auto city : cities)
        {
            from_to.push_back(city);
            // 还有pwd_city到city的票
            // cout << pwd_city << "->" << city << " " << able[from_to] << endl;
            if (able[from_to])
            {
                able[from_to]--;
                path.push_back(city);
                // cout << path.size() << endl;
                // 找到路径
                if (backtracking(tickets, cities, city))
                {
                    return true;
                }
                path.pop_back();
                able[from_to]++;
            }
            from_to.pop_back();
        }
        return false;
    }

    void initFromToTicketsMap(const vector<vector<string>> &tickets)
    {
        for (auto ticket : tickets)
        {
            able[ticket]++;
        }
    }
    set<string> passedCities(const vector<vector<string>> &tickets)
    {
        set<string> cities;
        for (auto ticket : tickets)
        {
            cities.insert(ticket[0]);
            cities.insert(ticket[1]);
        }
        return cities;
    }
};