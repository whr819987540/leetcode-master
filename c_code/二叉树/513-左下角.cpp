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

// 左下角是指最底层、最左侧的结点
// 显然用层序遍历
// 迭代+队列
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<node *> my_queue;
        my_queue.push(root);
        node *most_left, *p;
        int cnt = 1;
        while (!my_queue.empty())
        {
            int tmp = 0;
            // 左下角的结点只可能是每层结点的第一个
            most_left = my_queue.front();
            while (cnt)
            {
                p = my_queue.front();
                my_queue.pop();
                cnt--;
                if (p->left)
                {
                    tmp++;
                    my_queue.push(p->left);
                }
                if (p->right)
                {
                    tmp++;
                    my_queue.push(p->right);
                }
            }
            // 下一层结点个数
            cnt = tmp;
        }
        return most_left->val;
    }
};

// 上面的cnt和tmp是为了记录某一层结点总数
// 其实没必要这样，只需要在开始遍历前，记录队列的长度即可
// 这在之前出现过
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<node *> my_queue;
        my_queue.push(root);
        node *most_left, *p;
        while (!my_queue.empty())
        {
            // 左下角的结点只可能是每层结点的第一个
            most_left = my_queue.front();
            // 记录一下队列中结点个数，即当前层结点个数
            int size = my_queue.size();
            for (int i = 0; i < size; i++)
            {
                p = my_queue.front();
                my_queue.pop();
                if (p->left)
                {
                    my_queue.push(p->left);
                }
                if (p->right)
                    my_queue.push(p->right);
            }
        }
        return most_left->val;
    }
};

// 递归实现
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        
    }
};