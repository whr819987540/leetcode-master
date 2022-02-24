// 用迭代+栈来实现二叉树的深度优先遍历
#include <vector>
using namespace std;

typedef int element_type;
typedef struct node
{
    element_type val;
    node *left, *right;
    node() : left(nullptr), right(nullptr) {}
    node(element_type x) : val(x), left(nullptr), right(nullptr) {}
    node(element_type x, node *left, node *right) : val(x), left(left), right(right) {}
} node;

class BinaryTree
{
public:
    // 前序遍历
    vector<element_type> preorder_traverse(node *root)
    {
        vector<element_type> res;
        preorder_traverse_func(root, res);
        return res;
    }
    void preorder_traverse_func(node *root, vector<element_type> &res)
    {
    }

    // 中序遍历
    vector<element_type> inorder_traverse(node *root)
    {
        vector<element_type> res;
        inorder_traverse_func(root, res);
        return res;
    }
    void inorder_traverse_func(node *root, vector<element_type> &res)
    {
    }

    // 后序遍历
    vector<element_type> postorder_traverse(node *root)
    {
        vector<element_type> res;
        postorder_traverse_func(root, res);
        return res;
    }
    void postorder_traverse_func(node *root, vector<element_type> &res)
    {
    }
};

int main()
{
    return 0;
}