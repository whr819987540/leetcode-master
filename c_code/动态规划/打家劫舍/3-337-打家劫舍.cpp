#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
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

// 前面的后序遍历-递归超时了
// 模拟一下就可以知道，进行了很多重复计算
// 求根+四个孙子时计算孙子，求两个儿子时也会计算四个孙子
// 应该用一个map来记录某个结点的最大值（根+四个孙子或两个儿子）
// 并且因为是后序遍历，所以这个map先记录的是比较深的结点的最大值
// 可以被比较浅的结点在计算中用到
class Solution2
{
private:
    map<node *, int> my_map;

public:
    int rob(node *root)
    {
        if (root == nullptr)
        {
            my_map[root] = 0;
            return my_map[root];
        }

        // 不放根节点
        // 这一部分向下搜索，同时填充map
        int left = rob(root->left), right = rob(root->right);

        // 放根节点
        int root_val = root->val;
        // 在计算左右儿子时，四个孙子的值肯定已经计算出来并放map里面了
        if (root->left)
        {
            root_val += my_map[root->left->left] + my_map[root->left->right];
        }
        if (root->right)
        {
            root_val += my_map[root->right->left] + my_map[root->right->right];
        }

        my_map[root] = max(left + right, root_val);
        return my_map[root];
    }
};

// 更加清晰的方法是将map只放在返回值处
class Solution3
{
private:
    map<node *, int> my_map;

public:
    int rob(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // map中有记录
        if (my_map.find(root) != my_map.end())
        {
            return my_map[root];
        }

        // 不放根节点
        int left = rob(root->left), right = rob(root->right);

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

        // 保存计算结果
        my_map[root] = max(left + right, root_val);
        return my_map[root];
    }
};

// 树形动态规划
// 对树进行动态规划，本身要和树的遍历结合在一起
// 本题选择后序遍历，因为根节点的结果依赖于儿子和孙子
// 1、数组含义：dp[0]表示偷当前结点的最大值，dp[1]表示不偷当前结点的最大值
// 注意，在遍历这棵树之前，无法知道所有结点
// 所以不能像背包问题一样提前定义好一个二维数组，然后用横坐标来表示物品
// 只能将计算结果逐步通过递归的返回值送给上层结点
// 2、递推公式：
// 3、初始化：dp[0]=dp[1]=0
// 4、遍历顺序：后序遍历
class Solution4
{
public:
    int rob(node *root)
    {
        vector<int> res = postOrderTraverse(root);
        return max(res[0], res[1]);
    }

    vector<int> postOrderTraverse(node *root)
    {
        if (root == nullptr)
        {
            return {0, 0};
        }
        // 左右子树偷与不偷根节点的最大值
        vector<int> left = postOrderTraverse(root->left);
        vector<int> right = postOrderTraverse(root->right);

        // 不偷根节点，左右子树的根节点可以偷也可以不偷
        int val1 = max(left[0], left[1]) + max(right[0], right[1]);
        // 偷根节点，不能偷左右子树的根节点
        int val2 = root->val + left[0] + right[0];

        return {val1, val2};
    }
};

int main()
{
    Solution s;
}