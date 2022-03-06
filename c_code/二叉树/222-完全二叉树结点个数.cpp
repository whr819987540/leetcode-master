// 满二叉树是每层节点都达到最大值的二叉树
// 若其深度为n，则结点总数为2^n-1
// 完全二叉树是除了最下面一层外，其余层结点都达到最大值
// 且最下面一层的结点是集中分布在最左侧的，不存在间隙

// 如果是满二叉树，首先用深度优先遍历获得深度，然后带入公式
// 如果是完全二叉树
// 可以先判断是不是满二叉树，如果是，同上
// 如果不是，对左右子树递归处理获得结点数，然后+根节点
// 直到某棵子树为满二叉树

// 也可以采用迭代或递归的方法，对树进行遍历
// 但是这样就没有用到完全二叉树这个条件
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

// 层序遍历-迭代
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        queue<node *> my_queue;
        if (root == nullptr)
        {
            return 0;
        }

        int cnt = 1;
        my_queue.push(root);
        node *p;
        while (!my_queue.empty())
        {
            p = my_queue.front();
            my_queue.pop();
            cnt++;
            if (p->left)
            {
                my_queue.push(p->left);
            }
            if (p->right)
            {
                my_queue.push(p->right);
            }
        }
        return cnt;
    }
};

// 深度优先遍历-递归
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if(root==nullptr){
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// 利用完全二叉树的性质-递归
// 完全二叉树的子树
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // 最左侧的深度
        int left = 0, right = 0;
        node *p = root->left;
        while (p)
        {
            p = p->left;
            left++;
        }
        // 最右侧深度
        p = root->right;
        while (p)
        {
            p = p->right;
            right++;
        }
        if (left == right)
        {
            return pow(2, left + 1) - 1;
        }
        else
        {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};