/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int in, out;
        in = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] <= prices[i] && i != prices.size() - 1) {
                continue;
            } else if (prices[i - 1] <= prices[i] && i == prices.size() - 1) {
                profit += prices[i] - in;
                break;
            } else {
                out = prices[i - 1];
                profit += out - in;

                in = prices[i];
            }
        }

        return profit;
    }
};
// @lc code=end

