/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        // 求总和
        for (int x : nums) sum += x;

        // 求背包重量
        if ((target + sum) % 2 == 1) return 0;
        if (abs(target) > sum) return 0;
        int p = (target + sum) / 2; // 背包重量

        // 定义并初始化dp数组
        vector<int> dp(p + 1, 0);
        dp[0] = 1;

        // 外层循环遍历物品
        for (int i = 0; i < nums.size(); ++i) {
            // 内存循环逆序遍历重量
            for (int j = p; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[p];
    }
};
// @lc code=end

