/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;

        // i表示当前下标
        // 当前下标在覆盖范围内就可以到达
        for (int i = 0; i <= cover; ++i) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true;
        }

        return false;  
    }
};
// @lc code=end

