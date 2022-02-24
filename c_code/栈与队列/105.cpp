// 逆波兰表示法
// 即算符的后缀表示法
// 一般习惯将算符写在两个运算数之间
// 而逆波兰表示法将算符写在两个运算数之后
// 栈适合对逆序的事物进行操作

// 字符换转数字，可以用sstream中的strinstream
// 也可以用stoi函数
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution
{
public:
    // 如果是数字，则入栈
    // 如果是算符，则从栈中取两个数字进行运算
    int evalRPN(vector<string> &tokens)
    {
        stack<string> my_stack;
        for (auto i : tokens)
        {
            if (isdigit(i))
            {
                my_stack.push(i);
            }
            else
            {
                int left_num, right_num;
                int res;
                // 这里注意
                // 先出栈的是右运算数
                right_num = todigit(my_stack.top());
                my_stack.pop();

                left_num = todigit(my_stack.top());
                my_stack.pop();
                // cout << left_num << i << right_num << endl;
                if (i == "+")
                {
                    res = left_num + right_num;
                    my_stack.push(tostring(res));
                }
                else if (i == "-")
                {
                    res = left_num - right_num;
                    my_stack.push(tostring(res));
                }
                else if (i == "*")
                {
                    res = left_num * right_num;
                    my_stack.push(tostring(res));
                }
                else if (i == "/")
                {
                    res = int(left_num / right_num);
                    my_stack.push(tostring(res));
                }
            }
        }
        return todigit(my_stack.top());
    }
    // 用stringstream来判断字符串是不是数字
    // 需要include头文件sstream

    int todigit(string s)
    {
        stringstream ss;
        int res;
        ss << s;
        ss >> res;
        return res;
    }
    string tostring(int value)
    {
        stringstream ss;
        string res;
        ss << value;
        ss >> res;
        return res;
    }
    bool isdigit(string s)
    {
        stringstream ss;
        int value;
        ss << s;
        // 输入成功，返回非零值;否则返回零
        if (ss >> value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// 上面的代码有点麻烦，因为频繁的进行类型转换和类型判断
// 原因在于stack里面放的是string，其实应该放int的
class NewSolution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> my_stack;
        for (auto i : tokens)
        {
            if (isdigit(i))
            {
                my_stack.push(stoi(i));
            }
            else
            {
                int right, left, res;
                right = my_stack.top();
                my_stack.pop();
                left = my_stack.top();
                my_stack.pop();

                if (i == "+")
                {
                    my_stack.push(left + right);
                }

                else if (i == "-")
                {
                    my_stack.push(left - right);
                }

                else if (i == "*")
                {
                    my_stack.push(left * right);
                }

                else if (i == "/")
                {
                    my_stack.push(left / right);
                }
            }
        }
        return my_stack.top();
    }

    bool isdigit(string s)
    {
        stringstream ss;
        int res;
        ss << s;
        if (ss >> res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    vector<string> s;
    s.push_back("4");
    s.push_back("13");
    s.push_back("5");
    s.push_back("/");
    s.push_back("+");
    // Solution test;
    // cout << test.evalRPN(s);

    NewSolution test_1;
    cout << test_1.evalRPN(s);
}