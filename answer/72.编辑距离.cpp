/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 边界检查
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();

        // 定义dp数组
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
        // 初始化dp[0][0]
        if (word1[0] == word2[0]) dp[0][0] = 0;
        else dp[0][0] = 1;

        // 初始化第一列
        for (int i = 1; i < word1.size(); i++) {
            if (word1[i] == word2[0]) dp[i][0] = i;
            else dp[i][0] = dp[i - 1][0] + 1;
        }

        // 初始化第一行
        for (int j = 1; j < word2.size(); j++) {
            if (word1[0] == word2[j]) dp[0][j] = j;
            else dp[0][j] = dp[0][j - 1] + 1;
        }

        for (int i = 1; i < word1.size(); i++) {
            for (int j = 1; j < word2.size(); j++) {
                if (word1[i] == word2[j]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])  + 1;
            }
        }

        return dp[word1.size() - 1][word2.size() - 1];
    }
};
// @lc code=end

