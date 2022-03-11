#include <iostream>
#include <vector>
#include <string>
#include <strstream>
#include <map>
#include <set>
#include <list>
using namespace std;

void start()
{
    int i;
    cout << i << endl;
}

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

    {
        map<int, bool> m;
        cout << m[1] << endl;
    }

    {
        // 动态数组申请
        bool *record;
        // 用()时，会对数组元素用简单类型的默认值进行初始化
        record = new bool[5]();
        for (int i = 0; i < 5; i++)
        {
            cout << record[i] << " ";
        }
        cout << endl; // 0 0 0 0 0

        // 不用()，不会初始化
        record = new bool[5];
        for (int i = 0; i < 5; i++)
        {
            cout << record[i] << " ";
        }
        cout << endl; // 0 40 95 2 0
    }

    {
        if ("abc" < "abd")
        {
            cout << "<" << endl;
        }
    }

    {
        set<int> s; //创建一个int类型的set

        s.insert(10); //插入数据
        s.insert(30);
        s.insert(20);
        s.insert(40);

        //遍历数据，用迭代器遍历数据
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        {
            cout << *it << endl;
        }
    }

    {
        int i;
        cout << i << endl;
        start();
    }

    {
        cout << "-----------\n";
        vector<int> res(4, 0);
        cout << "capacity:" << res.capacity() << endl;
        res.insert(res.begin() + 1, 1);
        cout << "capacity:" << res.capacity() << endl;
        for (auto i : res)
        {
            cout << i << endl;
        }
    }

    {
        cout << "--------------" << endl;
        list<int> res = {1, 2};
        list<int>::iterator p = res.begin();
        for (int i = 0; i < 4; i++)
        {
            p++;
        }
        res.insert(p, 3);
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    {
        cout << "-----------\n";
        vector<int> res(4, 0);
        cout << "capacity:" << res.capacity() << endl; // 只执行到这里
        res.insert(res.begin() + 4, 1);
        cout << "capacity:" << res.capacity() << endl;
        for (auto i : res)
        {
            cout << i << endl;
        }
        cout << "end\n";
    }
    // {
    //     cout << "--------------" << endl;
    // }
}

void end()
{
    return;
}