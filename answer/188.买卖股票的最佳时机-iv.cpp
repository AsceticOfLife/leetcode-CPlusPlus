/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        // 定义dp数组和下标定义
        // 奇数下标表示处于买入状态，偶数下标表示处于卖出状态
        vector<vector<int>> dp(prices.size(), vector<int>(k * 2 + 1, 0));
        // 对于奇数（表示买入）进行初始化
        for (int j = 0; j < k; ++j) dp[0][2 * j + 1] = -prices[0];
        
        // 遍历价格
        for (int i = 1; i < prices.size(); ++i) {
            // 遍历更新第i天的dp数组
            for (int j = 0; j < k; ++j) {
                // 更新买入状态
                dp[i][j * 2 + 1] = max(dp[i - 1][j * 2 + 1], dp[i][j * 2] - prices[i]);

                // 更新卖出状态
                dp[i][j * 2 + 2] = max(dp[i - 1][j * 2 + 2], dp[i][j * 2 + 1] + prices[i]);
            }
        }

        return dp[prices.size() - 1][dp[0].size() - 1];
    }
};
// @lc code=end

