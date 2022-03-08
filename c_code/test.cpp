#include <iostream>
#include <vector>
#include <string>
#include <strstream>
using namespace std;
int main()
{
    {
        int res;
        res = int(13 / 5);
        cout << res << endl;
        string s = "11.0";
        res = stoi(s);
        cout << res << endl;
    }

    {
        vector<int> r;
        r.push_back(1);
        r.push_back(2);
        r.pop_back();
        cout << r[0] << endl;
    }

    {
        string a = "abc"; // abc
        a.erase(a.end() - 1);
        cout << a << endl; // ab
        a.push_back('s');
        cout << a << endl; // abs
        a.pop_back();
        cout << a << endl; // ab
    }

    {
        string str = "abcdef";
        string newStr = str.substr(1, 3); //要创建新的变量接收获取的子符串   		两个参数一个起始位置 一个截取长度
        cout << newStr << endl;           //注意输出的是获取后的子字符串subStr
        cout << str << endl;
    }

    {
        string a = "11";
        int a_int = stoi(a);
        cout << a_int << endl; // 11
    }
    {
        string a = "22";
        int a_int = atoi(a.c_str());
        cout << a_int << endl; // 22
    }

    {
        strstream s;
        string a = "33";
        int a_int;
        s << a;
        s >> a_int;
        cout << a_int << endl; // 33
    }
}