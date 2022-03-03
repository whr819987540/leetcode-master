#include <queue>
#include <vector>
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
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        queue<Node *> my_queue;
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        else
        {
            my_queue.push(root);
        }
        int size;
        Node *p;
        while (!my_queue.empty())
        {
            // 当前层结点个数
            size = my_queue.size();
            vector<int> tmp_res;
            for (int i = 0; i < size; i++)
            {
                p = my_queue.front();
                my_queue.pop();
                // 当前结点值
                tmp_res.push_back(p->val);
                // 当前结点的子节点
                for (auto i : p->children)
                {
                    my_queue.push(i);
                }
            }
            res.push_back(tmp_res);
        }
        return res;
    }
};