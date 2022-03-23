#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 给定两个整数数组
// 返回他们公共数组的最大长度
// 公共数组应该连续
// nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
// Output: 3

// 1、数组含义：dp[i][j]表示第一个数组以i结尾、第二个数组以j结尾时的公共子数组的最长长度
// 2、递推公式：如果nums1[i]!=nums2[j]则dp[i][j]=0,否则dp[i][j]=dp[i-1][j-1]+1
// 3、初始化：dp[0][j]=1 if nums1[0]==nums2[j],dp[i][0]=1 if nums1[i]==nums2[0]
// 4、遍历顺序：递增，递增
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int max_length = 0;

        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums2[j] == nums1[0])
            {
                dp[0][j] = 1;
                max_length = 1;
            }
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == nums2[0])
            {
                dp[i][0] = 1;
                max_length = 1;
            }
        }

        for (int i = 1; i < nums1.size(); i++)
        {
            for (int j = 1; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max_length = max(max_length, dp[i][j]);
                }
            }
        }
        return max_length;
    }
};

int main()
{
    {
        Solution s;
        vector<int> nums1{1, 2, 3, 2, 1}, nums2{3, 2, 1, 4, 7};
        cout << s.findLength(nums1, nums2) << endl;
    }

    {
        Solution s;
        vector<int> nums1{0, 0, 0, 0}, nums2{0, 0, 0, 7};
        cout << s.findLength(nums1, nums2) << endl;
    }
}