#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> queue_a;
    queue<int> queue_b;
    MyStack()
    {
    }

    void push(int x)
    {
        if (!queue_b.empty())
        {
            queue_b.push(x);
        }
        else
        {
            queue_a.push(x);
        }
    }
    int move(queue<int> &first, queue<int> &second)
    {
        int tmp;
        while (1)
        {
            tmp = first.front();
            first.pop();
            // 空了，表明是最后一个元素，即栈顶
            if (first.empty())
            {
                return tmp;
            }
            else
            {
                second.push(tmp);
            }
        }
    }
    int pop()
    {
        int res;
        if (!queue_b.empty())
        {
            // 将b的元素移动到a中，同时返回b的最后一个元素
            res = move(queue_b, queue_a);
        }
        else
        {
            // 将a的元素移动到b中，同时返回a的最后一个元素
            res = move(queue_a, queue_b);
        }
        return res;
    }

    int top()
    {
        // 与pop的区别在于，还要将返回的元素放到新的队列汇总
        int res;
        if (!queue_b.empty())
        {
            // 将b的元素移动到a中，同时返回b的最后一个元素
            res = move(queue_b, queue_a);
            queue_a.push(res);
        }
        else
        {
            // 将a的元素移动到b中，同时返回a的最后一个元素
            res = move(queue_a, queue_b);
            queue_b.push(res);
        }
        return res;
    }

    bool empty()
    {
        if (queue_a.empty() && queue_b.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// 上面用到了两个队列
// 但根据原理，push，放到队尾
// pop、peek只需要获得队尾即栈顶元素即可
// 所以可以通过循环队列来实现，从头开始pop
// 第queue.size()-1即为所求
class NewMyStack
{
public:
    queue<int> my_queue;
    NewMyStack()
    {
    }
    bool empty()
    {
        return my_queue.empty();
    }
    void push(int x)
    {
        my_queue.push(x);
    }
    int get_last_value()
    {
        int length = my_queue.size();
        int tmp;
        for (int i = 0; i < length - 1; i++)
        {
            tmp = my_queue.front();
            my_queue.pop();
            my_queue.push(tmp);
        }
        tmp = my_queue.front();
        my_queue.pop();
        return tmp;
    }
    int pop()
    {
        return get_last_value();
    }
    int top()
    {
        int tmp = get_last_value();
        my_queue.push(tmp);
        return tmp;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */