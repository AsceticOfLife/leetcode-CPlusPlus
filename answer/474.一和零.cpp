/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 遍历物品
        for (string str : strs) {
            int one = 0, zero = 0;
            // 统计0和1的个数
            for (char c : str) {
                if (c == '0') zero++;
                else one++;
            }

            // 遍历两个重量维度
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) 
                dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

