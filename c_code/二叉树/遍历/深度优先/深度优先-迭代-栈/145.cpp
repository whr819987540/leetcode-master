// 后序遍历-迭代-栈
#include <stack>
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> my_stack;
        vector<element_type> res;
        if (root == nullptr)
        {
            return res;
        }
        // 栈初始化
        else
        {
            my_stack.push(root);
        }
        TreeNode *tmp;
        // 前序遍历的顺序是中左右
        // 后序遍历的顺序是左右中
        // 中左右->中右左->左右中
        while (!my_stack.empty())
        {
            // 取出一个结点，放入res，再将其left、right放入
            // 最后放入right，因为先处理right
            tmp = my_stack.top();
            my_stack.pop();
            res.push_back(tmp->val);

            // 注意nullptr不要放进去
            if (tmp->left)
            {
                my_stack.push(tmp->left);
            }
            if (tmp->right)
            {
                my_stack.push(tmp->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};