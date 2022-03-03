#include <queue>
#include <iostream>
#include <vector>
#include <stack>
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

// 递归（定义与性质混淆）
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        // 不能只检查根节点与左右儿子
        // 而要检查根节点和左右子树
        if (root->left && root->left->val >= root->val)
        {
            return false;
        }
        if (root->right && root->right->val <= root->val)
        {
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};

// 正确的递归
// 定义要保证左子树的所有元素都比根小，右子树的所有元素都比根大
// 如果进行中序遍历，则元素值保持递增
// 可以用一个数组记录遍历结果
class RightSolution
{
public:
    vector<int> res;
    void inorderTraverse(node *root)
    {
        if (root)
        {
            inorderTraverse(root->left);
            res.push_back(root->val);
            inorderTraverse(root->right);
        }
    }
    bool isValidBST(TreeNode *root)
    {
        res.clear();
        inorderTraverse(root);
        for (int i = 0; i < res.size() - 1; i++)
        {
            if (res[i] >= res[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

// 在上面的基础上，用迭代来实现中序遍历，可以不用数组
class NewSolution
{
public:
    bool isValidBST(TreeNode *root)
    {
        stack<node *> my_stack;
        node *p = root, *pre = nullptr;

        while (p!=nullptr || my_stack.empty() != true)
        {
            if (p)
            {
                my_stack.push(p);
                p = p->left;
            }
            else
            {
                p = my_stack.top();
                my_stack.pop();
                if (pre && pre->val >= p->val)
                {
                    return false;
                }
                pre = p;
                p = p->right;
            }
        }
        return true;
    }
};