// 实现二叉树的广度优先遍历/层序优先遍历

#include <queue>
#include <vector>
using namespace std;
typedef int element_type;
typedef struct TreeNode
{
    element_type val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
} TreeNode;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> my_queue;
        vector<vector<element_type>> res;
        int node_num;
        if (root != nullptr)
        {
            my_queue.push(root);
            node_num = 1;
        }
        else
        {
            return res;
        }

        // 层序遍历
        // 遇到一个结点，记录value
        // left、right分别进队列
        // 这里需要注意的是，根据返回值的特点可以发现
        // 每层的value需要单独放到一个vector里
        TreeNode *p;
        while (!my_queue.empty())
        {
            vector<element_type> tmp;
            int next_node_num = 0;
            while (node_num--)
            {
                p = my_queue.front();
                my_queue.pop();
                if (p->left)
                {
                    my_queue.push(p->left);
                    next_node_num++;
                }
                if (p->right)
                {
                    my_queue.push(p->right);
                    next_node_num++;
                }
                tmp.push_back(p->val);
            }
            node_num = next_node_num;
            res.push_back(tmp);
        }
        return res;
    }
};

// 还有一个更加简洁的写法
class NewSolution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> my_queue;
        vector<vector<element_type>> res;
        if (root == nullptr)
        {
            return res;
        }
        else
        {
            my_queue.push(root);
        }
        int size;
        TreeNode *tmp;
        while (!my_queue.empty())
        {
            // 用一个单独的变量来记录初始时队列的长度
            // 即为当前层结点的个数
            size = my_queue.size();
            vector<element_type> tmp_res;
            for (int i = 0; i < size; i++)
            {
                tmp = my_queue.front();
                my_queue.pop();

                if (tmp->left)
                {
                    my_queue.push(tmp->left);
                }
                if (tmp->right)
                {
                    my_queue.push(tmp->right);
                }
                tmp_res.push_back(tmp->val);
            }
            res.push_back(tmp_res);
        }
        return res;
    }
};