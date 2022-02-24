// 中序遍历-迭代-栈
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> my_stack;
        vector<element_type> res;
        // 中序遍历-左中右
        // 不停地向左遍历，栈记录遇到的结点
        // 如果不是空节点，则该节点入栈
        // 如果是空节点，栈顶为中，弹出，访问
        // 然后尝试访问右结点
        // 当栈空且结点空时，表明到了最右侧，结束
        TreeNode *p = root;
        while (true)
        {
            if (p != nullptr)
            {
                my_stack.push(p);
                p = p->left;
            }
            else if (!my_stack.empty())
            {
                p = my_stack.top();
                my_stack.pop();

                res.push_back(p->val);
                p = p->right;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};