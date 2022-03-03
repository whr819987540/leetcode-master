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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
typedef struct TreeNode node;

// 递归
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q)
        {
            return root;
        }
        // 在同侧
        else if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // 在异侧
        else
        {
            return root;
        }
    }
};

// 迭代
class NewSolution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (root->val > p->val & root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val & root->val < q->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};