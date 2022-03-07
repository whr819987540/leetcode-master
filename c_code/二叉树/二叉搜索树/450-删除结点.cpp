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

// class Solution
// {
// public:
//     TreeNode *deleteNode(TreeNode *root, int key)
//     {
//         // 没找到
//         if (root == nullptr)
//         {
//             return nullptr;
//         }
//         if (root->val > key)
//         {
//             root->left = deleteNode(root->left, key);
//             return root;
//         }
//         else if (root->val < key)
//         {
//             root->right = deleteNode(root->right, key);
//             return root;
//         }
//         // 找到
//         else
//         {
//             // 左右子树都空
//             if (root->left == nullptr && root->right == nullptr)
//             {
//                 return nullptr;
//             }
//             // 一个子树为空
//             else if (root->left != nullptr && root->right == nullptr)
//             {
//                 // delete root;
//                 // return root->left;
//                 node *tmp = root->left;
//                 delete root;
//                 return tmp;
//             }
//             else if (root->left == nullptr && root->right != nullptr)
//             {
//                 node *tmp = root->right;
//                 delete root;
//                 return tmp;
//             }
//             // 都不空
//             // 将左子树放到右子树的最左节点
//             else
//             {
//                 node *p = root->right;
//                 while (p->left != nullptr)
//                 {
//                     p = p->left;
//                 }
//                 p->left = root->left;
//                 node *tmp = root->right;
//                 delete root;
//                 return tmp;
//             }
//         }
//     }
// };

// 迭代，两个指针
// 前序遍历
class Solution
{
public:
    void delete_node(node *pwd, node *pre, int key)
    {
        // 删除pwd需要知道pwd是pre的哪个儿子
        node *pos;
        // pwd是pre的右儿子
        if (key > pre->val)
        {
            pos = pre->right;
        }
        // pwd是pre的左儿子
        else
        {
            pos = pre->left;
        }

        // 需要判断pwd有无孩子
        // pwd无左右孩子
        if (!pwd->left && !pwd->right)
        {
            pos = nullptr;
        }
        // 只有左子树
        else if (pwd->left && !pwd->right)
        {
            pos = pwd->left;
        }
        // 只有右子树
        else if (!pwd->left && pwd->right)
        {
            pos = pwd->right;
        }
        // 左右子树都有
        else if (pwd->left && pwd->right)
        {
            pos = pwd->right;
            // 将左子树放到右子树的最左边
            node *p = pwd->right;
            while (p->left)
            {
                p = p->left;
            }
            p->left = pwd->left;
        }
        // 释放结点
        delete pwd;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        // 为了让操作一般化申明一个伪根节点
        node *fake_root = new node(root->val + 1);
        fake_root->left = root;

        node *pwd = root, *pre = fake_root;
        while (pwd)
        {
            // 找到
            if (key == pwd->val)
            {
                delete_node(pwd, pre, key);
                break;
            }
            // 去右子树
            else if (key > pwd->val)
            {
                pre = pwd;
                pwd = pwd->right;
            }
            // 去左子树
            else
            {
                pre = pwd;
                pwd = pwd->left;
            }
        }
        return fake_root->left;
    }
};


// 迭代-两个指针
// 对逻辑进行了优化
// 主要在于删除结点后返回这棵子树新的根结点
// 这样，判断pwd是pre哪个孩子的问题就不需要出现在删除函数中
// 函数的功能更加清晰
class Solution
{
public:
    // 删除结点，返回新节点
    node *delete_node(node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        // 没有左右孩子
        else if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        // 没有左孩子
        else if (!root->left && root->right)
        {
            node *p = root->right;
            delete root;
            return p;
        }
        // 没有右孩子
        else if (root->left && !root->right)
        {
            node *p = root->left;
            delete root;
            return p;
        }
        // 有左右孩子
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        node *pwd = root, *pre = nullptr;
        while (pwd)
        {
            // 中
            // 找到就不需要对pre赋值，因为不再往下走了
            if (pwd->val == key)
            {
                break;
            }
            else
            {
                // 更新pre
                pre = pwd;
                if (key < pwd->val)
                {
                    pwd = pwd->left;
                }
                else
                {
                    pwd = pwd->right;
                }
            }
        }
        // 退出循环时，pwd可能指向对应结点，也可能为空（没找到）

        // 判断pwd是pre的哪个孩子
        // pre
        if (pre == nullptr)
        {
            return delete_node(pwd);
        }
        else
        {
            // 左孩子
            if (pre->left == pwd)
            {
                pre->left = delete_node(pwd);
            }
            // 右孩子
            else
            {
                pre->right = delete_node(pwd);
            }
            return root;
        }
    }
};

int main()
{
    Solution s;
    node *root = new node(1);
    node *p = s.deleteNode(root, 1);
    if (!p)
    {
        cout << "null" << endl;
    }
    else
    {
        cout << p->val << endl;
    }
}