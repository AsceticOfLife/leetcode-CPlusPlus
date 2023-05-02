/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;

        int slow, fast;
        slow = fast = 0;
        while (fast < len) {
            if (nums[slow] != nums[fast]) nums[++slow] = nums[fast];
            ++fast;
        }

        return slow + 1;
    }
};
// @lc code=end

