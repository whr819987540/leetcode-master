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

// 定义两个栈，栈的初始值相同
// 同时执行相反的操作
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        stack<node *> left, right;
        node *left_node, *right_node;
        left.push(root), right.push(root);
        while (!left.empty())
        {
            left_node = left.top();
            left.pop();
            right_node = right.top();
            right.pop();
            // 检查结点值
            if (left_node->val != right_node->val)
            {
                return false;
            }
            if (left_node->left)
            {
                if (right_node->right)
                {
                    left.push(left_node->left);
                    right.push(right_node->right);
                }
                else
                {
                    return false;
                }
            }
            if (left_node->right)
            {
                if (right_node->left)
                {
                    left.push(left_node->right);
                    right.push(right_node->left);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// 定义两个栈，栈的初始值不能相同
// 同时执行相反的操作
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        stack<node *> left, right;
        node *left_node, *right_node;
        left.push(root->left), right.push(root->right);
        while (!left.empty())
        {
            left_node = left.top();
            left.pop();
            right_node = right.top();
            right.pop();
            // 同时为空
            if (!left_node && !right_node)
            {
                continue;
            }
            // 同时不为空
            else if (left_node && right_node)
            {
                if (left_node->val != right_node->val)
                {
                    return false;
                }
                else
                {
                    left.push(left_node->left), right.push(right_node->right);
                    left.push(left_node->right), right.push(right_node->left);
                }
            }
            // 一个空，一个不空
            else
            {
                return false;
            }
        }
        // 因为push和pop都是成对的操作
        // 所以退出循环时，两个栈肯定都为空
        return true;
    }
};

// 错误的递归
// 重大错误，不能递归进入左右子树，因为此时无法看到另一侧的内容
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        // 左右子树都存在
        if (root->left && root->right)
        {
            // 递归处理左右子树
            if (root->left->val == root->right->val)
            {
                return isSymmetric(root->left) && isSymmetric(root->right);
            }
            else
            {
                return false;
            }
        }
        // 左右子树都不存在
        else if (!root->left && !root->right)
        {
            return true;
        }
        // 存在一个子树
        else
        {
            return false;
        }
    }
};

// 递归
// 吸取上面的教训，应该同时传入两个要比较的根节点作为参数
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return func(root->left, root->right);
    }
    bool func(node *left, node *right)
    {
        // 左右都存在
        if (left && right)
        {
            if (left->val == right->val)
            {
                return func(left->left, right->right) && func(left->right, right->left);
            }
            else
            {
                return false;
            }
        }
        // 左右都不存在
        else if (!left && !right)
        {
            return true;
        }
        // 存在一颗子树
        else
        {
            return false;
        }
    }
};