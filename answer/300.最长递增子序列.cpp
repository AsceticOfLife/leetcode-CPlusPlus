/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 边界检查
        if (nums.size() == 0) return 0;
        
        // 定义dp数组和初始化
        vector<int> dp(nums.size(), 1);
        int result = 0;
        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            // 遍历原问题（以nums[i]为最后一个元素的子序列）的子问题
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (result < dp[i]) result = dp[i];
        }
    
        return result;
    }
};
// @lc code=end

