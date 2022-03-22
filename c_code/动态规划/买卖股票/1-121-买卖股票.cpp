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
class Solution2
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

// 动态规划
// 1、数组含义：dp[i][0]表示第i天持有股票时股票的买入价格（可能是今天买的，也可能是之前买的）
// dp[i][1]表示第i天不持有股票（可能是i-1天也不持有，也可能是今天卖的）时的获利
// 2、递推公式：dp[i][0] = min(dp[i-1][0], prices[i])
// 前者表示i-1天已经持有(历史买入价格)，后者表示今天买入(当前买入价格)，选择小的
// dp[i][1] = max(dp[i-1][1], prices[i]-dp[i][0])（获利高）
// 3、初始化：dp[0][0]=prices[0],dp[0][1]=0
// 4、遍历顺序：先持有然后不持有
// 先遍历天数
class Solution3
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = min(dp[i - 1][0], prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] - dp[i][0]);
        }
        return dp.back()[1];
    }
};
int main()
{
    Solution s;
}