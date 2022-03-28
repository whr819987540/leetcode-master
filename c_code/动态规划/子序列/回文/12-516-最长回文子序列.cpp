#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 1、数组含义：dp[i]表示
// 2、递推公式：
// 3、初始化：
// 4、遍历顺序：
class Solution
{

public:
    void display_matrix(const vector<vector<int>> &dp)
    {
        for (auto inner : dp)
        {
            for (auto outer : inner)
            {
                cout << outer << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    {
        Solution s;
    }
}