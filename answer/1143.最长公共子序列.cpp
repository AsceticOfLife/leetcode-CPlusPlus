/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 边界检查
        if (text1.size() == 0 || text2.size() == 0) return 0;
        
        // 定义dp数组
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        // 初始化第一列
        for (int i = 0; i < text1.size(); i++) {
            if (text1[i] == text2[0]) {
                // 后面都为1
                while (i < text1.size()) {
                    dp[i++][0] = 1;
                }

                // 后面都设置为1之后退出
                break;
            }
                
        }
        // 初始化第一行
        for (int j = 0; j < text2.size(); j++) {
            if (text1[0] == text2[j]) {
                while (j < text2.size()) {
                    dp[0][j++] = 1;
                }

                break;
            }
        }

        // 分别从下标1开始遍历
        for (int i = 1; i < text1.size(); i++) {
            for (int j = 1; j < text2.size(); j++) {
                if (text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[text1.size() - 1][text2.size() - 1];
    }
};
// @lc code=end

