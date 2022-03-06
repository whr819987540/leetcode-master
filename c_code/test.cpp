#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int res;
    res = int(13 / 5);
    cout << res << endl;
    string s = "11.0";
    res = stoi(s);
    cout << res << endl;

    vector<int> r;
    r.push_back(1);
    r.push_back(2);
    r.pop_back();
    cout << r[0] << endl;
}