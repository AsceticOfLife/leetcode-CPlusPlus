/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.size() == 0) return -1; // 如果目标串是空，那么应该是未定义操作
        else if (s.size() == 0) return 0;

        // 定义dp数组
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));
        // 初始化第一列
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[0]) dp[i][0] = ++last;
            else dp[i][0] = last;
        }
        // // 初始化第一行
        // for (int j = 0; j < t.size(); j++) {
        //     if (s[0] == t[j]) dp[0][j] = 1;
        // }

        for (int i = 1; i < s.size(); i++) {
            for (int j = 1; j < t.size(); j++) {
                if (s[i] == t[j]) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % static_cast<int>(1e9 + 7);
                else dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[s.size() - 1][t.size() - 1];
    }
};
// @lc code=end

