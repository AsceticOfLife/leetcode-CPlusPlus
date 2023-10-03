/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int result = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);
            result = max(result, prices[i] - low);
        }

        return result;
    }
};
// @lc code=end

