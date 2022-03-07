// 找到所有的路径，使得从根节点到叶子结点的值之和等于给定值

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

// // 递归-前序遍历
// // 按值传参
// class Solution
// {
// public:
//     vector<vector<int>> res;
//     vector<vector<int>> pathSum(TreeNode *root, int targetSum)
//     {
//         res.clear();
//         if (root == nullptr)
//         {
//             return res;
//         }
//         vector<int> history;
//         func(root, targetSum, history);
//         return res;
//     }

//     void func(node *root, int targetSum, vector<int> history)
//     {
//         // 不会让空节点进入递归
//         // 中
//         targetSum = targetSum - root->val;
//         history.push_back(root->val);

//         // 叶子结点
//         if (!root->left && !root->right)
//         {
//             if (targetSum == 0)
//             {

//                 res.push_back(history);
//             }
//             return;
//         }

//         // 左右
//         if (root->left)
//         {
//             func(root->left, targetSum, history);
//         }
//         if (root->right)
//         {
//             func(root->right, targetSum, history);
//         }
//     }
// };

// // 递归-前序遍历
// // 引用传参-回溯
// class Solution
// {
// public:
//     vector<vector<int>> res;
//     vector<vector<int>> pathSum(TreeNode *root, int targetSum)
//     {
//         res.clear();
//         if (root == nullptr)
//         {
//             return res;
//         }
//         vector<int> history;
//         func(root, targetSum, history);
//         return res;
//     }

//     void func(node *root, int targetSum, vector<int> &history)
//     {
//         // 不会让空节点进入递归
//         // 中
//         targetSum = targetSum - root->val;
//         history.push_back(root->val);

//         // 叶子结点
//         if (!root->left && !root->right)
//         {
//             if (targetSum == 0)
//             {

//                 res.push_back(history);
//             }
//             return;
//         }

//         // 左右
//         if (root->left)
//         {
//             func(root->left, targetSum, history);
//             // 回溯
//             history.pop_back();
//         }
//         if (root->right)
//         {
//             func(root->right, targetSum, history);
//             // 回溯
//             history.pop_back();
//         }
//     }
// };

// 迭代-前序遍历
// 栈中记录结点-历史信息-targetSum
class Solution
{
public:
    typedef struct record
    {
        node *p;
        vector<int> history;
        int target;
    } record;

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        stack<record> my_stack;
        record tmp;
        tmp.p = root, tmp.history = {}, tmp.target = targetSum;
        my_stack.push(tmp);

        while (!my_stack.empty())
        {
            record tmp = my_stack.top();
            my_stack.pop();
            tmp.history.push_back(tmp.p->val);
            if (!tmp.p->left && !tmp.p->right)
            {
                if (tmp.target == tmp.p->val)
                {
                    res.push_back(tmp.history);
                }
            }

            if (!tmp.p->right)
            {
                record right;
                vector<int> vt;
                right.p = tmp.p->right;
                right.history.assign(tmp.history.begin(), tmp.history.end());
                right.target = tmp.target - tmp.p->val;
                my_stack.push(right);
            }

            if (!tmp.p->left)
            {
                record left;
                left.p = tmp.p->left;
                left.history.assign(tmp.history.begin(), tmp.history.end());
                left.target = tmp.target - tmp.p->val;
                my_stack.push(left);
            }
        }

        return res;
    }
};

int main()
{
    node *root = new node(1);
    node *p2 = new node(2);
    node *p3 = new node(3);
    root->left = p2;
    p2->left = p3;
    Solution s;
    vector<vector<int>> vt = s.pathSum(root, 6);
    for (int i = 0; i < vt.size(); i++)
    {
        for (int j = 0; j < vt[i].size(); j++)
        {
            cout << vt[i][j] << " " << endl;
        }
        cout << "-------\n";
    }
}