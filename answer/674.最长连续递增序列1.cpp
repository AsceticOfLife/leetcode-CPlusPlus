/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    int findLengthOfLCIS(vector<int>& nums) {
        // 定义dp数组和初始化
        vector<int> dp(nums.size(), 1);

        int result = 1; // 最大长度
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;

                // 记录最大长度
                dp[i] > result ? result = dp[i] : result;
            }
                
        }

        return result;
    }
};
// @lc code=end

