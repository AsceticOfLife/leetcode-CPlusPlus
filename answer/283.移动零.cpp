/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return;

        int i = 0, j = 0;
        while (j < len) {
            if (nums[j] != 0) nums[i++] = nums[j];

            j++;
        }
        for (; i < len; i++) nums[i] = 0;

    }
};
// @lc code=end

