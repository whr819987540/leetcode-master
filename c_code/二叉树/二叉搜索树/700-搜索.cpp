// 普通的二叉搜索
// 给一个数和一个搜索值
// 返回对应的结点

#include <queue>
#include <iostream>
#include <vector>
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

// 迭代
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        node *p = root;
        while (p)
        {
            if (p->val == val)
            {
                return p;
            }
            // 去右子树寻找
            else if (p->val < val)
            {
                p = p->right;
            }
            // 去左子树寻找
            else
            {
                p = p->left;
            }
        }
        // 没找到
        return nullptr;
    }
};

// 递归
class NewSolution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
        {
            return root;
        }
        if (root->val < val)
        {
            return searchBST(root->right, val);
        }
        else
        {
            return searchBST(root->left, val);
        }
    }
};