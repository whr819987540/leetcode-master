#include <iostream>
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
}