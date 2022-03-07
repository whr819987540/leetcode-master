#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef struct TreeNode node;

// 修剪的意思就是说，保证结点值都在某个范围之间
// 如果超出这个范围，要将相应的结点删除
// 所以这题本质上就是遍历+删除 when 结点值不符合条件
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        traversal(root, low, high);
        return root;
    }

    // 后序遍历
    // 因为要遍历整棵树，所以不需要返回值
    void traversal(node *root, int low, int high)
    {
        if (root)
        {
            // 左
            traversal(root->left, low, high);
            // 右
            traversal(root->right, low, high);
            // 中，超出范围
            if (root->val > high || root->val < low)
            {
                root = delete_node(root);
            }
        }
    }

    // 删除子树的根结点，返回新的根结点
    node *delete_node(node *root)
    {
        // 无论结构如何，将左子树挂到右子树的最左侧
        // 右子树为空
        if (!root->right)
        {
            return root->left;
        }
        else
        {
            node *p = root->right;
            while (p->left)
            {
                p = p->left;
            }
            p->left = root->left;
            p = root->right;
            delete root;
            return p;
        }
    }
};

int main()
{
    Solution s;
    node *p1 = new node(1);
    node *p0 = new node(0);
    node *p2 = new node(2);
    p1->left = p0;
    p1->right = p2;
    node *p = s.trimBST(p1, 1, 2);
    cout << p->left->val << endl;
}