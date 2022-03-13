#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1、数组含义：dp[i][j]表示到达[i][j]的方法数，0表示不可到达，也就是有障碍
// 2、递推公式：
// if(obstacle[i][j]==1) dp[i][j]=0
// else dp[i][j]=dp[i-1][j]+dp[i][j-1] 如果有障碍，dp被设为0，不影响结果
// 3、初始化：第一行被设置为1，如果遇到阻碍，停止初始化；第一列也是如此
// 4、遍历顺序：先横向，再纵向
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
        {
            return 0;
        }

        int row = obstacleGrid.size(), column = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        // 初始化考虑阻碍
        for (int j = 0; j < column && obstacleGrid[0][j] != 1; j++)
        {
            dp[0][j] = 1;
        }
        for (int i = 0; i < row && obstacleGrid[i][0] != 1; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < column; j++)
            {
                // 遍历考虑阻碍
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0; // 实际上就是保持初始值
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][column - 1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> data = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int res = s.uniquePathsWithObstacles(data);
    cout << res << endl;
}