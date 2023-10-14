/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    // 时间复杂度降到O(1)
    int maxSubArray(vector<int>& nums) {
        // 边界检查
        if (nums.size() == 0) return 0;
        
        // 定义dp数组
        int last = nums[0];
        int result = last;

        for (int i = 1; i < nums.size(); i++) {
            int tmp = max(last + nums[i], nums[i]);

            result < tmp ? result = tmp : result;

            last = tmp;
        }

        return result;
    }
};
// @lc code=end

