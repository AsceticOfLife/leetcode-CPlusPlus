/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // 初始化第一行
        // 如果存在障碍物，障碍物之前都为1，后面都是0
        // 不存在障碍物那么都是1
        int col;
        for (col = 0; col < n; ++col) {
            // 如果是障碍物就退出循环
            if (obstacleGrid[0][col] == 1) break;
            dp[0][col] = 1;
        }
        // 判断是否由于障碍物而退出循环
        while (col < n) {
            // 后面的元素都设置为0
            dp[0][col++] = 0;
        }

        // 初始化第一列
        int row;
        for (row = 0; row < m; ++row) {
            if (obstacleGrid[row][0] == 1) break;
            dp[row][0] = 1;
        }
        while (row < m) dp[row++][0] = 0;

        // 递推更新dp数组
        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                // 如果这个位置是一个障碍物则设置为0
                if (obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                } else {
                    // 在上面已经将障碍物的dp也设置为0
                    // 所以即使前两个dp都是障碍物也能计算正确
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

