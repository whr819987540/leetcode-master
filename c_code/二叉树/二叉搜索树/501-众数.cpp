// 修改二叉搜索树的定义
// 根节点的值大于等于左子树所有值，小于等于右子树所有值
// 求众数
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef struct TreeNode node;

// 递归，中序遍历，得到不递减序列
// 求次数，排序输出
// class Solution
// {
// public:
//     vector<int> res;
//     void inorderTraverse(node *root)
//     {
//         if (root)
//         {
//             inorderTraverse(root->left);
//             res.push_back(root->val);
//             inorderTraverse(root->right);
//         }
//     }
//     vector<int> findMode(TreeNode *root)
//     {
//         // 遍历
//         res.clear();
//         inorderTraverse(root);

//         vector<int> vt;
//         int maxTimes = 1, tmpMaxTimes = 1;
//         if (res.size() == 1)
//         {
//             return res;
//         }
//         vt.push_back(res[0]);
//         for (int i = 1; i < res.size(); i++)
//         {
//             if (res[i] == res[i - 1])
//             {
//                 tmpMaxTimes++;
//             }
//             else
//             {
//                 if (tmpMaxTimes == maxTimes)
//                 {
//                     vt.push_back(res[i - 1]);
//                 }
//                 else if (tmpMaxTimes > maxTimes)
//                 {
//                     vt.clear();
//                     vt.push_back(res[i - 1]);
//                 }
//                 tmpMaxTimes = 1;
//             }
//         }
//         // 只有当最后两个元素相等时，才需要继续处理
//         if (res[res.size() - 1] == res[res.size() - 2])
//         {
//             // tmpMaxTimes是res[i-1]这个元素出现的次数
//             if (tmpMaxTimes == maxTimes)
//             {
//                 vt.push_back(res[res.size() - 1]);
//             }
//             else if (tmpMaxTimes > maxTimes)
//             {
//                 vt.clear();
//                 vt.push_back(res[res.size() - 1]);
//             }
//         }
//         return vt;
//         // 有序数组找众数，最好以后面一个元素为基准来遍历
//     }
// };

// 上面的结构不好，处理很混乱
class Solution
{
public:
    vector<int> res;
    void inorderTraverse(node *root)
    {
        if (root)
        {
            inorderTraverse(root->left);
            res.push_back(root->val);
            inorderTraverse(root->right);
        }
    }
    // 不应该将比较结点的值和比较次数的逻辑放到一起
    vector<int> findMode(TreeNode *root)
    {
        res.clear();
        // 遍历出一个非递减数组
        inorderTraverse(root);
        // 在数组中找众数
        vector<int> vt;
        int count = 1, maxCount = 1;
        // 处理第一个元素
        vt.push_back(res[0]);

        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] == res[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count == maxCount)
            {
                vt.push_back(res[i]);
            }
            else if (count > maxCount)
            {
                maxCount = count;
                vt.clear();
                vt.push_back(res[i]);
            }
        }
        // 对于最后一个元素
        return vt;
    }
};