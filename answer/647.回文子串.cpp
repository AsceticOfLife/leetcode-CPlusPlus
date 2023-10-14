/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    int countSubstrings(string s) {
        // 初始化dp数组
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        // 从下到上遍历
        for (int i = s.size() - 1; i >= 0; i--) {
            // 从左到右遍历
            for (int j = i; j < s.size(); j++) {
                if (s[i] != s[j]) continue;

                if (j - i <= 1) {
                    dp[i][j] = true;
                    result++;
                } else if (dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    result++;
                }
            }
        }

        return result;
    }
};
// @lc code=end

