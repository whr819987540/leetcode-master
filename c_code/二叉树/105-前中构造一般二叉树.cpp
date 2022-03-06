// 根据前序中序遍历结果还原一颗二叉树
// 前序确定根节点位置，中序确定左右子树

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

// 递归+复制vector
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.size() == 0)
        {
            return nullptr;
        }
        // 根节点
        node *root = new node(preorder.front());
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder.front());

        // 划分左右子树的中序遍历结果
        vector<int> left_inorder, right_inorder;
        left_inorder.assign(inorder.begin(), it);
        right_inorder.assign(it + 1, inorder.end());

        // 划分左右子树的前序遍历结果
        vector<int> left_preorder, right_preorder;
        left_preorder.assign(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
        right_preorder.assign(preorder.end() - right_inorder.size(), preorder.end());

        // 左右子树
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};

// 递归+索引vector
class NewSolution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return func(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    node *func(vector<int> &preorder, int begin_preorder, int end_preorder,
               vector<int> &inorder, int begin_inorder, int end_inorder)
    {
        if (begin_inorder == end_inorder)
        {
            return nullptr;
        }
        // 根节点
        node *root = new node(preorder[begin_preorder]);
        // 根节点在中序遍历的位置
        int index = find(inorder, begin_inorder, end_inorder, preorder[begin_preorder]);
        // 左子树长度
        int left_length = index - begin_inorder;
        // 右子树长度
        int right_length = end_inorder - index - 1;
        root->left = func(preorder, begin_preorder + 1, begin_preorder + 1 + left_length, inorder, begin_inorder, index);
        root->right = func(preorder, end_preorder - right_length, end_preorder, inorder, index + 1, end_inorder);
        return root;
    }
    int find(vector<int> &vt, int left, int right, int val)
    {
        for (int i = left; i < right; i++)
        {
            if (vt[i] == val)
            {
                return i;
            }
        }
        return 0;
    }
};
