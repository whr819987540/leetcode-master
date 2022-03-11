#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// prices给出某一天的股价信息
// 要求某时只能持有
// 在任何时候最多只能持有一股股票
// 你也可以购买它，然后在同一天出售(不限制交易次数)
// 要求获得最大利润

// 上帝视角来看
// 只要明天会跌，今天肯定不买
// 只要明天会涨，今天肯定买，然后明天卖掉
// 然后立足明天，后天涨，明天会继续买
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i + 1] > prices[i])
            {
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};