#include <queue>
#include <vector>
using namespace std;
typedef int element_type;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        // 填充next域
        // 层序遍历每层结点时，记录第一个结点即可
        queue<Node *> my_queue;
        if (root != nullptr)
        {
            my_queue.push(root);
        }

        int size;
        Node *before, *next;
        while (!my_queue.empty())
        {
            size = my_queue.size();

            // 处理第一个结点
            before = my_queue.front();
            my_queue.pop();
            if (before->left)
            {
                my_queue.push(before->left);
            }
            if (before->right)
            {
                my_queue.push(before->right);
            }

            for (int i = 0; i < size - 1; i++)
            {
                next = my_queue.front();
                my_queue.pop();
                before->next = next;

                before = next;
                if (before->left)
                {
                    my_queue.push(before->left);
                }
                if (before->right)
                {
                    my_queue.push(before->right);
                }
            }
            before->next = nullptr;
        }
        return root;
    }
};

// 在处理头结点时，不是很简洁，有很多重复代码
class NewSolution
{
public:
    Node *connect(Node *root)
    {
        // 填充next域
        // 层序遍历每层结点时，记录第一个结点即可
        queue<Node *> my_queue;
        if (root != nullptr)
        {
            my_queue.push(root);
        }

        int size;
        Node *before, *next;
        while (!my_queue.empty())
        {
            size = my_queue.size();
            for (int i = 0; i < size; i++)
            {
                // i=0时，处理头结点
                if (i == 0)
                {
                    before = my_queue.front();
                }
                else
                {
                    next = my_queue.front();
                    before->next = next;
                    before = next;
                }
                my_queue.pop();

                if (before->left)
                {
                    my_queue.push(before->left);
                }
                if (before->right)
                {
                    my_queue.push(before->right);
                }
            }
            before->next = nullptr;
        }
        return root;
    }
};