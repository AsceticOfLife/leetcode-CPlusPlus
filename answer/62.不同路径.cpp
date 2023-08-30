/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // 使用动态规划
    int uniquePaths(int m, int n) {
        // 初始化dp数组
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // 递推更新dp数组
        // 从第二行开始更新数组
        for (int row = 1; row < m; ++row) {
            // 每一行从第二列开始更新数组
            for (int col = 1; col < n; ++col) {
                // 循环保证row的范围是[1, m)
                // col的范围是[1, n)
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

