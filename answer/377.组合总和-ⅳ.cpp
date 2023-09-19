/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 定义dp数组和初始化
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        // 外层循环遍历重量
        for (int j = 0; j <= target; ++j) {
            // 内层循环遍历物品
            for (int i = 0; i < nums.size(); ++i)
                if (j >= nums[i]) dp[j] += dp[j - nums[i]];
        }

        return dp[target];
    }
};
// @lc code=end

