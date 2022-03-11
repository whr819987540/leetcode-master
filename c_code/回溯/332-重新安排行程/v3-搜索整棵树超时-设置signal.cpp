#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;


// 上面的代码可以得出正确结果，但是由于搜索了整棵树
// 所以会超时
// 这里设置一个signal，一旦出现path，就停止纵向和横向遍历
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