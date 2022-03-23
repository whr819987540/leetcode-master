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

// 压缩为一维数组
// 注意递推公式dp[i][j] = dp[i - 1][j - 1] + 1;
// 下一行在计算时用到前一行的第j-1个值
// 可以考虑压缩为一维数组然后递减遍历
// 为什么可行？因为不会用到当前一行的值
// 1、数组含义：dp[j+1]表示第二个数组以j结尾时，公共子数组的最长长度
// 2、递推公式：如果nums1[i]!=nums2[j]则dp[j+1]=0(这里不同于二维数组，必须显式置零),否则dp[j+1]=dp[j]+1
// 3、初始化：dp[0]=0
// 4、遍历顺序：递减
class Solution2
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int max_length = 0;
        // 这里要补上一个0，防止越界
        vector<int> dp(nums2.size() + 1, 0);
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = nums2.size() - 1; j >= 0; j--)
            {
                if (nums2[j] == nums1[i])
                {
                    // 因为dp前面补了一个0
                    dp[j + 1] = dp[j] + 1;
                    max_length = max(max_length, dp[j + 1]);
                }
                // 这里是一维数组和二维数组的区别
                // 一维数组如果遇到nums1[i]!=nums2[j]，应该将dp[j+1]显式置零
                // 不能让上一行的值代替本行的值，因为以nums1[i]和nums2[j]结尾的数组，最后一个值不相同
                // 而二维数组不需要重复利用一块空间，所以不需要显式置零（因为都初始化为0）
                else
                {
                    dp[j + 1] = 0;
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

    {
        Solution2 s;
        vector<int> nums1{1, 0, 0, 0, 1};
        vector<int> nums2{1, 0, 0, 1, 1};
        cout << s.findLength(nums1, nums2) << endl;
    }
}