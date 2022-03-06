// 判断一棵树是不是平衡二叉树
// 平衡二叉树应该保证任意结点左右子树的高度差不超过1
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

// 递归
// 首先要求一颗树的高度
// 高度是根节点到叶子结点的最长路径
class Solution
{
public:
    //  错误，不应该是根节点的左右子树之差不超过1
    // 而应该是所有结点的左右子树之差都不超过1
    // bool isBalanced(TreeNode *root)
    // {
    //     if (root == nullptr)
    //     {
    //         return true;
    //     }
    //     // 左右子树的高度差小于1
    //     else
    //     {
    //         return abs(getDepthRecursion(root->left) - getDepthRecursion(root->right)) <= 1;
    //     }
    // }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        // 左右子树的高度差小于1
        else
        {
            // 当前结点左右子树的高度差
            bool pwd = (abs(getDepthRecursion(root->left) - getDepthRecursion(root->right)) <= 1);
            // 递归处理孩子结点
            bool left = isBalanced(root->left);
            bool right = isBalanced(root->right);
            return pwd && left && right;
        }
    }

    // 递归求树的高度-后序遍历
    int getDepthRecursion(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return max(getDepthRecursion(root->left), getDepthRecursion(root->right)) + 1;
    }

    // 迭代求树的高度，也就是层序遍历时的层数
    int getDepthRecursion(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<node *> my_queue;
        int cnt = 0;
        my_queue.push(root);
        node *p;
        while (!my_queue.empty())
        {
            int size = my_queue.size();
            for (int i = 0; i < size; i++)
            {
                p = my_queue.front();
                my_queue.pop();
                if (p->left)
                {
                    my_queue.push(p->left);
                }
                if (p->right)
                {
                    my_queue.push(p->right);
                }
            }
            cnt++;
        }
        return cnt;
    }
};

// 上面代码的问题：
// 1、递归嵌套
// 2、并不是后序遍历，也就是说用的不是高度，而是深度
// 3、做了重复工作，如果根节点的左右子树高度差大于1，没有必要再检查左右子树了
// 这里用后序遍历
class Solution
{
public:
    // 用了-1这个标记，就只需要一层递归
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) != -1;
    }
    // 返回树的高度
    // -1表示子树高度差超过1
    int getHeight(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // 左
        int left_height = getHeight(root->left);
        // 检查左子树是不是二叉平衡树
        if (left_height == -1)
        {
            return -1;
        }

        // 右
        int right_height = getHeight(root->right);
        // 检查右子树是不是二叉平衡树
        if (right_height == -1)
        {
            return -1;
        }

        // 中
        // 不是二叉平衡树
        if (abs(right_height - left_height) > 1)
        {
            return -1;
        }
        // 是，返回高度
        else
        {
            return max(right_height, left_height) + 1;
        }
    }
};