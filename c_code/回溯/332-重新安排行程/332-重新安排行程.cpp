#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;



class Solution
{
public:
    vector<string> path;           // 可以多次到同一城市
    vector<vector<string>> res;    //遍历整棵树，取第一个值
    map<vector<string>, int> able; // 票数
    bool signal;                   // false表示还未找到一条path
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
        // signal初始化
        signal = false;
        backtracking(tickets, cities, pwd_city);
        return res[0];
    }

    void backtracking(const vector<vector<string>> &tickets, const set<string> &cities, string pwd_city)
    {
        // 到达城市数=票数+1
        if (path.size() == tickets.size() + 1)
        {
            res.push_back(path);
            signal = true;
            // cout << "over" << endl;
            return;
        }

        vector<string> from_to = {pwd_city};
        for (auto city : cities)
        {
            if (signal)
            {
                break;
            }
            from_to.push_back(city);
            // 还有pwd_city到city的票
            // cout << pwd_city << "->" << city << " " << able[from_to] << endl;
            if (able[from_to])
            {
                able[from_to]--;
                path.push_back(city);
                // cout << path.size() << endl;
                backtracking(tickets, cities, city);
                path.pop_back();
                able[from_to]++;
            }
            from_to.pop_back();
        }
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



int main()
{
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution s;
    // set<string> cities = s.allCities(tickets);
    // for (auto i : cities)
    // {
    //     cout << i << endl;
    // }

    vector<string> res = s.findItinerary(tickets);
    for (auto i : res)
    {
        cout << i << endl;
    }
}
