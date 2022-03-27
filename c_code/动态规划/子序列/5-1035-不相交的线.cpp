#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定两个整数数组nums1、nums2
// 将他们按照数组的顺序分别横放在两个水平线上
// 从两个数组中国分别选取两个值，如果这两个值相同，且连线不会和已有连线相交，则连接这两个值
// 并且，只能从一个数上引出一条线
// 最后返回线的最大条数

// 1、数组含义：dp[i][j]表示考虑第i、j个数时，最大的条数
// 2、递推公式：if(nums1[i]==nums2[j]) dp[i][j]=dp[i-1][j-1]，此时肯定不会冲突
// else dp[i][j]=max(dp[i][j-1],dp[i-1][j])
// 3、初始化：0，越界，所以行列都增加一个单位
// 4、遍历顺序：递增，递增
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp.back().back();
    }
};

int main()
{
    {
        Solution s;
        vector<int> nums1 = {1, 2, 4}, nums2 = {1, 4, 2};
        cout << s.maxUncrossedLines(nums1, nums2) << endl;
    }

    {
        Solution s;
        vector<int> nums1 = {2, 5, 1, 2, 5}, nums2 = {10, 5, 2, 1, 5, 2};
        cout << s.maxUncrossedLines(nums1, nums2) << endl;
    }
}