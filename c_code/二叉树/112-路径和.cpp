// 判断是否存在一条从根节点到叶子结点的路径，使结点和等于给定值

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

// 递归
class Solution
{
public:
    // 不行，因为因为空树+0，不存在路径
    // bool hasPathSum(TreeNode *root, int targetSum)
    // {
    //     if (root == nullptr)
    //     {
    //         if (targetSum == 0)
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }

    //     return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    // }

    // 不行，因为无法保证这条路径含有叶子结点
    //  1
    // 2
    // targetSum=1
    // bool hasPathSum(TreeNode *root, int targetSum)
    // {
    //     if (root == nullptr)
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         return func(root, targetSum);
    //     }
    // }

    // bool func(TreeNode *root, int targetSum)
    // {
    //     if (root == nullptr)
    //     {
    //         if (targetSum == 0)
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }

    //     return func(root->left, targetSum - root->val) || func(root->right, targetSum - root->val);
    // }

    // 递归，关键是处理好空节点的情况
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root)
        {
            // 叶子结点
            if (!root->left && !root->right && root->val == targetSum)
            {
                return true;
            }
            // 非叶子结点或叶子结点但不满足值的条件
            else
            {
                return hasPathSum(root->left, targetSum - root->val) ||
                       hasPathSum(root->right, targetSum - root->val);
            }
        }
        // 空节点
        else
        {
            // 空节点时，targetSum为0，表示到其父结点时，满足值条件
            // 但还是继续了，表示父结点不是叶子结点
            if (targetSum == 0)
            {
                return false;
            }
            // 剩余的targetSum不为0，当然返回false
            else
            {
                return false;
            }
        }
    }
};

// 迭代
// 为了记录targetSum的历史结果，需要将某个结点时的targetSum记录下来
// 也就是栈中同时存放结点和targetSum
// 这和递归的实现也是一致的
class Solution
{
public:
    // 定义结构体来同时存放node和targetSum
    typedef struct record
    {
        node *p;
        int target;
    } record;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        stack<record> my_stack;

        if (root == nullptr)
        {
            return false;
        }
        record tmp;
        tmp.p = root, tmp.target = targetSum;
        my_stack.push(tmp);

        while (!my_stack.empty())
        {
            record tmp;
            tmp = my_stack.top();
            my_stack.pop();
            // 中
            int res = tmp.target - tmp.p->val;

            // 满足值条件且该结点为叶子结点
            if (res == 0 && !tmp.p->left && !tmp.p->right)
            {
                return true;
            }
            else
            {
                // 处理右子树
                if (tmp.p->right)
                {
                    record r;
                    r.p = tmp.p->right;
                    r.target = res;
                    my_stack.push(r);
                }
                // 处理左子树
                if (tmp.p->left)
                {
                    record r;
                    r.p = tmp.p->left;
                    r.target = res;
                    my_stack.push(r);
                }
            }
        }
        return false;
    }
};

// 采用类似所有路径的解法

// 递归-前序遍历
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 实际上这只处理了根节点为空，因为后续的逻辑可以保证空节点不进入递归
        // <0是不合理的，因为题目没说一定是正整数
        // if (root == nullptr || targetSum < 0)
        if (root == nullptr)
        {
            return false;
        }
        // 中
        targetSum = targetSum - root->val;

        // 叶子结点
        if (!root->left && !root->right)
        {
            if (targetSum == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // 左子树
        bool res = false;
        if (root->left)
        {
            res = hasPathSum(root->left, targetSum);
        }
        // 左子树不符合才检查右子树
        if (!res && root->right)
        {
            res = hasPathSum(root->right, targetSum);
        }
        return res;
    }
};