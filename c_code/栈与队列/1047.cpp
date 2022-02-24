// 类似编译原理
// 如果放入的字符与栈顶元素相同，则出栈
// 任何时候再弹栈时，都要注意栈是否为空

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> my_stack;
        // 遍历字符串
        // 栈空，放入
        // 栈不空，相等，移除
        // 栈不空，不相等，放入
        for (auto c : s)
        {
            if (my_stack.empty() || c != my_stack.top())
            {
                my_stack.push(c);
            }
            else
            {
                my_stack.pop();
            }
        }
        string res = "";
        int size = my_stack.size();
        for (int i = 0; i < size; i++)
        {
            res += my_stack.top();
            my_stack.pop();
        }
        // 这里必须导入algorithm头文件
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.removeDuplicates("abbaca");
}