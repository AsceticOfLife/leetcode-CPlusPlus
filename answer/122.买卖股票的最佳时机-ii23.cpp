/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        // 定义dp数组
        vector<vector<int>> dp(prices.size(), {0, 0});
        dp[0][0] = -prices[0];

        // 遍历
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = std::max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        
        return dp[prices.size() - 1][1];
    }
};
// @lc code=end

