#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 对s进行连续划分
// 要求：子区间的字母组成不能有交集
// 子区间的数目最多
// 返回子区间的长度

// 从start开始，反向搜索，找到s[start]最后出现的位置pos，记录在map中
// 并与end比较，如果pos大，更新end（遍历范围）
// 继续正向遍历，当遍历到最终位置时，将end-start+1放入结果，作为子区间的长度

// 这个思路和55差不多，都对遍历的区间进行了动态更新
class Solution
{
private:
    map<char, int> my_map;
    // 在s中找到c的最后出现位置
    int lastPosition(const string &s, char c)
    {
        // map中有对应记录
        auto pos_it = my_map.find(c);
        if (pos_it != my_map.end())
        {
            return pos_it->second;
        }
        // 从右往左查找
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == c)
            {
                my_map[s[i]] = i;
                return i;
            }
        }
    }

public:
    vector<int> partitionLabels(string s)
    {
        vector<int> res;
        int start = 0;   // 开始遍历位置
        int end = start; //最终遍历位置
        // 这里取等于，是要考虑最后一个元素
        while (end <= s.size() - 1)
        {
            // 这里不取等于，是因为当end到达最后面时，没必要再检查了
            for (int i = start; i <= end && end < s.size() - 1; i++)
            {
                // 找到最后出现位置
                int last_pos = lastPosition(s, s[i]);
                // 动态更新最终遍历位置
                end = last_pos > end ? last_pos : end;
                // cout << "char:" << s[i] << " last_pos:" << end << endl;
            }
            res.push_back(end - start + 1);
            // 更新start和end
            start = end + 1;
            end = start;
        }
        return res;
    }
};

int main()
{
    string str = "ababcbacadefegdehijhklij";
    Solution s;
    vector<int> res = s.partitionLabels(str);
    for (auto data : res)
    {
        cout << data << endl;
    }
}