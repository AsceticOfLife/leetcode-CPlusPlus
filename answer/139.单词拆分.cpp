/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 使用无序集合方便在其中查找单词
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // 定义dp数组和初始化
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        // 外层循环遍历背包
        // i表示背包长度
        for (int i = 1; i <= s.size(); i++) {
            // 内层循环遍历背包后面的物品
            // s[0, j)表示背包中的字符串
            // s[j, i)表示背包后面的字串
            for (int j = 0; j < i; j++) {
                string back = s.substr(j, i - j);
                if (wordSet.find(back) != wordSet.end() &&
                    dp[j] == true) {
                    dp[i] = true;
                } 
            } // end of for j in range[0, i)
            
        } // end of for i in range[1, s.size()]

        return dp[s.size()];
    }
};
// @lc code=end

