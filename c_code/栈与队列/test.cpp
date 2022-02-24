#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    unordered_map<int, int> iMap;
    iMap[1] = 20;
    iMap[2] = 10;
    iMap[5] = 30;
    iMap[4] = 0;

    vector<pair<int, int>> vtMap;
    for (auto it = iMap.begin(); it != iMap.end(); it++)
        vtMap.push_back(make_pair(it->first, it->second));

    sort(vtMap.begin(), vtMap.end(),
         [](const pair<int, int> &x, const pair<int, int> &y) -> int
         {
             return x.second < y.second;
         });

    for (auto it = vtMap.begin(); it != vtMap.end(); it++)
        cout << it->first << ':' << it->second << '\n';
    return 0;
}