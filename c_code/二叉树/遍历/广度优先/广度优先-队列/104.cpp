// 求二叉树的最大深度

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

// 迭代-广度优先遍历
// 也就是处理的层数
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> my_queue;
        int depth = 0;
        if (root != nullptr)
        {
            my_queue.push(root);
        }

        TreeNode *p;
        int size;
        while (!my_queue.empty())
        {
            size = my_queue.size();
            for (int i = 0; i < size; i++)
            {
                p = my_queue.front();
                my_queue.pop();
                if (p->left)
                    my_queue.push(p->left);
                if (p->right)
                    my_queue.push(p->right);
            }
            depth++;
        }
        return depth;
    }
};

// 递归
class NewSolution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            return left > right ? left + 1 : right + 1;
        }
    }
};
