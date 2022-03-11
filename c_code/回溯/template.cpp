#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

void display(const vector<vector<int>> &data)
{
    for (auto outer : data)
    {
        for (auto inner : outer)
        {
            cout << inner << " ";
        }
        cout << endl;
    }
}