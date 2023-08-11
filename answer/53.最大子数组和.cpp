/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            if (count > result) result = count;

            if (count < 0) count = 0;
        }

        return result;
    }
};
// @lc code=end

