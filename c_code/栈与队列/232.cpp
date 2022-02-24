#include <stack>
#include <iostream>
using namespace std;

// 这个思路是采用两个栈
// 一个模拟队尾，一个模拟队首
// 缺点是，当push和pop交叉时，需要移动栈中所有的元素
class MyQueue
{
public:
    // a的栈顶类似队列尾
    stack<int> stack_a;
    // b的栈顶类似队列头
    stack<int> stack_b;
    MyQueue()
    {
    }
    // 将栈a的元素移动到栈b中
    void move(stack<int> &a, stack<int> &b)
    {
        while (!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
    }

    void push(int x)
    {
        // 如果b不空，则移动元素到a
        move(stack_b, stack_a);
        // while (!stack_b.empty())
        // {
        //     stack_a.push(stack_b.top());
        //     stack_b.pop();
        // }
        stack_a.push(x);
    }

    int pop()
    {
        int res = peek();
        stack_b.pop();
        return res;
    }

    int peek()
    {
        // 先将a中的元素放到b中
        move(stack_a, stack_b);
        int res = stack_b.top();
        return res;
    }

    bool empty()
    {
        if (stack_a.empty() && stack_b.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class NewMyQueue
{
public:
    // a作为输入栈
    stack<int> stack_a;
    // b作为输出栈
    stack<int> stack_b;
    NewMyQueue()
    {
    }

    void push(int x)
    {
        stack_a.push(x);
    }
    int pop()
    {
        int res = peek();
        stack_b.pop();
        return res;
    }
    int peek()
    {
        // 输出栈为空，应该从输入栈取数据
        if (stack_b.empty())
        {
            while (!stack_a.empty())
            {
                stack_b.push(stack_a.top());
                stack_a.pop();
            }
        }
        return stack_b.top();
    }
    bool empty()
    {
        if (stack_a.empty() && stack_b.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 **/
