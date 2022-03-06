// 输出格式为["1->2->5","1->3"]

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

// 迭代，栈
// 栈中存结点，以及之前访问过的结点
class Solution
{
public:
    typedef struct record
    {
        node *p;
        vector<int> before;
    } record;
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (root == nullptr)
        {
            return res;
        }
        stack<record> my_stack;
        record tmp;
        tmp.p = root, tmp.before = {};
        my_stack.push(tmp);

        while (!my_stack.empty())
        {
            record last = my_stack.top();
            my_stack.pop();
            // 处理右孩子
            if (last.p->right)
            {
                record right;
                right.p = last.p->right;
                // 新的before应该为父结点的before+父结点的值
                right.before.assign(last.before.begin(), last.before.end());
                right.before.push_back(last.p->val);
                my_stack.push(right);
            }
            // 处理左孩子
            if (last.p->left)
            {
                record left;
                left.p = last.p->left;
                left.before.assign(last.before.begin(), last.before.end());
                left.before.push_back(last.p->val);
                my_stack.push(left);
            }
            // 如果此结点为叶子结点，则整合历史信息
            // 注意此时要加上叶子结点的自身值
            if (!last.p->left && !last.p->right)
            {
                last.before.push_back(last.p->val);
                res.push_back(process(last.before));
            }
        }
        return res;
    }
    // 将data中的int以->连接，并返回字符串
    string process(vector<int> &data)
    {
        string res = to_string(data[0]);
        for (int i = 1; i < data.size(); i++)
        {
            res = res + "->" + to_string(data[i]);
        }
        return res;
    }
};

// 递归
// 在遇到叶子结点之前，必须先处理根节点（历史信息）
// 所以用前序遍历
class Solution
{
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode *root)
    {
        res.clear();
        vector<int> history;
        history.clear();
        func(root, history);
        return res;
    }

    void func(node *root, vector<int> history)
    {
        if (root == nullptr)
        {
            return;
        }

        // 首先将当前结点值放入
        history.push_back(root->val);

        // 叶子结点
        if (!root->left && !root->right)
        {
            res.push_back(process(history));
            return;
        }

        // 处理左右子树
        if (root->left)
        {
            func(root->left, history);
        }
        if (root->right)
        {
            func(root->right, history);
        }
    }

    // 将data中的int以->连接，并返回字符串
    string process(vector<int> data)
    {
        string res = to_string(data[0]);
        for (int i = 1; i < data.size(); i++)
        {
            res = res + "->" + to_string(data[i]);
        }
        return res;
    }
};

// 递归+引用传参
// 降低空间复杂度
// 结果放到全局变量中
class Solution
{
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> history;
        res.clear();
        func(root, history);
        return res;
    }

    void func(node *root, vector<int> &history)
    {
        if (root == nullptr)
        {
            return;
        }
        // 中
        history.push_back(root->val);

        // 叶子结点
        if (!root->left && !root->right)
        {
            res.push_back(process(history));
        }
        else
        {
            // 左右
            // 特别注意此时只需要回溯一次
            // 因为只放入了根节点
            if (root->left)
            {
                func(root->left, history);
                // 回溯
                history.pop_back();
            }
            if (root->right)
            {
                func(root->right, history);
                // 回溯
                history.pop_back();
            }
        }
    }
    // 将data中的int以->连接，并返回字符串
    string process(vector<int> data)
    {
        string res = to_string(data[0]);
        for (int i = 1; i < data.size(); i++)
        {
            res = res + "->" + to_string(data[i]);
        }
        return res;
    }
};