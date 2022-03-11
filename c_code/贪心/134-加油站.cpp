#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// gas[i]表示第i个加油站的油，cost[i]表示从第i到i+1个加油站的耗油量
// 显然，gas[i]-cost[i]即为从i到i+1剩余的油量

// class Solution
// {
// public:
//     int canCompleteCircuit1(vector<int> &gas, vector<int> &cost)
//     {
//         vector<int> res;
//         for (int i = 0; i < gas.size(); i++)
//         {
//             res.push_back(gas[i] - cost[i]);
//         }

//         // 暴力
//         for (int start = 0; start < res.size(); start++)
//         {
//             int remained = 0;
//             int end;
//             for (int cnt = 0; cnt < res.size(); cnt++)
//             {
//                 end = (start + cnt) % res.size();
//                 remained += res[end];
//                 if (remained < 0)
//                 {
//                     break;
//                 }
//             }
//             if (remained >= 0)
//             {
//                 return start;
//             }
//         }
//     }
// };

// // for+while（环形遍历）
// class Solution
// {
// public:
//     int canCompleteCircuit2(vector<int> &gas, vector<int> &cost)
//     {
//         vector<int> res;
//         for (int i = 0; i < gas.size(); i++)
//         {
//             res.push_back(gas[i] - cost[i]);
//         }

//         // 二重循环
//         for (int i = 0; i < res.size(); i++)
//         {
//             int remain = res[i];
//             int j = (i + 1) % res.size();
//             // j!=i表示未完成环形遍历
//             while (remain >= 0 && j != i)
//             {
//                 remain += res[j];
//                 j = (j + 1) % res.size();
//             }
//             // 完成环形遍历
//             if (remain >= 0 && j == i)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// 贪心
class Solution
{
public:
    int canCompleteCircuit3(vector<int> &gas, vector<int> &cost)
    {
        int total = 0, res = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            cout << res << endl;
            total += (gas[i] - cost[i]);
            res += (gas[i] - cost[i]);
            // 累加和出现复制，应该更新起点
            // start会不会越界
            // 当i已经到gas.size()-1时，如果res还是负，则start=gas.size()
            // 显然此时start越界了
            // 但是由于到最后，res还是负值，前面若干个子区间的和也为负值（只有出现负值才会更新res）
            // 那么total必然也为负，返回-1，所以start不会越界
            if (res < 0)
            {
                res = 0;
                start = i + 1;
            }
        }
        // 检查有没有解
        if (total >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution s;
    s.canCompleteCircuit3(gas, cost);
}