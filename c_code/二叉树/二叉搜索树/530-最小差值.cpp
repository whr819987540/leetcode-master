// 可以采用中序遍历得到一个递增数组
// 然后分别计算差值，取最小差值
// 也可以不得到递增数组，在遍历过程中就比较出最小差值

#include <queue>
#include <iostream>
#include <vector>
#include <stack>
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

// 递归，中序遍历，数组
class Solution
{
public:
    vector<int> res;
    void inorderTraverse(TreeNode *root)
    {
        if (root)
        {
            inorderTraverse(root->left);
            res.push_back(root->val);
            inorderTraverse(root->right);
        }
    }
    int getMinimumDifference(TreeNode *root)
    {
        // 得到中序遍历结果
        res.clear();
        inorderTraverse(root);
        int minDiff = INT_MAX;
        for (int i = 0; i < res.size() - 1; i++)
        {
            int tmp = abs(res[i] - res[i + 1]);
            minDiff = tmp < minDiff ? tmp : minDiff;
        }
        return minDiff;
    }
};

// 迭代，中序遍历，直接比较
class NEWSolution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        int minDiff = INT_MAX;
        // error:node *p = root, *pre;
        // 因为pre指针没有初始化，可能指向一个危险的区域
        // 实际上通过debug发现该指针确实指向一个低地址0x0018
        node *p = root, *pre = nullptr;
        stack<node *> my_stack;
        while (p != nullptr || my_stack.empty() != true)
        {
            if (p)
            {
                my_stack.push(p);
                p = p->left;
            }
            else
            {
                p = my_stack.top();
                my_stack.pop();
                if (pre)
                {
                    minDiff = min(minDiff, p->val - pre->val);
                }
                pre = p;
                p = p->right;
            }
        }
        return minDiff;
    }
};

int main()
{
    NEWSolution s;
    node *root = new node(1);
    node *p3 = new node(3);
    node *p2 = new node(2);
    root->right = p3;
    root->left = p2;
    // root->right = p3;
    // p3->left = p2;
    int res = s.getMinimumDifference(root);
    cout << res << endl;
}