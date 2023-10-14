/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    // 动态规划2：使用最长公共自序列来理解
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        
        // 定义dp数组
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
        // 初始化第一列
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] == word2[0]) {
                while (i < word1.size()) dp[i++][0] = 1;
                break;
            }
        }

        // 初始化第一行
        for (int j = 0; j < word2.size(); j++) {
            if (word1[0] == word2[j]) {
                while (j < word2.size()) dp[0][j++] = 1;
                break;
            }
        }

        for (int i = 1; i < word1.size(); i++) {
            for (int j = 1; j < word2.size(); j++) {
                if (word1[i] == word2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int len = dp[word1.size() - 1][word2.size() - 1];
        return word1.size() + word2.size() - len * 2;
    }
};
// @lc code=end

