// 判断括号是否匹配,(),{},[]
// 首先检验一下字符串长度是否为偶数
// 最后检查一下栈是否为空
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        // 数量不为偶数，必定无效
        if (s.size() % 2 != 0)
        {
            return false;
        }
        char tmp;
        stack<char> my_stack;
        for (int i = 0; i < s.size(); i++)
        {
            tmp = s[i];
            if (tmp == '(' || tmp == '[' || tmp == '{')
            {
                my_stack.push(tmp);
            }
            else
            {
                if (my_stack.empty())
                {
                    return false;
                }
                char left = my_stack.top();
                my_stack.pop();
                if (tmp == ')' && left != '(')
                {
                    return false;
                }
                else if (tmp == ']' && left != '[')
                {
                    return false;
                }
                else if (tmp == '}' && left != '{')
                {
                    return false;
                }
            }
        }
        // 将string扫描完后，还需要栈为空
        // if(my_stack.empty()){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return my_stack.empty();
    }
};
