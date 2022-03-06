// 求n叉树的最大深度
// 递归
// 迭代（层序遍历）

#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// 层序遍历
class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<Node *> my_queue;
        my_queue.push(root);

        Node *p;
        int depth = 0;
        while (!my_queue.empty())
        {
            int size = my_queue.size();
            for (int i = 0; i < size; i++)
            {
                p = my_queue.front();
                my_queue.pop();
                // 处理所有孩子结点
                for (auto i : p->children)
                {
                    my_queue.push(i);
                }
            }
            depth++;
        }
        return depth;
    }
};

// 递归
class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        vector<int> depth;
        // 递归处理所有子节点的深度
        for (auto p : root->children)
        {
            depth.push_back(maxDepth(p));
        }
        // 取最大值
        // 可能没有子节点
        if (depth.empty())
        {
            return 1;
        }
        else
        {
            return *max_element(depth.begin(), depth.end()) + 1;
        }
    }
};