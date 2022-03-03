// 翻转一颗二叉树

#include <vector>
#include <queue>
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

// 迭代-队列-层序遍历
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        queue<TreeNode *> my_queue;
        if (root != nullptr)
        {
            my_queue.push(root);
        }

        while (!my_queue.empty())
        {
            TreeNode *p = my_queue.front();
            my_queue.pop();
            if (p->left)
                my_queue.push(p->left);
            if (p->right)
                my_queue.push(p->right);
            TreeNode *tmp;
            tmp = p->left;
            p->left = p->right;
            p->right = tmp;
        }
        return root;
    }
};

// 递归-前序
class Solution1
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
    }
};
// 递归-后序
class Solution2
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
    }
};
// 迭代-栈-前序
class Solution3
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
    }
};
// 迭代-栈-后序
class Solution4
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
    }
};