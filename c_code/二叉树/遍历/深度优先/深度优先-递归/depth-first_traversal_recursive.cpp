// 进行二叉树的深度优先遍历

#include <vector>
#include <iostream>
using namespace std;
typedef int element_type;

typedef struct node
{
    element_type value;
    node *left;
    node *right;
} node;

class BinaryTree
{
public:
    node *root;
    BinaryTree()
    {
        root = nullptr;
    }
    node *get_node()
    {
        node *tmp = new node;
        tmp->left = nullptr;
        tmp->right = nullptr;
        return tmp;
    }
    void preorder_traversal_recursive(node *root, vector<element_type> &res)
    {
        if (root != nullptr)
        {
            res.push_back(root->value);
            preorder_traversal_recursive(root->left, res);
            preorder_traversal_recursive(root->right, res);
        }
    }
    void inorder_traversal_recursive(node *root, vector<element_type> &res)
    {
        if (root != nullptr)
        {
            cout << root->value << endl;
            cout << root->left->value << endl;
            cout << root->right->value << endl;
            preorder_traversal_recursive(root->left, res);
            res.push_back(root->value);
            preorder_traversal_recursive(root->right, res);
        }
    }
    void postorder_traversal_recursive(node *root, vector<element_type> &res)
    {
        if (root != nullptr)
        {
            cout << root->value << endl;
            preorder_traversal_recursive(root->left, res);
            preorder_traversal_recursive(root->right, res);
            res.push_back(root->value);
        }
    }

    void display_vector(const vector<element_type> &res)
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
        // for (auto i : res)
        // {
        //     cout << i << endl;
        // }
        cout << "display over-------" << endl;
    }
};

int main()
{
    //    5
    //  4   6
    // 1 2 7 8
    BinaryTree tree;
    tree.root = tree.get_node();
    tree.root->value = 5;

    tree.root->right = tree.get_node();
    tree.root->right->value = 6;

    tree.root->right->left = tree.get_node();
    tree.root->right->left->value = 7;

    tree.root->right->right = tree.get_node();
    tree.root->right->right->value = 8;

    tree.root->left = tree.get_node();
    tree.root->left->value = 4;

    tree.root->left->left = tree.get_node();
    tree.root->left->left->value = 1;

    tree.root->left->right = tree.get_node();
    tree.root->left->right->value = 2;

    vector<element_type> res;
    tree.preorder_traversal_recursive(tree.root, res);
    tree.display_vector(res);
    res.clear();

    tree.inorder_traversal_recursive(tree.root, res);
    cout << "over\n";
    tree.display_vector(res);
    res.clear();

    tree.postorder_traversal_recursive(tree.root, res);
    cout << "over\n";
    tree.display_vector(res);
    res.clear();
}