// 只插入，不需要保持平衡

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

class Solution
{
public:
    // 关键是处理结点数为0的情况
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        node *insert = new node(val);
        // 空树
        if (root == nullptr)
        {
            return insert;
        }

        node *p = root;
        while (true)
        {
            if (p->val > val)
            {
                if (p->left == nullptr)
                {
                    p->left = insert;
                    break;
                }
                else
                {
                    p = p->left;
                }
            }
            else if (p->val < val)
            {
                if (p->right == nullptr)
                {
                    p->right = insert;
                    break;
                }
                else
                {
                    p = p->right;
                }
            }
        }
        return root;
    }
};

// 还是迭代
// 上面是在循环中检查孩子结点是否为空
// 如果为空就可以插入了
// 这里记录父结点。找到插入点后，就可以找到插入点的父结点
class NewSolution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        node *insert = new node(val);
        // 空树
        if (root == nullptr)
        {
            return insert;
        }

        node *child = root;
        node *parent = root;
        while (child)
        {
            parent = child;
            if (child->val > val)
            {
                child = child->left;
            }
            else
            {
                child = child->right;
            }
        }
        if (parent->val > val)
        {
            parent->left = insert;
        }
        else
        {
            parent->right = insert;
        }
        return root;
    }
};

// 递归实现
class NewNewSolution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new node(val);
        }
        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else if (root->val < val)
        {

            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};