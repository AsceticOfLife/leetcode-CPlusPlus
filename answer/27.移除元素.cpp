/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) return 0;

        int i = 0, j = 0;
        while (j < len) {
            if (nums[j] != val) nums[i++] = nums[j];

            j++;
        }

        return i;
    }
};
// @lc code=end

