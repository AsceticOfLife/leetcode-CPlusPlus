/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        else if (t.size() == 0) return false;

        // 定义dp数组
        vector<vector<int>> dp(t.size(), vector<int>(s.size(), 0));
        // 初始化第一列
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[0]) {
                // 找到一个相等的
                while (i < t.size()) dp[i++][0] = 1;
                break;
            }
        }
        // 初始化第一行
        for (int j = 0; j < s.size(); j++) {
            if (t[0] == s[j]) {
                while (j < s.size()) dp[0][j++] = 1;
                break;
            }
        }
        int i, j;
        for (i = 1; i < t.size(); i++) {
            for (j = 1; j < s.size(); j++) {
                if (t[i] == s[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

            if (dp[i][s.size() - 1] == s.size()) return true;
        }

        // if (dp[t.size() - 1][s.size() - 1] == s.size()) return true;
        return false;
    }
};
// @lc code=end

