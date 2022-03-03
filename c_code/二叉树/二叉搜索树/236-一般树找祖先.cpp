// 对于一个根结点
// 如果一个结点在左子树或者就是根节点，一个结点在右子树或者就是根节点，则根节点即为所求
// 如果两个节点在同一颗子树，则去该子节点寻找

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
        else if (find(root->left, p) && find(root->left, q))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (find(root->right, p) && find(root->right, q))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // 在异侧
        else
        {
            return root;
        }
    }

    bool find(TreeNode *root, TreeNode *p)
    {
        if (root == p)
        {
            return true;
        }
        else
        {
            if (root == nullptr)
            {
                return false;
            }
            else
            {
                return find(root->left, p) || find(root->right, p);
            }
        }
    }
};

// 后序遍历
class NewSolution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // pq中某一个为根节点，则根节点即为祖先
        if (root == p || root == q || root == nullptr)
        {
            return root;
        }
        // left有两种情况
        // 如果为空，表明左子树中没有pq
        // 如果不为空，可能是左子树中有p或q的一个，也可能是左子树中找到pq的祖先
        node *left = lowestCommonAncestor(root->left, p, q);
        node *right = lowestCommonAncestor(root->right, p, q);
        // 都不空，只能是pq位于两侧，所以root是祖先
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        // 左侧没有pq，右侧不为空，则右侧有祖先
        else if (left == nullptr && right != nullptr)
        {
            return right;
        }
        else if (left != nullptr && right == nullptr)
        {
            return left;
        }
        // 两侧都没有pq
        else
        {
            return nullptr;
        }
    }
};