/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() <= 1) return 0;
        
        // 定义dp数组和下标
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];

        // 遍历价格
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }

        // 最后一定是不持有状态金钱多
        return dp[prices.size() - 1][1];
    }
};
// @lc code=end

