#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 所有屋子构成一棵二叉树
// 要求偷盗某个结点后，不能再偷盗它的子节点
// 返回偷盗的最大总价值
//      3
//    |   |
//    4   5
//   | |   |
//   1 3   1
// 结果为4+5=9

typedef struct TreeNode node;
// 涉及到的是父子节点，考虑从下往上，也就是后序遍历
// 对于根节点，如果不放，那么结果就是两个子树的和
// 如果放，那么结果就是两个子树左右孩子的和
// 最后取最大值
class Solution
{
public:
    int rob(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        // 不放根节点
        int left = rob(root->left);   //左子树
        int right = rob(root->right); //右子树

        // 放根节点
        int root_val = root->val;
        if (root->left)
        {
            root_val += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right)
        {
            root_val += rob(root->right->left) + rob(root->right->right);
        }
        return max(root_val, left + right);
    }
};

int main()
{
    Solution s;
}