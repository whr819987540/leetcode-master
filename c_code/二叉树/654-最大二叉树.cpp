// 最大二叉树的构建过程是：
// 首先在数组中找到最大的元素，然后用左侧元素构建左子树，右侧元素构建右子树
// 显然这是一个递归定义

#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
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

// 递归+复制vector
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        // 找到最大值
        vector<int>::iterator max = max_element(nums.begin(), nums.end());
        node *root = new node(*max);
        // 划分左右数组
        vector<int> left, right;
        left.assign(nums.begin(), max);
        right.assign(max + 1, nums.end());
        // 构建左右子树
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};

// 递归+索引vector
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        return func(nums, 0, nums.size());
    }

    node *func(vector<int> &nums, int start, int end)
    {
        if (start >= end)
        {
            return nullptr;
        }
        // 首先找到最大值的索引
        int max = nums[start], index = start;
        for (int i = start + 1; i < end; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i], index = i;
            }
        }
        // 根节点
        node *root = new node(max);
        // 左右子树
        root->left = func(nums, start, index);
        root->right = func(nums, index + 1, end);
        return root;
    }
};