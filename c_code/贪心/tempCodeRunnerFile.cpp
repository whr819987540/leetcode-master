class Solution
// {
// public:
//     int findMinArrowShots(vector<vector<int>> &points)
//     {
//         sort(points.begin(), points.end());
//         for (auto outer : points)
//         {
//             for (auto inner : outer)
//             {
//                 cout << inner << " ";
//             }
//             cout << endl;
//         }
//         int num = 0;
//         int pos;
//         for (int i = 0; i < points.size(); i++)
//         {
//             if (i + 1 < points.size() && points[i + 1][0] >= points[i][0] && points[i + 1][0] <= points[i][1])
//             {
//                 // 右边界的最小值为发射位置
//                 pos = min(points[i][1], points[i + 1][1]);
//                 // 检查还可能被射中的气球
//                 i += 2;
//                 while (i < points.size() && pos >= points[i][0] && pos <= points[i][1])
//                 {
//                     i++;
//                 }
//                 // 此时i指向射不了的气球，应该回退
//                 i--;
//             }
//             num++;
//         }
//         return num;
//     }
// };