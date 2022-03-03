// 求二叉树的最小深度

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
// 如果某个结点的左右孩子都是null，该节点为叶子结点
// 即返回深度
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
        else
        {
            return 0;
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
                // 找到叶子结点
                if (p->left == nullptr && p->right == nullptr)
                {
                    return depth + 1;
                }
            }
            depth++;
        }
        return 0;
    }
};

// 递归
class NewSolution
{
public:
    int minDepth(TreeNode *root)
    {
        // 空节点
        if (root == nullptr)
        {
            return 0;
        }
        // 叶子结点
        else if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        else
        {
            int min_depth = INT_MAX;
            // 处理左子树
            if (root->left)
            {
                min_depth = min(min_depth, minDepth(root->left));
            }
            // 处理右子树
            if (root->right)
            {
                min_depth = min(min_depth, minDepth(root->right));
            }
            return min_depth + 1;
        }
    }
};
