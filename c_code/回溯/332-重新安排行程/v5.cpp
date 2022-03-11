#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

// 效率相对还是比较低
// 1、用了set对城市去重
// 2、map的底层是红黑树（平衡二叉搜索树），对key的查找效率为logn
// 改进：
// 1、用unordered_map（底层是哈希表），查找效率为1
//    
// 2、不用set对城市去重，就是遍历unordered_map
