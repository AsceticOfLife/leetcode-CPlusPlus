/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>{-prices[0], 0});

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(-prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return dp[prices.size() - 1][1];
    }
};
// @lc code=end

