/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 定义dp数组
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;

        // 外层循环遍历重量
        for (int j = 0; j <= amount; j++) {
            // 内层循环遍历物品
            for (int i = 0; i < coins.size(); i++) {
                if (j >= coins[i] && dp[j - coins[i]] != numeric_limits<int>::max())
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }

        }

        if (dp[amount] == numeric_limits<int>::max()) return -1;
        return dp[amount];
    }
};
// @lc code=end

