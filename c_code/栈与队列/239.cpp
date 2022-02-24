#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

// 暴力解法
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        for (int start = 0; start <= nums.size() - k; start++)
        {
            res.push_back(get_max(nums, start, start + k));
        }
        return res;
    };
    int get_max(vector<int> &nums, int start, int end)
    {
        int max = nums[start];
        for (int i = start; i < end; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
        }
        return max;
    }
};

void display(vector<int> &v)
{
    for (auto c : v)
    {
        cout << c << endl;
    }
}

// 单调队列
// 随着窗口的移动
// 移出，如果移出的元素等于之前窗口的最大值，则移除队首元素
// 移入，遍历队列的值，因为队列中的值都是靠左的位置，如果移入元素大于这些值，
// 则这些值永远不会成为窗口的最大值，放心移除即可

// 首先实现单调队列
class MyQueue
{
public:
    deque<int> myqueue;
    // 从窗口中移除某个元素
    void pop(int a)
    {
        if (a == myqueue.front())
        {
            myqueue.pop_front();
        }
    }
    // 向窗口中移入某个元素
    void push(int a)
    {
        // 需要删除所有比a小的元素，从后面开始
        while (!myqueue.empty() && myqueue.back() < a)
        {
            myqueue.pop_back();
        }
        // 将a放到最后
        myqueue.push_back(a);
    }

    int front()
    {
        return myqueue.front();
    }
};
class NewSolution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        MyQueue q;
        // 先用第一个窗口的值初始化，此时只有push操作
        for (int i = 0; i < k; i++)
        {
            q.push(nums[i]);
        }
        res.push_back(q.front());

        // 处理后续窗口
        for (int i = 0; i < nums.size() - k; i++)
        {
            q.pop(nums[i]);
            q.push(nums[i + k]);
            res.push_back(q.front());
        }
        return res;
    }
};
int main()
{
    vector<int> data = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;

    vector<int> res = s.maxSlidingWindow(data, 3);
    display(res);
}