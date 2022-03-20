#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给一个正整数数组和整数target
// 用+/-来连接所有的数，使得表达式的结果等于target
// 返回满足条件的表达式的个数
// 第一个数也可以有+/-

// 设带+数的和为pos，带-数的和为neg
// pos-neg = sum
// pos+neg = target
// 即pos*2 = target+sum
// 即pos = (target+sum)/2
// 也就是要找到和为(target+sum)/2的数
// 等价于weights=values=nums,n = (target+sum)/2

// 1、数组含义：dp[i][j]表示考虑0-i的数，背包重量为j时的最大价值
// 2、递推公式：dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]) / dp[i-1][j]
// 3、初始化：dp[0][j]=values[0] when j>=weights[0], dp[i][0]=0
// 4、遍历顺序：从小到大，从小到大

// 返回值处理
// 根据values和weights的特点，dp[i][j]<=j
// 所以要让dp[i][j] == n
// 只能考虑dp[i][n] 即最后一行
// 应该回溯最后一行中dp[i][n] == n的值
// 因为有可能递归公式max中的两项相等，那么就会产生两种方法
// 如果回溯的话，起点是最后一行中所有dp数组值等于n的单元格
// 然后返回起点到终点的所有路径
// 这样又引入了图论中的问题，变复杂了

// 1、数组含义：dp[i][j]表示考虑0-i个物品，背包重量为j时，让物品价值和达到j的方法数
// 2、递推公式：dp[i][j] = 放第i个物品（if j>=weights[i]）dp[i-1][j-weights] + 不放第i个物品 dp[i-1][j]
// 到达dp[i][j]只有两个方向，放或不放第i个物品
// 3、初始化：0初始化所有值
// j=0，dp[i][0]=1代表任何一个物品都可以选择不放使背包价值达到0
// i=0，dp[0][weights[0]]=1，恰好使重量==价值的只有一个值
// 4、遍历顺序：从小到大，从小到大
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = get_sum(nums);
        // 绝对值越界
        if (abs(target) > sum)
        {
            return 0;
        }
        // 2*pos得奇数
        else if ((sum + target) % 2)
        {
            return 0;
        }
        int n = (sum + target) / 2;
        // 0初始化所有值
        vector<vector<int>> dp(nums.size(), vector<int>(n + 1, 0));

        // 0是特殊情况，如果重量为0，放或不放都可以保证增加的价值为0
        // 而其他值，只能选择不放
        // dp[0][0] = 1 if nums[0]!=0, dp[0][0]=2 if nums[0]==0
        // dp[i][0] = dp[i-1][0] if nums[i]!=0，只能不放
        // dp[i][0] = 2*dp[i-1][0] if nums[i]==0，可以放或者不放
        for (int i = 0; i < dp.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (i == 0)
                {
                    dp[i][0] = 2;
                }
                else
                {
                    dp[i][0] = 2 * dp[i - 1][0];
                }
            }
            else
            {
                if (i == 0)
                {
                    dp[i][0] = 1;
                }
                else
                {
                    dp[i][0] = dp[i - 1][0];
                }
            }
        }
        // dp[0][weights[0]] = 1
        // 此处可能越界，如果越界，表示最大重量<0号物品重量，则不可能放入0号物品
        // 那么只考虑0号物品时，不可能让总价值==重量
        // 如[1000],-1000
        if (nums[0] <= n && nums[0] != 0) // 重量为0时，已经初始化了
        {
            dp[0][nums[0]] = 1;
        }
        // display(dp);
        // 遍历
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                // 两种方法
                if (j >= nums[i])
                {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
                // display(dp);
            }
        }
        // 考虑所有商品，且背包重量达到(sum+target)/2
        return dp[nums.size() - 1][n];
    }
    int get_sum(const vector<int> &stones)
    {
        int sum = 0;
        for (auto stone : stones)
        {
            sum += stone;
        }
        return sum;
    }

    void display(const vector<vector<int>> &data)
    {
        for (auto outer : data)
        {
            for (auto inner : outer)
            {
                cout << inner << "\t";
            }
            cout << endl;
        }
        cout << "----------\n";
    }
};

