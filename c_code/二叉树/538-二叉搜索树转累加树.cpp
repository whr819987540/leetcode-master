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

// 累加树满足：结点的新值=不小于该结点旧值的结点值之和
// 也要对该结点的旧值求和
// 观察示例，需要采用右中左的遍历顺序
// 因为最右结点不存在比他的值，取自身值即可，新值放到变量pre中
// 中结点等于自身值+pre，新值放到变量pre中
// 左结点也是如此

// 换一个考虑角度，为了实现找到不小于的值，必须进行降序排序
// 因为是二叉搜索树，所以应该右中左遍历
// 同时要记录上一个结点（即排序中相邻节点）的新值
class Solution
{
public:
    int pre;
    TreeNode *convertBST(TreeNode *root)
    {
        pre = 0;
        func(root);
        return root;
    }
    // 因为需要遍历整棵树，所以不带返回值
    void func(node *root)
    {
        // 叶子结点
        if (root == nullptr)
        {
            return;
        }
        // 右
        func(root->right);
        // 中
        root->val += pre;
        pre = root->val;
        // 左
        func(root->left);
    }
};

// 迭代-栈
class Solution
{
public:
    TreeNode *convertBST(TreeNode *root)
    {
        // 右中左
        // 类似于中序遍历
        // 指针不空，指针入栈，指向右儿子（右）
        // 指针为空，弹出栈顶元素（中），处理；然后指向左儿子
        // 当指针空且栈空时，结束
        stack<node *> node_stack;
        node *p = root;
        int pre = 0;
        while (1)
        {
            if (p == nullptr && node_stack.empty() == true)
            {
                break;
            }

            if (p != nullptr)
            {
                node_stack.push(p);
                p = p->right; // 右
            }
            else
            {
                p = node_stack.top();
                node_stack.pop(); //中
                p->val += pre;
                pre = p->val;

                p = p->left; // 左
            }
        }
        return root;
    }
};