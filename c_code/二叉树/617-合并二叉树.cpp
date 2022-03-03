// 将两颗二叉树合并
// 同位置的结点值相加
// 采用层序遍历

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

// 层序遍历
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // 对于两个结点，将他们的值相加，赋值给左侧结点
        // 对于他们的孩子，有三种情况
        // 1、都有左儿子
        // 此时左儿子都放入队列
        // 2、一个有左儿子，一个没有左儿子
        // 只需要保证左侧结点有左儿子即可
        // 3、都没有左儿子
        // 不处理
        // 对于右儿子也是这样处理
        queue<node *> my_queue;
        if (root1 == nullptr)
        {
            return root2;
        }
        if (root2 == nullptr)
        {
            return root1;
        }
        my_queue.push(root1);
        my_queue.push(root2);

        node *t1, *t2;
        while (!my_queue.empty())
        {
            t1 = my_queue.front();
            my_queue.pop();
            t2 = my_queue.front();
            my_queue.pop();
            // 结点值相加
            t1->val += t2->val;

            // 都有左儿子
            if (t1->left && t2->left)
            {
                my_queue.push(t1->left);
                my_queue.push(t2->left);
            }
            else if (t2->left)
            {
                t1->left = t2->left;
            }

            // 同样处理右儿子
            if (t1->right && t2->right)
            {
                my_queue.push(t1->right);
                my_queue.push(t2->right);
            }
            else if (t2->right)
            {
                t1->right = t2->right;
            }
        }
        return root1;
    }
};

// 前序遍历
class NewSolution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr)
        {
            return root2;
        }
        else if (root2 == nullptr)
        {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

// 后序遍历
class NewNewSolution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr)
        {
            return root2;
        }
        else if (root2 == nullptr)
        {
            return root1;
        }
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        root1->val += root2->val;
        return root1;
    }
};

// 中序遍历
class NewNewSolution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr)
        {
            return root2;
        }
        else if (root2 == nullptr)
        {
            return root1;
        }
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        root1->val += root2->val;
        return root1;
    }
};