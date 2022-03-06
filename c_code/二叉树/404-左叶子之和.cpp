// 求所有左叶子结点之和
// 左叶子是一个结点的左孩子，且该结点是叶子结点（没有左右孩子）

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

class Solution
{
public:
    // 迭代+栈
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        stack<node *> my_stack;
        my_stack.push(root);
        int res = 0;
        node *p;
        // 类似前序遍历，顺序无所谓
        while (!my_stack.empty())
        {
            p = my_stack.top();
            my_stack.pop();
            if (p->left && p->left->left == nullptr && p->left->right == nullptr)
            {
                res += p->left->val;
            }
            else if (p->left)
            {
                my_stack.push(p->left);
            }
            if (p->right)
            {
                my_stack.push(p->right);
            }
        }
        return res;
    }
};

class NewSolution
{
public:
    // 递归
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int res = 0;
        // 处理左子树
        if (root->left)
        {
            // 左子树是叶子结点
            if (root->left->left == nullptr && root->left->right == nullptr)
            {
                res += root->left->val;
            }
            // 递归处理左子树
            else
            {
                res += sumOfLeftLeaves(root->left);
            }
        }
        // 处理右子树
        // 右子树不需要考虑是不是叶子结点，直接处理
        res += sumOfLeftLeaves(root->right);
        return res;
    }
};

class NewNewSolution
{
public:
    // 递归
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int res = 0;
        // 左子树
        res += sumOfLeftLeaves(root->left);
        // 右子树
        res += sumOfLeftLeaves(root->right);
        // 根节点
        if (root->left && root->left->left == nullptr && root->left->right == nullptr)
        {
            res += root->left->val;
        }
        return res;
    }
};