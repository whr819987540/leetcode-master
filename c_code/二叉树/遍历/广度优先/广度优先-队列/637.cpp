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
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> res;
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
        // sum取int可能溢出
        double sum;
        TreeNode *tmp;
        while (!my_queue.empty())
        {
            size = my_queue.size();
            sum = 0;
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
                sum += tmp->val;
            }
            res.push_back(sum / size);
        }
        return res;
    }
};