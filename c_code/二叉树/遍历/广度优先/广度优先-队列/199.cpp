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
    vector<int> rightSideView(TreeNode *root)
    {
        // 对于每一层的结点，只有遍历到最后一个结点时，
        // 才将其放到结果中
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
        int size;
        TreeNode *tmp;
        while (!my_queue.empty())
        {
            size = my_queue.size();
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
            }
            res.push_back(tmp->val);
        }
        return res;
    }
};