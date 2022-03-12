#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> func(vector<int> &data)
    {
        vector<int> res;
        if (data.empty())
        {
            return res;
        }
        res.push_back(data[0]);
        int i = 0;
        while (i < data.size() - 1)
        {
            if (data[i] == data[i + 1])
            {
                i++;
            }
            else if (data[i] < data[i + 1])
            {
                while (i < data.size() - 1 && data[i] <= data[i + 1])
                {
                    i++;
                }
                res.push_back(data[i]);
            }
            else if (data[i] > data[i + 1])
            {
                while (i < data.size() - 1 && data[i] >= data[i + 1])
                {
                    i++;
                }
                res.push_back(data[i]);
            }
        }
    }
};

int main()
{
    vector<int> data = {1, 1, 2, 3, 2};
    Solution s;
    vector<int> res = s.func(data);
    for (auto i : res)
    {
        cout << i << endl;
    }
}