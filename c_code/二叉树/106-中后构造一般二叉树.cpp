// 根据中序和后序遍历的结果构造一个二叉树

#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
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
// 递归+拷贝
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0)
        {
            return nullptr;
        }
        // inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
        // 首先根据后序遍历的最后一个元素确定根节点
        // 然后将中序遍历的结果划分成左右子树

        // 后序遍历的最后一个元素即为根节点
        node *root = new node(postorder.back());

        // 找到根节点在中序遍历中的位置
        vector<int>::iterator index = find(inorder.begin(), inorder.end(), postorder.back());

        // 划分出左子树对应的中序、后续遍历结果
        vector<int> new_inorder_left, new_postorder_left;
        new_inorder_left.assign(inorder.begin(), index);
        new_postorder_left.assign(postorder.begin(), postorder.begin() + new_inorder_left.size());

        // 划分出右子树对应的中序、后续遍历结果
        vector<int> new_inorder_right, new_postorder_right;
        new_inorder_right.assign(index + 1, inorder.end());
        new_postorder_right.assign(postorder.begin() + new_inorder_left.size(), postorder.end() - 1);

        // 递归得到相应的左右子树
        root->left = buildTree(new_inorder_left, new_postorder_left);
        root->right = buildTree(new_inorder_right, new_postorder_right);
        return root;
    }
};
// 上面的解法很清晰，但是有个问题，就是在递归的过程中，需要频繁进行vector的切片操作
// 空间复杂度比较高
// 注意到题目中给的是引用，其实题目是想让我们直接用下标来进行访问，保证较小的空间复杂度

// 递归+索引
class NewSolution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return func(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    // 包括左侧但不包括右侧
    // inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    node *func(vector<int> &inorder, int inorder_left, int inorder_right, vector<int> postorder, int postorder_left, int postorder_right)
    {
        if (inorder_left == inorder_right)
        {
            return nullptr;
        }
        // 根据后序遍历获得根节点
        node *root = new node(postorder[postorder_right - 1]);
        // 找到根节点在中序遍历中的下标
        int index = find(inorder, inorder_left, inorder_right, postorder[postorder_right - 1]);
        // 左子树
        // 左子树长度
        int left_length = index - inorder_left;
        root->left = func(inorder, inorder_left, index, postorder, postorder_left, postorder_left + left_length);

        // 右子树
        // 右子树长度
        int right_length = inorder_right - index - 1;
        root->right = func(inorder, index + 1, inorder_right, postorder, postorder_left +left_length,postorder_right-1);
        return root;
    }
    int find(vector<int> &vt, int left, int right, int data)
    {
        for (int i = left; i < right; i++)
        {
            if (vt[i] == data)
            {
                return i;
            }
        }
    }
};

int main()
{
    // test vector find and copy
    vector<int> test = {1, 2, 3, 4, 5, 6};
    // find
    // first,second 从first开始到second，不包括second
    // 如果找到返回指向该元素的迭代器
    int target;
    target = 3;
    vector<int>::iterator it = find(test.begin(), test.end(), target);
    cout << *it << endl;
    // 如果没有找到，返回相应vector.end()
    target = 7;
    it = find(test.begin(), test.end(), target);
    if (it == test.end())
    {
        cout << "not found " << 7 << endl;
    }

    // 划分成左右两侧
    // vector.assign(start,end)
    // 从start迭代器开始移植到end，将这些所有元素复制到vector中
    // 同样的，包括start指向的元素，不包括end指向的元素
    vector<int> left, right;
    left.assign(test.begin(), it);
    for (auto i : left)
    {
        cout << "left" << i << endl;
    }

    right.assign(it + 1, test.end());
    for (auto i : right)
    {
        cout << "right" << i << endl;
    }
}