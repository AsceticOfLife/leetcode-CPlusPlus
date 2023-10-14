/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 定义dp数组
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        // 初始化i与j相等的情况
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;

        // 从下向上遍历
        for (int i = s.size() - 1; i >= 0; i--) {
            // 从左向右遍历
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][s.size() - 1];
    }
};
// @lc code=end

