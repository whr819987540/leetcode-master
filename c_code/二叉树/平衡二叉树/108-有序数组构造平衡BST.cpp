// 输入是一个升序排列的数组
// 构造一棵高度平衡的二叉搜索树
// 为了保持高度平衡，从数组中选取中间值作为根节点
// 左子数组去构建左子树，右子数组构建右子树

#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <string>
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

// 递归-引用传参-索引
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return func(nums, 0, nums.size());
    }
    // 取下标为(start+end)/2的值作为中间值
    node *func(vector<int> &nums, int start, int end)
    {
        if (start >= end)
        {
            return nullptr;
        }
        int mid_index = (start + end) / 2;
        int mid_value = nums[mid_index];
        // 根
        node *root = new node(mid_value);
        // 左
        root->left = func(nums, start, mid_index);
        root->right = func(nums, mid_index + 1, end);
        return root;
    }
};

// 递归-按值传参-复制
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        vector<int> tmp;
        tmp.assign(nums.begin(), nums.end());
        return func(tmp);
    }
    node *func(vector<int> nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        int mid_index = nums.size() / 2;
        int mid_value = nums[mid_index];
        node *root = new node(mid_value);

        vector<int> left, right;
        left.assign(nums.begin(), nums.begin() + mid_index);
        right.assign(nums.begin() + mid_index + 1, nums.end());
        root->left = func(left);
        root->right = func(right);
        return root;
    }
};

// 迭代
// 栈中存放根节点以及区间的左右位置
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        stack<node *> node_stack;           // 存放结点
        stack<int> left_stack, right_stack; // 存放区间的左右边界
        node *root = new node;
        node_stack.push(root), left_stack.push(0), right_stack.push(nums.size());

        node *p;
        int left, right;
        while (!node_stack.empty())
        {
            p = node_stack.top();
            node_stack.pop();
            left = left_stack.top();
            left_stack.pop();
            right = right_stack.top();
            right_stack.pop();
            // 根
            int mid_index = (right - left) / 2 + left;
            int mid_value = nums[mid_index];
            p->val = mid_value;

            // 右
            if (right > mid_index + 1)
            {
                node *tmp = new node;
                p->right = tmp;
                node_stack.push(tmp), left_stack.push(mid_index + 1), right_stack.push(right);
            }
            else
            {
                p->right = nullptr;
            }

            // 左
            if (left < mid_index)
            {
                node *tmp = new node;
                p->left = tmp;
                node_stack.push(tmp), left_stack.push(left), right_stack.push(mid_index);
            }
            else
            {
                p->left = nullptr;
            }
        }
        return root;
    }
};