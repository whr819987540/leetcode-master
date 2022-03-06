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
} node;

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

// 递归-后序遍历
// 实际上是处理高度
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

// 递归-前序遍历
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        max_depth = 0;
        getDepth(root, 1);
        return max_depth;
    }

    int max_depth;
    // 遍历，传入参数为结点+该节点的深度
    // 为什么能这样传参？因为根节点的深度是已知的
    void getDepth(node *root, int depth)
    {
        // 空结点不更新最大值
        if (root == nullptr)
        {
            return;
        }
        // 当前结点的处理就是更新max_depth
        max_depth = depth > max_depth ? depth : max_depth;
        // 处理左右孩子，前序遍历
        // 当前结点的深度为depth，左右孩子的深度为depth+1,或者不更新（为空时）
        getDepth(root->left, depth + 1);
        getDepth(root->right, depth + 1);
    }
};
