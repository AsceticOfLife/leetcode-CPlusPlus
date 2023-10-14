/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    int maxSubArray(vector<int>& nums) {
        // 边界检查
        if (nums.size() == 0) return 0;
        
        // 定义dp数组
        vector<int> dp(nums.size() , 0);
        dp[0] = nums[0];

        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);

            result < dp[i] ? result = dp[i] : result;
        }

        return result;
    }
};
// @lc code=end

