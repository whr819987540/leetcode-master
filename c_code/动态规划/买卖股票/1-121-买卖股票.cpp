#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定prices，prices[i]表示该股票第i天的价格
// 只能进行一次买卖
// 返回最大获利，如果不能获利，返回0

// 不能单纯的求最大值和最小值，最大值要出现在最小值后面
// 遍历并记录此时的最小值，遍历并记录此时的值与最小值的差
// 这样可以保证最小值比最大值先出现
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX;
        int max_profit = 0;
        // 在遍历过程中不断修正最小值和最大利润
        // 即使左侧有更大的值，也不能再用了
        for (auto price : prices)
        {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};

// 暴力解法，两层循环
// 用两层循环来控制最大值和最小值的顺序
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                max_profit = max(max_profit, prices[j] - prices[i]);
            }
        }
        return max_profit;
    }
};

int main()
{
    Solution s;
}