// 一维数组
// sum = x + y, x为前面将要补+的数之和，y为将要前面补-的数之和
// target = x - y，target是表达式的计算结果
// x = (sum + target) / 2
// 等价于在原数组中找到和为x的数的方法数

// nums = weights = values
// 1、数组含义：dp[j]表示可组成和为j的方法数
// 2、递推公式：dp[j] = dp[j] + dp[j - nums[i]]
// 前者为不放入nums[i]，使得和为j的方法数；后者为不放入
// 3、初始化：对于第0个物品
// 若nums[0]!=0，则dp[0] = 1（不放物品0），dp[nums[0]] = 1（放物品0）
// 若nums[0] == 0，则dp[nums[0]] = 2。实际上就是上面两种的加和
// 或者不考虑物品时，使得和为0的方法数为1，即什么都不放dp[0]=1
// 4、遍历顺序：物品递增，重量递减
// 最后返回dp[x]，表示考虑所有数字后，使和为x的方法数
class Solution2
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = get_sum(nums);
        if (abs(target) > sum) // 表达式的值越界
        {
            return 0;
        }
        else if ((target + sum) % 2) // 2*x为奇数
        {
            return 0;
        }

        int n = (target + sum) / 2;
        vector<int> dp(n + 1, 0);
        // 第一种初始化
        dp[0]++;          //表示不放入物品0
        if (nums[0] <= n) // 表示放入物品0，但0的重量可能超过最大重量，对应于下面内层for循环的条件，此时为0
        {
            dp[nums[0]]++;
        }
        // display(dp);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = n; j >= nums[i]; j--)
            {
                // 前者表示不放，后者表示放
                dp[j] = dp[j] + dp[j - nums[i]];
            }
            // display(dp);
        }
        return dp[n];
    }
    int get_sum(const vector<int> &stones)
    {
        int sum = 0;
        for (auto stone : stones)
        {
            sum += stone;
        }
        return sum;
    }
    void display(const vector<int> &data)
    {
        for (auto i : data)
        {
            cout << i << " ";
        }
        cout << "----------\n";
    }
};

// 另一种初始化方法
// 不考虑任何数字，只有让和为0才有一种方法，和为其他值都没有方法
class Solution3
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = get_sum(nums);
        if (abs(target) > sum) // 表达式的值越界
        {
            return 0;
        }
        else if ((target + sum) % 2) // 2*x为奇数
        {
            return 0;
        }

        int n = (target + sum) / 2;
        vector<int> dp(n + 1, 0);
        // 第二种初始化
        dp[0] = 1; // 不考虑任何数字，让和为0有一种方法
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = n; j >= nums[i]; j--)
            {
                // 前者表示不放，后者表示放
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[n];
    }
    int get_sum(const vector<int> &stones)
    {
        int sum = 0;
        for (auto stone : stones)
        {
            sum += stone;
        }
        return sum;
    }
    void display(const vector<int> &data)
    {
        for (auto i : data)
        {
            cout << i << " ";
        }
        cout << "----------\n";
    }
};

int main()
{
    {
        Solution s;
        vector<int> data{1, 1, 1, 1, 1};
        int res = s.findTargetSumWays(data, 3);
        cout << res << endl;
    }

    {
        Solution2 s;
        vector<int> data{1, 1, 1, 1, 1};
        int res = s.findTargetSumWays(data, 3);
        cout << res << endl;
    }

    {
        Solution3 s;
        vector<int> data{1, 1, 1, 1, 1};
        int res = s.findTargetSumWays(data, 3);
        cout << res << endl;
    }
    {
        Solution s;
        vector<int> data{7, 0, 3, 9, 9, 9, 1, 7, 2, 3};
        int res = s.findTargetSumWays(data, 6);
        cout << res << endl;
    }
    {
        Solution2 s;
        vector<int> data{7, 0, 3, 9, 9, 9, 1, 7, 2, 3};
        int res = s.findTargetSumWays(data, 6);
        cout << res << endl;
    }
    {
        Solution3 s;
        vector<int> data{7, 0, 3, 9, 9, 9, 1, 7, 2, 3};
        int res = s.findTargetSumWays(data, 6);
        cout << res << endl;
    }
}