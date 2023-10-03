/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int RobRange(const vector<int> &nums, int start_index, int end_index) {
        int len = end_index - start_index + 1;
        if (len == 0) return 0;
        if (len == 1) return nums[end_index];

        // 确定dp数组
        // dp[i] 表示前家（包括下标为i）的最大值
        vector<int> dp(len, 0);
        dp[0] = nums[start_index];
        dp[1] = max(nums[start_index], nums[start_index + 1]);

        // 遍历所有物品
        for (int i = 2; i < len; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + start_index]);
        }

        return dp[len - 1];
    }

    int rob(vector<int>& nums) {
        // 后续算法至少需要两个元素
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int result1 = RobRange(nums, 1, nums.size() - 1);
        int result2 = RobRange(nums, 0, nums.size() - 2);

        return max(result1, result2);
    }
};
// @lc code=end

