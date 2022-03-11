#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 可能收到20/10/5
// 价格为5，所以可能不找零，可能找5，可能找10+5/5+5+5，优先用10+5找零
// total_5记录5的个数，total_10记录10的个数

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int total_5 = 0, total_10 = 0;
        for (auto bill : bills)
        {
            if (bill == 5)
            {
                total_5++;
            }
            else if (bill == 10)
            {
                if (total_5 == 0)
                {
                    return false;
                }
                total_5--, total_10++;
            }
            else if (bill == 20)
            {
                if (total_10 > 0)
                {
                    if (total_5 > 0)
                    {
                        total_5--, total_10--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (total_5 >= 3)
                {
                    total_5 -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> data = {5, 5, 5, 10, 5, 5, 10, 20, 20, 20};
    cout << s.lemonadeChange(data) << endl;
}