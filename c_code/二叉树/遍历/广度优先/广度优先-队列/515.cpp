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
    vector<int> largestValues(TreeNode *root)
    {
        vector<element_type> res;
        queue<TreeNode *> my_queue;
        if (root == nullptr)
        {
            return res;
        }
        else
        {
            my_queue.push(root);
        }

        int size, max_val;
        TreeNode *tmp;
        while (!my_queue.empty())
        {
            size = my_queue.size();
            // 最大值初始化
            tmp = my_queue.front();
            my_queue.pop();
            max_val = tmp->val;
            if (tmp->left)
            {
                my_queue.push(tmp->left);
            }
            if (tmp->right)
            {
                my_queue.push(tmp->right);
            }

            // 继续比较
            for (int i = 0; i < size - 1; i++)
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
                if (tmp->val > max_val)
                {
                    max_val = tmp->val;
                }
            }
            res.push_back(max_val);
        }
        return res;
    }
};

// 上面关于max的初始化以及比较过程不是很简洁
// 可以直接将max初始化为相应类型的最小值
class NewSolution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<element_type> res;
        queue<TreeNode *> my_queue;
        if (root == nullptr)
        {
            return res;
        }
        else
        {
            my_queue.push(root);
        }

        int size, max_val;
        TreeNode *tmp;
        while (!my_queue.empty())
        {
            size = my_queue.size();
            // 最大值初始化
            max_val = INT_MIN;

            // 继续比较
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
                max_val = tmp->val > max_val ? tmp->val : max_val;
            }
            res.push_back(max_val);
        }
        return res;
    }
};