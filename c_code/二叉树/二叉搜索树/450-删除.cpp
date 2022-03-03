// 给定一个值，删除对应结点
// 要保证删除后仍然是二叉搜索树

#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
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

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 没找到
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        // 找到
        else
        {
            // 左右子树都空
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            // 一个子树为空
            else if (root->left != nullptr && root->right == nullptr)
            {
                // delete root;
                // return root->left;
                node *tmp = root->left;
                delete root;
                return tmp;
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                node *tmp = root->right;
                delete root;
                return tmp;
            }
            // 都不空
            // 将左子树放到右子树的最左节点
            else
            {
                node *p = root->right;
                while (p->left != nullptr)
                {
                    p = p->left;
                }
                p->left = root->left;
                node *tmp = root->right;
                delete root;
                return tmp;
            }
        }
    }
};
